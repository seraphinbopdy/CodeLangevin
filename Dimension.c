

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dimension.h"


//Calcul de la Somme du binomial pour trouver la dimension 
int rmdimen(int k, int m)
{
    int r = 0;
    for(int i=0;i<=k;i++)
    {
        r+=rmdimen(i,m);
    }
    return r;
}