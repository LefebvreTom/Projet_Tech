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
payload = {
    'p': '',
    'pAction': 'login',
    'username': 'adebeddes',
    'password': 'poussin36'
}



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
    'tam2' : '2 mouton',
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
    'tk25b' : 'Boost point victoire marchandise vendu(Noire)',
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



def connexion(payload):


    with session() as c:
        response = c.post('http://www.boiteajeux.net/gestion.php',data=payload)
        return response.content



def lancerPartie(payload):

    connexion(payload)
    partie = "http://www.boiteajeux.net/jeux/cdb/partie.php?id="
    score = "http://www.boiteajeux.net/jeux/cdb/decompte.php?id="
    #idpartie = input("Entrez un id de partie : ")
    #idpartie = "530217"
    idpartie = "539962"
    url = request.urlopen(partie + idpartie)
    urlS = request.urlopen(score + idpartie)
    return url,urlS



def listeJoueur(page):    
    joueurs = {}
    joueurActif = re.findall("<li"+".*?"+"</li>", page)
    for i in range (0,len(joueurActif)):
        idJoueur = re.findall("mini[0-3]",joueurActif[i])
        nomJoueur = re.sub("<.*?>","",joueurActif[i])
        joueurs[nomJoueur] = idJoueur[0]
    return joueurs 



def extraireDe(donnee,fichier):
    if(len(re.findall("img/de.png", donnee[0])) == 1):
        couleur= "blanc"
    if(len(re.findall("img/der.png", donnee[0])) == 1):
        couleur= "rouge"
    if(len(re.findall("img/dev.png", donnee[0])) == 1):
        couleur= "vert"
    de = re.split("src", donnee[0])
    valeur = re.findall("[1-6]", de[1])
    #print ("Vous avez un de de couleur " + couleur + " et de valeur " + valeur[0])
    fichier.write(couleur+";"+valeur[0]+"\n")
    donnee.pop(0)



def extrairePepite(donnee,fichier):
    isPepite = re.findall("pepite", donnee[0])
    pepite= "0"
    if len(isPepite) > 0:
        pepite = re.sub("<.*?>","",donnee[0])
        donnee.pop(0)
    fichier.write("pepite:\n"+pepite+"\n")
    #print ("Vous avez " + pepite + " pepite")



def extraireMarchandise(donnee,fichier):
    marchandise = re.findall("m[1-6]", donnee[0])
    if len(marchandise) > 0:
        valeur = re.findall("[1-6]", marchandise[0])
        quantite = re.sub("<.*?>","",donnee[0])
        fichier.write(valeur[0]+";"+quantite[0]+"\n")
        #print ("Vous avez une marchandise de valeur " + valeur[0] + " en " + quantite[0] + " quantite")
        donnee.pop(0)
        return marchandise
    else:
        return None



#Va devenir obselète
"""def extraireMarchandiseVendue(donnee):
    marchandise = re.findall("m[1-6]", donnee[0])
    if len(marchandise) > 0:
        valeur = re.findall("[1-6]", marchandise[0])
        quantite = re.sub("<.*?>","",donnee[0])
        print ("Vous avez une marchandise vendue de valeur " + valeur[0] + " en " + quantite[0] + " quantite")
        donnee.pop(0)
        return marchandise
    else:
        return None"""



def extraireOuvrier(donnee):
    """
        On retourne la valeur des ouvriers du joueur
    """
    ouvrier = re.sub("<.*?>","",donnee[0])
    donnee.pop(0)
    return ouvrier



def extraireTuile(donnee):
    """
        on extrait les balises du code html pour déterminer les types de chaque case
        pour par la suite les rentrer dans un tableau et les envoyer à l'ia
    """
    tuile = re.split("img/",donnee[0])
    couleurTemp = re.split(".png",tuile[1])
    valeurTemp = re.split(".png",tuile[2])
    couleur = couleurTemp[0]
    valeur = valeurTemp[0]
    #print("Case : "+case.get(couleur,"Case inconnue")+"\nValeur : "+typeTuile.get(valeur,"Tuile inconnue")+"\n========================================")
    donnee.pop(0)
    return (couleur,valeur)



def extraireReserve(donnee,fichier):
    donnee.pop(0)
    tuile = re.split("img/",donnee[0])
    valeur = re.split(".png",tuile[1])
    fichier.write(valeur[0]+"\n")
    #print(typeTuile.get(valeur[0],"Tuile inconnue"))
    donnee.pop(0)



