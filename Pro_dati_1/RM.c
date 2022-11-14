

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "code.h"



//Fonction pour inialiser la Matrice.
code Init_Code(int k, int n)
{
    code rep;
    rep.n = n;
    rep.k = k;
    rep.mat = calloc(k,sizeof(uchar*)); 


    for(int i =0;i<k;i++)
    {
        rep.mat[i] = calloc(n,sizeof(uchar));
    }

    return rep;
}



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



code RM(int k, int m)
{
    code res;
    int u,i,x;

    res = Init_Code((rmdimen(k,m)),(1<<m));
    i=0;
    for(u=0;u<res.n;u++)
    {
        if(wt(u)<=k)//Calcule du poids qui nous returne un entier
        {
            for(x=0;x<res.n;x++)
                res.mat[i][x] = ((x&u)==u);
            i++;
        }
    }
    return res;
}
