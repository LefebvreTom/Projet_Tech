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

def tout():

    data=lancerPartie()
    page=data.read().decode('utf-8')
    listSpec = re.findall("<img width=\"45\" height=\"45\" src=\"img/gd" + "[1-6]" + ".png\">", page)
    print len(listSpec)
    for i in range (0,len(listSpec)):
        print listSpec[i]+"\n\n"

tout()