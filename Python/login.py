from requests import session
from urllib import request
import numpy as np
import re
import sys

"""
findall= trouve toute occu d'un patern et les mets dans un tableau
split= prend un string et le coupe en suivant une séparation précisé
sub= retire les carac en parametre
"""


"""payload = {
        'p': '',
        'pAction': 'login',
        'username': 'kraken_eilco',
        'password': 'krakeneilco'
}"""
"""payload = {
        'p': '',
        'pAction': 'login',
        'username': 'Pepita_eilco',
        'password': 'pepita62'
}"""


def connexion(payload):


    with session() as c:
        response = c.post('http://www.boiteajeux.net/gestion.php',data=payload)
        return response.content



def lancerPartie(payload):

    connexion(payload)
    partie = "http://www.boiteajeux.net/jeux/cdb/partie.php?id="
    #idpartie = input("Entrez un id de partie : ")
    idpartie = "530217"
    url = request.urlopen(partie + idpartie)
    return url



def listeJoueur(page):    
    joueurActif = re.findall("<li"+".*?"+"</li>", page)
    for i in range (0,len(joueurActif)):
        idJoueur = re.findall("mini[0-3]",joueurActif[i])
        nomJoueur = re.sub("<.*?>","",joueurActif[i])
        print ("id: " + idJoueur[0] + " nom : " + nomJoueur) 



def extraireDe(donnee):
    if(len(re.findall("img/de.png", donnee[0])) == 1):
        couleur= "blanc"
    if(len(re.findall("img/der.png", donnee[0])) == 1):
        couleur= "rouge"
    if(len(re.findall("img/dev.png", donnee[0])) == 1):
        couleur= "vert"
    de = re.split("src", donnee[0])
    valeur = re.findall("[1-6]", de[1])
    print ("Vous avez un de de couleur " + couleur + " et de valeur " + valeur[0])
    donnee.pop(0)



def extrairePepite(donnee):
    isPepite = re.findall("pepite", donnee[0])
    pepite= "0"
    if len(isPepite) > 0:
        pepite = re.sub("<.*?>","",donnee[0])
        donnee.pop(0)
    print ("Vous avez " + pepite + " pepite")
    #return pepite



def extraireMarchandise(donnee):
    marchandise = re.findall("m[1-6]", donnee[0])
    if len(marchandise) > 0:
        valeur = re.findall("[1-6]", marchandise[0])
        quantite = re.sub("<.*?>","",donnee[0])
        print ("Vous avez une marchandise de valeur " + valeur[0] + " en " + quantite[0] + " quantite")
        donnee.pop(0)
        return marchandise
    else:
        return None



#Va devenir obselète
def extraireMarchandiseVendue(donnee):
    marchandise = re.findall("m[1-6]", donnee[0])
    if len(marchandise) > 0:
        valeur = re.findall("[1-6]", marchandise[0])
        quantite = re.sub("<.*?>","",donnee[0])
        print ("Vous avez une marchandise vendue de valeur " + valeur[0] + " en " + quantite[0] + " quantite")
        donnee.pop(0)
        return marchandise
    else:
        return None



def extraireOuvrier(donnee):
    """
        On retourne la valeur des ouvriers du joueur
    """
    ouvrier = re.sub("<.*?>","",donnee[len(donnee)-1])
    #donnee.pop(0)
    return ouvrier



