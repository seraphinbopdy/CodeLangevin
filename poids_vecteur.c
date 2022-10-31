

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "poids_vecteur.h"




//Calcul du poids d'un vecteur
int weight(char*s,int n)
{
    int res = 0;
    for(int j=0;j<n;j++)
    {
        res+=s[j];
    }
    return  res;
}

