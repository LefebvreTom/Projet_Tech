#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

#include "PlateauJoueur.h"
#include "PlateauCentral.h"
#include "Partie.h"
#include "Simulateur.h"

#include <iostream>
#include<stdio.h>
#include<string>
#include <random>

#include <cstdlib>
#include <stdlib.h>

class IA
{
public :
        IA();

        ~IA();

        void Monte_Carlo();

protected :
    Partie partie;
    Simulateur simulateur;
};
#endif // IA_H_INCLUDED
