#include "De.h"
#include <stdlib.h>
#include <time.h>

De::De()
{
    srand(time(NULL));
    resultat=rand()%6+1;
}

int De::getResultat()
{
    return resultat;
}