def extrairePlateau(donnee,fichier):
    """
        On retourne la tableau  des tuiles du domaine en remplissant de façon à correspondre la valeur et la couleur 
        et en le faisant en sorte d'avoir une forme héxagonal pour garder la logique de 6 voisins
    """
    """for j in range(7):
        tableauPlateauJoueur.append([['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['',''],['','']])"""
    fichier.write("plateau:\n")
    for i in range(37):
        couleur,valeur=extraireTuile(donnee)
        fichier.write(couleur+";"+valeur+"\n")



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


def extraireDonneeJoueur(listeJoueurs,joueur,page,fichier):
    donneeJoueur = re.findall(listeJoueurs[joueur]+"\">"+ ".*?" + "<div class=\"tab-pane",page)
    if(len(donneeJoueur)==0):
        donneeJoueur = re.findall(listeJoueurs[joueur]+"\">"+ ".*?" + "</td>",page)
    donneeJoueurSplit = re.findall("<div " + ".*?" + "/div>", donneeJoueur[0])
    donneeJoueurSplit.pop(0)

    fichier.write("de:\n")
    extraireDe(donneeJoueurSplit,fichier) #On recupère les dés
    extraireDe(donneeJoueurSplit,fichier)

    extrairePepite(donneeJoueurSplit,fichier) #On recupère les pépites
    
    #On recupère les marchandises
    listeMarchandise = re.findall("dvGoods",donneeJoueurSplit[0])
    fichier.write("marchandise:\n")
    while(len(listeMarchandise)!=1):
        extraireMarchandise(donneeJoueurSplit,fichier)
        listeMarchandise = re.findall("dvGoods",donneeJoueurSplit[0])
    listeMarchandise = re.findall("clmar",donneeJoueurSplit[0])
    fichier.write("marchandise_vendu:\n")
    while(len(listeMarchandise)>1):
        extraireMarchandise(donneeJoueurSplit,fichier)
        listeMarchandise = re.findall("clMar",donneeJoueurSplit[0])
    donneeJoueurSplit.pop(0)
    reserve = re.findall("url",donneeJoueurSplit[0])
    #print("Votre reserve:")
    fichier.write("reserve:\n")
    while(len(reserve)!=1):
        extraireReserve(donneeJoueurSplit,fichier)
        reserve = re.findall("url",donneeJoueurSplit[0])
    extrairePlateau(donneeJoueurSplit,fichier) #On recupere le tableau des tuiles du domaine
    ouvrier = extraireOuvrier(donneeJoueurSplit) #On recupère les ouvriers
    fichier.write("ouvrier:\n"+str(ouvrier))
    #print ("Vous avez " + ouvrier + " ouvrier")



def topLeft(donneeJoueurSplit):
    if(re.search("img/p",donneeJoueurSplit[0])!=None): #si on a un pion, on s'adapte au format de balise, spécifique
        coordonee = re.split(";",donneeJoueurSplit[0])  
        top = re.sub("rel=.*? style","",coordonee[2])
        top = re.findall(r"\d+",top)
        top = int(top[0])
        left = re.sub("rel=.*? style","",coordonee[1])
        left = re.findall(r"\d+",left)
        left = int(left[0])
        return (top,left)
    elif(re.search("img/p",donneeJoueurSplit[0])==None): #si non, on utilise le cas des balises générales
        coordonee = re.split(";",donneeJoueurSplit[0])  
        top = re.sub("rel=.*? style","",coordonee[0])
        top = re.findall(r"\d+",top)
        top = int(top[0])
        left = re.sub("rel=.*? style","",coordonee[1])
        left = re.findall(r"\d+",left)
        left = int(left[0])
        return (top,left)
    else:
        print("Inconnue")
        return(None)
    

