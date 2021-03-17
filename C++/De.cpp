#include "De.h"


De::De()
{

    //premier random
    resultat=(rand()%6)+1;

}


int De::getResultat()
{
    return resultat;
}
