#ifndef DE_H
#define DE_H

#include <stdlib.h>
#include <random>
#include <ctime>


class De
{
    //Constructeur
    public :
        De();
        De(std::mt19937 &rand_gen);
        De(int face);
    //Destructeur


    //Méthodes
    int getResultat();
    void genereResultat();
    double getRand(std::mt19937 &rand_gen);
    int getRandInt(std::mt19937 &rand_gen,int a,int b);

    //Attributs
    protected :
        std::mt19937 rgen;
        int resultat;

};

#endif

