

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RM.h"






code RM(int k, int m)
{
    code res;
    int u,i,x;

    res = Init_Code((rmdimen(k,m),1<<m));
    i=0;
    for(u=0;u<res.m;u++)
    {
        if(wt(u)<=k)//Calcule du poids qui nous returne un entier
        {
            for(x=0;x<res.m;x++)
                res.mat[i][x] = ((x&u)==u);
        i++;
        }
    }
    return res;
}
