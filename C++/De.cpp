#include "De.h"

using namespace std;

    //constructeur

    De::De(){}

    De::De(mt19937 &rgen)
    {

        //premier random
        //resultat=(rand()%6)+1;

        //deuxieme random

        resultat=getRandInt(rgen,1,6);


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

    //methode random


    double De::getRand(mt19937 &rand_gen) {
        //renvoie un double dans [0, 1[
        return (double) rand_gen() / ((double) rand_gen.max() + 1);
    }

    int De::getRandInt(mt19937 &rand_gen, int a, int b) {
        // renvoie un entier dans [a, b]
        // suppose que b >= a
        int resultat;

        resultat=((getRand(rand_gen) * (b-a+1))) + a;
    return resultat;
    }