def extraireTuile(donnee):
    """
        on extrait les balises du code html pour déterminer les types de chaque case
        pour par la suite les rentrer dans un tableau et les envoyer à l'ia
    """
    case = {
        'cs' : 'Navires',
        'cb' : 'Batiments',
        'cm' : 'Mines',
        'ca' : 'Animaux',
        'ck' : 'Connaissance',
        'cc' : 'Chateaux'
    }
    typeTuile = {
        'ts' : 'Navire Normale',
        'tsb' : 'Navire Noire',
        'tb1' : 'Entrepot',
        'tb1b' : 'Entrepot(Noire)',
        'tb2' : 'Atelier de menuiserie',
        'tb2b' : 'Atelier de menuiserie(Noire)',
        'tb3' : 'Eglise',
        'tb4' : 'Marche',
        'tb5' : 'Pension',
        'tb5b' : 'Pension (Noire)',
        'tb7' : 'Hotel de ville',
        'tb7b' : 'Hotel de ville(Noire)',
        'tb8' : 'Tour de guet',
        'tb8b' : 'Tour de guet(Noire)',
        'tm' : 'Mine normale',
        'tac4' : '4 cochon',
        'tam3' : '3 mouton',
        'tap3b' : '3 poule(Noire)',
        'tav3' : '3 vache',
        'tav4' : '4 vache',
        'tk5' : 'Boost navires',
        'tk8' : 'Boost ouvrier',
        'tk9' : 'Boost ajustement batiments',
        'tk10' : 'Boost ajustement navires/animaux',
        'tk14b' : 'Boost vente des De (Noire)',
        'tk19' : 'Boost point victoire eglise',
        'tk20' : 'Boost point victoire banque',
        'tk22' : 'Boost point victoire marche',
        'tk23' : 'Boost point victoire hotel de ville',
        'tk25' : 'Boost point victoire marchandise vendu',
        'tk26' : 'Boost point victoire tuile bonus',
        'tc' : 'Chateau normale',
        'tcb' : 'Chateau noire',
        'd1' : 'Vide (1)',
        'd2' : 'Vide (2)',
        'd3' : 'Vide (3)',
        'd4' : 'Vide (4)',
        'd5' : 'Vide (5)',
        'd6' : 'Vide (6)'
    }
    tuile = re.split("img/",donnee[0])
    couleurTemp = re.split(".png",tuile[1])
    valeurTemp = re.split(".png",tuile[2])
    couleur = couleurTemp[0]
    valeur = valeurTemp[0]
    #print("Case : "+case.get(couleur,"Case inconnue")+"\nValeur : "+typeTuile.get(valeur,"Tuile inconnue")+"\n========================================")
    donnee.pop(0)
    return (case.get(couleur,"Case inconnue"),typeTuile.get(valeur,"Tuile inconnue"))