def extraireMarche(page,joueurs,fichier):
    #On extrait les tuiles et informations du plateau centrale
    tuile1=[]
    tuile2=[]
    tuile3=[]
    tuile4=[]
    tuile5=[]
    tuile6=[]
    tuileNoire=[]
    marchandise1=[]
    marchandise2=[]
    marchandise3=[]
    marchandise4=[]
    marchandise5=[]
    marchandise6=[]

    #On récupére la phase et le tour de jeu
    test = re.findall("PHASE"+ ".*?" + "/div>", page)
    test1 = re.split("/",test[0])
    phase = test1[0]
    indexPhase = len(phase)-1
    phase = phase[indexPhase]
    tour = test1[1]
    indexTour = len(tour)-1
    tour = tour[indexTour]
    fichier.write("Phase/tours:"+"\n"+phase+";"+tour+"\n")

    donneeJoueur = re.split("<td style=\"vertical-align:top;padding-left:8px\">",page)
    donneeJoueurSplit = re.findall("<div " + ".*?" + "/div>", donneeJoueur[1],re.DOTALL)
    donneeJoueurSplit.pop(len(donneeJoueurSplit)-1)
    donneeJoueurSplit[0] = re.sub("<div style=\"position:relative;width:580px;height:650px;background-image:url\(img/plateau.jpg\);\">","",donneeJoueurSplit[0])
    tuile = re.split("img/",donneeJoueurSplit[0])
    couleurTemp = re.split(".png",tuile[1])
    while re.search("t",couleurTemp[0])!=None:
        coordoneeTuile = topLeft(donneeJoueurSplit)
        if(coordoneeTuile[1]<150):
            if(coordoneeTuile[0]<300):
                tuile6.append(couleurTemp[0])
            elif(coordoneeTuile[0]>300):
                tuile5.append(couleurTemp[0])
            else:
                print("Inconnue")
        elif(coordoneeTuile[1]>350):
            if(coordoneeTuile[0]<300):
                tuile2.append(couleurTemp[0])
            elif(coordoneeTuile[0]>300):
                tuile3.append(couleurTemp[0])
            else:
                print("Inconnue")
        elif(coordoneeTuile[1]>150 and coordoneeTuile[1]<350):
            if(coordoneeTuile[0]<250):
                tuile1.append(couleurTemp[0])
            elif(coordoneeTuile[0]>350):
                tuile4.append(couleurTemp[0])
            elif(coordoneeTuile[0]<350 and coordoneeTuile[0]>250):
                tuileNoire.append(couleurTemp[0])
            else:
                print("Inconnue")
        else:
            print("Inconnue")
        donneeJoueurSplit.pop(0)
        tuile = re.split("img/",donneeJoueurSplit[0])
        couleurTemp = re.split(".png",tuile[1])
    coordoneeMarchandise = topLeft(donneeJoueurSplit)
    while coordoneeMarchandise[0]!=22:
        marchandise = re.split("img/",donneeJoueurSplit[0])
        couleurTemp = re.split(".png",marchandise[1])
        if(coordoneeMarchandise[1]<150):
            if(coordoneeMarchandise[0]<300):
                marchandise6.append(couleurTemp[0])
            elif(coordoneeMarchandise[0]>300):
                marchandise5.append(couleurTemp[0])
            else:
                print("Inconnue")
        elif(coordoneeMarchandise[1]>350):
            if(coordoneeMarchandise[0]<300):
                marchandise2.append(couleurTemp[0])
            elif(coordoneeMarchandise[0]>300):
                marchandise3.append(couleurTemp[0])
            else:
                print("Inconnue")
        elif(coordoneeMarchandise[1]>150 and coordoneeMarchandise[1]<350):
            if(coordoneeMarchandise[0]<250):
                marchandise1.append(couleurTemp[0])
            elif(coordoneeMarchandise[0]>350):
                marchandise4.append(couleurTemp[0])
            else:
                print("Inconnue")
        else:
            print("Inconnue")
        donneeJoueurSplit.pop(0)
        coordoneeMarchandise = topLeft(donneeJoueurSplit)
    
    #on prépare le renvoie des données sous une forme interessante pour leur utilisation
    listeTuileCentrale=[[],[],[],[],[],[],[]] #liste contenant les tuiles des dés et la boutique du centre
    #tuile et marchandise du dés de 1 à 6
    listeTuileCentrale[0] = tuile1 + marchandise1
    listeTuileCentrale[1] = tuile2 + marchandise2
    listeTuileCentrale[2] = tuile3 + marchandise3
    listeTuileCentrale[3] = tuile4 + marchandise4
    listeTuileCentrale[4] = tuile5 + marchandise5
    listeTuileCentrale[5] = tuile6 + marchandise6
    #boutique centrale
    listeTuileCentrale[6]=tuileNoire

    fichier.write("tuile_centrale:\n")
    for i in range(len(listeTuileCentrale)):
        fichier.write(str(listeTuileCentrale[i])+"\n")
    

    #on enregistre les marchandises qui vont etre placé aléatoirement aux débuts des prochains tours
    coordoneeMarchandise = topLeft(donneeJoueurSplit)
    marchandiseTours=[]
    fichier.write("marchandises_tours:\n")
    debut = True
    while coordoneeMarchandise[0]==22:
        marchandise = re.split("img/",donneeJoueurSplit[0])
        couleurTemp = re.split(".png",marchandise[1])
        if(coordoneeMarchandise[1]>250):
            marchandiseTours.append(couleurTemp[0])
            if(debut):
                fichier.write(couleurTemp[0])
                debut = False
            else:
                fichier.write(";"+couleurTemp[0])
            donneeJoueurSplit.pop(0)
        elif(coordoneeMarchandise[1]<250):
            donneeJoueurSplit.pop(0)
        else:
            print("Inconnue")
            donneeJoueurSplit.pop(0)
        coordoneeMarchandise = topLeft(donneeJoueurSplit)

    coordoneePion = topLeft(donneeJoueurSplit)
    pions=[]
    while re.search("img/p",donneeJoueurSplit[0])!=None:
        pion = re.split("img/",donneeJoueurSplit[0])
        ordreTemp = re.split(".png",pion[1])
        
        pions.append([coordoneePion[1],coordoneePion[0],ordreTemp[0]])
        donneeJoueurSplit.pop(0)
    
        coordoneePion = topLeft(donneeJoueurSplit)
    pions.sort(reverse=True)
    fichier.write("\npions:\n")
    for i in range(len(pions)):
        fichier.write(str(pions[i])+"\n") 
    #print(pions)


    bonus=[]
    while len(donneeJoueurSplit)>0 and re.search("img/b",donneeJoueurSplit[0])!=None:
        coordoneeBonus = topLeft(donneeJoueurSplit)
        b = re.split("img/",donneeJoueurSplit[0])
        bonusTemp = re.split(".png",b[1])
        
        bonus.append([bonusTemp[0]])
        donneeJoueurSplit.pop(0)
    fichier.write("bonus:\n")
    for i in range(len(bonus)):
        fichier.write(str(bonus[i])+"\n") 
    #print(bonus)

