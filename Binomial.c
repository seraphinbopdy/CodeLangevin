

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Binomial.h"





//Calcul d'un Binomial unique
int binomial(int k, int n)
{
    int r = 1;
    int i;
    for(i=0;i<k;i++)
        r = r*(n-i);
    for(i = 1;i<=k;i++)
        r = (r/i);
return r;
}


// Une Autre fonction pour le Calcul du Binomial

int Combinaison_De_N_Dans_K(int n,int k)
{
    if(k==1)
        return n;
    else if(n==k)
        return 1;
    else return (Combinaison_De_N_Dans_K(n-1,k)+Combinaison_De_N_Dans_K(n-1,k-1));
}
