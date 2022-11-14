

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dimension.h"



// Une Autre fonction pour le Calcul du Binomial
int Combinaison_De_N_Dans_K(int n,int k)
{
    if(k==1)
        return n;
    else if(n==k)
        return 1;
    else return (Combinaison_De_N_Dans_K(n-1,k)+Combinaison_De_N_Dans_K(n-1,k-1));
}


//Calcul de la Somme du binomial pour trouver la dimension 
int rmdimen(int k, int m)
{
    int r = 0;
    for(int i=0;i<=k;i++)
    {
        r+=Combinaison_De_N_Dans_K(i,m);
    }
    return r;
}


int main(int argc, char *argv[])
{
    int k ,n;
    k = atoi(argv[1]);
    n = atoi(argv[2]);

    printf("%d\n  ",Combinaison_De_N_Dans_K(n,k));

    printf("%d\n ",rmdimen(4,8));


    return 0;
}