def extrairePlateau(donnee):
    """
        On retourne la tableau  des tuiles du domaine en remplissant de façon à correspondre la valeur et la couleur 
        et en le faisant en sorte d'avoir une forme héxagonal pour garder la logique de 6 voisins
    """
    tableauPlateauJoueur=[]
    for j in range(7):
        tableauPlateauJoueur.append([['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['','']])
    for i in range(37):-
        couleur,valeur=extraireTuile(donnee)
        coord=extraireCoordonnee(i)
        tableauPlateauJoueur=remplissageTableau(tableauPlateauJoueur, coord, couleur, valeur)
        print("Case : " + couleur +"\nValeur : " + valeur + "\nLigne :" + str(coord//13) + "\nColonne :" + str(coord%13) + "\n========================================")
    return (tableauPlateauJoueur)



def remplissageTableau(tab, coordonnee, c, v):
    """
        On retourne la tableau rempli avec le contenue de chaque case rentré aux bonnes coordonnées
    """
    tab[coordonnee//13][coordonnee%13]=[ c, v]
    return(tab)



def extraireCoordonnee(valeur):
    """
        On retourne la valeur de la case correspondant à l'ordre des cases dans le jeu
        afin d'avoir ses coordonnées dans le tableau que l'on va créer puis retourner
    """
    selectionneur = {
        0 : 39,
        1 : 53,
        2 : 67,
        3 : 81,
        4 : 27,
        5 : 41,
        6 : 55,
        7 : 69,
        8 : 83,
        9 : 15,
        10 : 29,
        11 : 43,
        12 : 57,
        13 : 71,
        14 : 85,
        15 : 3,
        16 : 17,
        17 : 31,
        18 : 45,
        19 : 59,
        20 : 73,
        21 : 87,
        22 : 5,
        23 : 19,
        24 : 33,
        25 : 47,
        26 : 61,
        27 : 75,
        28 : 7,
        29 : 21,
        30 : 35,
        31 : 49,
        32 : 63,
        33 : 9,
        34 : 23,
        35 : 37,
        36 : 51,
    }
    return selectionneur.get(valeur,"Coordonnée invalide")

def extrairePlateauCentrale(index,tableau):
    tableau[index]=[,,,,,,,,,]
    #on regarde le nombre de joueur pour 0 et 3
    #on teste si il y a des marchandises pour remplir 4 à 9
    """
        on doit aussi voir les les bonus et piles de marchandises non utilisé encore
    """
    return (tableau)


def extraireDonneeJoueur(page):
    joueurActif = re.findall("<li class="+".*?"+"</li>", page,re.DOTALL)
    #print (joueurActif[0])
    if(re.search("adebeddes",joueurActif[0])!=None):
        donneeJoueur = re.findall("<div class=\"tab-pane active\""+".*?"+"<div class=\"tab-pane \"", page)
        donneeJoueurSplit = re.findall("<div " + ".*?" + "/div>", donneeJoueur[0])
        donneeJoueurSplit.pop(0)

        extraireDe(donneeJoueurSplit) #On recupère les dés
        extraireDe(donneeJoueurSplit)

        extrairePepite(donneeJoueurSplit) #On recupère les pépites

         #On recupère les marchandises
        listeMarchandise = re.findall("dvGoods",donneeJoueurSplit[0])
        while(len(listeMarchandise)!=1):
            extraireMarchandise(donneeJoueurSplit)
            listeMarchandise = re.findall("dvGoods",donneeJoueurSplit[0])
        listeMarchandise = re.findall("clmar",donneeJoueurSplit[0])
        while(len(listeMarchandise)!=1):
            extraireMarchandiseVendue(donneeJoueurSplit)
            listeMarchandise = re.findall("clMar",donneeJoueurSplit[0])
        donneeJoueurSplit.pop(0)
        reserve = re.findall("url",donneeJoueurSplit[0])
        while(len(reserve)!=1):
            donneeJoueurSplit.pop(0)
            reserve = re.findall("url",donneeJoueurSplit[0])

        tableauPlateauJoueur=[]
        tableauPlateauJoueur=extrairePlateau(donneeJoueurSplit)  #On recupere le tableau des tuiles du domaine

        ouvrier = extraireOuvrier(donneeJoueurSplit) #On recupère les ouvriers
        print ("Vous avez " + ouvrier + " ouvrier")
        """for i in range (0,len(donneeJoueurSplit)):
            print donneeJoueurSplit[i]"""
    else:
        donneeJoueur = re.findall("<div class=\"tab-pane \""+".*?"+"</td>", page)
        donneeJoueurSplit = re.findall("<div " + ".*?" + "/div>", donneeJoueur[0])
        donneeJoueurSplit.pop(0)

        extraireDe(donneeJoueurSplit)
        extraireDe(donneeJoueurSplit) #On recupère les dés

        extrairePepite(donneeJoueurSplit) #On recupère les pépites

        #On recupère les marchandises
        listeMarchandise = re.findall("dvGoods",donneeJoueurSplit[0])
        while(len(listeMarchandise)!=1):
            extraireMarchandise(donneeJoueurSplit)
            listeMarchandise = re.findall("dvGoods",donneeJoueurSplit[0])
        listeMarchandise = re.findall("clmar",donneeJoueurSplit[0])
        while(len(listeMarchandise)!=1):
            extraireMarchandiseVendue(donneeJoueurSplit)
            listeMarchandise = re.findall("clMar",donneeJoueurSplit[0])
        donneeJoueurSplit.pop(0)
        reserve = re.findall("url",donneeJoueurSplit[0])
        while(len(reserve)!=1):
            donneeJoueurSplit.pop(0)
            reserve = re.findall("url",donneeJoueurSplit[0])
        
        tableauPlateauJoueur=[]
        tableauPlateauJoueur=extrairePlateau(donneeJoueurSplit) #On recupere le tableau des tuiles du domaine
        
        ouvrier = extraireOuvrier(donneeJoueurSplit) #On recupère les ouvriers
        print ("Vous avez " + ouvrier + " ouvrier")
        #print donneeJoueurSplit[0]
        """for i in range (len(donneeJoueurSplit)-1,len(donneeJoueurSplit)):
            print donneeJoueurSplit[i]"""

        #On extrait les tuiles et informations du plateau centrale
        listeTuiteCentrale=[[],[],[],[],[],[],[]] #liste contenant les tuiles des dés et la boutique du centre
        for j in range(6) #tuile et marchandise associé au dés 1 à 6
            listeTuiteCentrale=extrairePlateauCentrale(j,listeTuiteCentrale)
        listeTuiteCentrale[6]=[,,,,,,] #boutique centrale



def tout(payload):
    donnee=lancerPartie(payload)
    page=donnee.read().decode('utf-8')
    listeJoueur(page)
    extraireDonneeJoueur(page)
    

payload = {
    'p': '',
    'pAction': 'login',
    'username': 'adebeddes',
    'password': 'poussin36'
}
tout(payload)