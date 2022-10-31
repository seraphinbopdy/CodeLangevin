

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "calcul_du_degre_fonction.h"


int degre_fonction(uchar*f,int m)
{
    int u;
    int res = -1;

    for(u =0;u< (1<<m);u++)
    {
        if(f[u] && (wt(u)> res)) res = wt(u);

        //Anf c'est une fonction a definir dehors et a implementer
    }
    anf(f,1<<m);
    return res;
}