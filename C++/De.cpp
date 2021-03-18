#include "De.h"

    //constructeur
    De::De()
    {

        //premier random
        resultat=(rand()%6)+1;

    }

    De::De(int face)
    {

        //premier random
        resultat=face;

    }

    //accesseur
        int De::getResultat()
    {
        return resultat;
    }