"""
    On récupére les scores de chaque joueurs
"""
def extraireScore(page,joueurs):
    listeScore = re.findall("<table border=0 cellpadding=2 cellspacing=2 class=clBody><tr><td class=\"clTexteFort\">"+ ".*?" + "/table>", page)
    listeScore = re.split("<tr>",listeScore[0])
    score1 = re.split("<tr>",listeScore[0])
    scorea= re.split("&nbsp;",listeScore[1])
    scoreb= re.split("&nbsp;",listeScore[3])
    scoreJ1=scorea[1]
    scoreJ2=scoreb[1]
    #print(scoreJ1)
    #print(scoreJ2)
    i = 1
    for joueur in joueurs.keys():
        fichier = open("../Donnes/J"+str(i)+".txt", "a")
        #fichier = open("e:/Kraken/projet_tech/Donnes/J"+str(i)+".txt", "a")
        if(i==1):fichier.write("\nscore:\n"+scoreJ1)
        if(i==2):fichier.write("\nscore:\n"+scoreJ2)
        fichier.close()
        i += 1

def tout(payload):
    donnee,donneeS = lancerPartie(payload)
    page = donnee.read().decode('utf-8')
    joueurs = listeJoueur(page)
    i = 1  
    for joueur in joueurs.keys():
        #print("Plateau : "+joueur)
        #fichier = open("e:/Kraken/projet_tech/Donnes/J"+str(i)+".txt", "w")
        fichier = open("../Donnes/J"+str(i)+".txt", "w")
        extraireDonneeJoueur(joueurs,joueur,page,fichier)
        fichier.close()
        i += 1
    extraireScore(page,joueurs)
    #print(page)
    
    #fichier = open("e:/Kraken/projet_tech/Donnes/marche.txt", "w")
    fichier = open("../Donnes/marche.txt", "w")
    extraireMarche(page,joueurs,fichier)
    


tout(payload)