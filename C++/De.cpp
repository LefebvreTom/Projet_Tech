#include "De.h"

    //constructeur
    De::De()
    {

        //premier random
        resultat=(rand()%6)+1;

    }

    //accesseur
        int De::getResultat()
    {
        return resultat;
    }
