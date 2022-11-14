
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "code.h"


//Calcul du poids d'un vecteur
int weight(int*s,int n)
{
    int res = 0;
    for(int j=0;j<n;j++)
    {
        res+=s[j];
    }
    return  res;
}


// implementation de la fonction add
void add(int*dest,int*src,int l)
{
    for(int i =0;i<l;i++)
    {
        dest[i]= dest[i]^src[i];
    }
}



int decode(code C, int t[], int*cpt,int Limite)
{
    // recherche d'un mot de C tel que :
    // wt(c+t)<w( Limite dans ce ca s c'est notre Cible) // Limite ici c'est le poid et tant que ce poid 
    // n'est pas atteind je ne m'arrete pas  


    //int random = rand();
    int i; //ligne
    int j; // colone
    int p,w,k;
    do{
            for(i = 0;i<C.k;i++)
            {
                //sur chaque ligne je genère une valeur et controle si ca vaut 1 ou 0
                do{
                    p = random()%C.n;
                }while(!C.mat[i][p]);
                for(k=0;k<C.n;k++)
                    if(k!=i && C.mat[k][p]) add(C.mat[k],C.mat[i],C.n);

                if(t[p]) add(t,C.mat[i],C.n); 
            }
            w = weight(t,C.n);
    }while ((*cpt)-->0 && w>=Limite);
    // je controle puis je desincremente.
    // la comparaison avec limite c'est pour dire le poid ne doit pas depasser la taille limite donné en entrée.
    return w;
}
