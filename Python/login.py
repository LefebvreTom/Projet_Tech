from requests import session
import urllib
import re

def connexion():

    payload = {
        'p': '',
        'pAction': 'login',
        'username': 'adebeddes',
        'password': 'poussin36'
    }

    with session() as c:
        response = c.post('http://www.boiteajeux.net/gestion.php',data=payload)
        return response.content

def lancerPartie():

    html = connexion()
    partie = "http://www.boiteajeux.net/jeux/cdb/partie.php?id="
    idpartie = raw_input("Entrez un id de partie : ")
    url=urllib.urlopen(partie + idpartie)
    return url

def extraireDe(data):
    if(len(re.findall("img/de.png", data[0])) == 1):
        couleur= "blanc"
    if(len(re.findall("img/der.png", data[0])) == 1):
        couleur= "rouge"
    if(len(re.findall("img/dev.png", data[0])) == 1):
        couleur= "vert"
    de = re.split("src", data[0])
    valeur = re.findall("[1-6]", de[1])
    print "Vous avez un de de couleur " + couleur + " et de valeur " + valeur[0]
    data.pop(0)

def extrairePepite(data):
    pepite = re.sub("<.*?>","",data[0])
    data.pop(0)
    return pepite

def extraireMarchandise(data):
    marchandise = re.findall("\(.*?\)", data[0])
    if len(marchandise) > 0:
        valeur = re.findall("[1-6]", marchandise[0])
        quantite = re.sub("<.*?>","",data[0])
        print "Vous avez une marchandise de valeur " + valeur[0] + " en " + quantite[0] + " quantite"
        data.pop(0)
        return marchandise
    else:
        return None

def extraireOuvrier(data):
    #print data[len(data)-1]
    ouvrier = re.sub("<.*?>","",data[len(data)-1])
    #print ouvrier
    #data.pop(0)
    return ouvrier

def tout():
    data=lancerPartie()
    page=data.read().decode('utf-8')
    joueurActif = re.findall("<li class=\"active\""+".*?"+"</li>", page,re.DOTALL)
    if(re.search("AstroBreak",joueurActif[0])!=None):
        dataJoueur = re.findall("<div class=\"tab-pane active\""+".*?"+"<div class=\"tab-pane \"", page)
        dataJoueurSplit = re.findall("<div " + ".*?" + "/div>", dataJoueur[0])
        dataJoueurSplit.pop(0)
        d1 = extraireDe(dataJoueurSplit)
        d2 = extraireDe(dataJoueurSplit)
        pepite = extrairePepite(dataJoueurSplit)
        print "Vous avez " + pepite + " pepite"
        m1 = extraireMarchandise(dataJoueurSplit)
        m2 = extraireMarchandise(dataJoueurSplit)
        m3 = extraireMarchandise(dataJoueurSplit)
        dataJoueurSplit.pop(0)
        ouvrier = extraireOuvrier(dataJoueurSplit)
        print "Vous avez " + ouvrier + " ouvrier"
        """for i in range (0,len(dataJoueurSplit)):
            print dataJoueurSplit[i]"""
    else:
        dataJoueur = re.findall("<div class=\"tab-pane \""+".*?"+"</td>", page)
        dataJoueurSplit = re.findall("<div " + ".*?" + "/div>", dataJoueur[0])
        dataJoueurSplit.pop(0)
        d1 = extraireDe(dataJoueurSplit)
        d2 = extraireDe(dataJoueurSplit)
        pepite = extrairePepite(dataJoueurSplit)
        print "Vous avez " + pepite + " pepite"
        m1 = extraireMarchandise(dataJoueurSplit)
        m2 = extraireMarchandise(dataJoueurSplit)
        m3 = extraireMarchandise(dataJoueurSplit)
        dataJoueurSplit.pop(0)
        ouvrier = extraireOuvrier(dataJoueurSplit)
        print "Vous avez " + ouvrier + " ouvrier"
        #print dataJoueurSplit[0]
        """for i in range (len(dataJoueurSplit)-1,len(dataJoueurSplit)):
            print dataJoueurSplit[i]"""

tout()