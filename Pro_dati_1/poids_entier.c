

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "poids_entier.h"


//Calcule du poids d'un entier
int wt(int z)
{
    int r =0;
    while(z)
    {
        r = r+(z&1);
        z = z>>1;
    }
    return r;
}

