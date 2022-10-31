
#include "init_code.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



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