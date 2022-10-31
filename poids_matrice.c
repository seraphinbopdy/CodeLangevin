

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "poids_matrice.h"



matt poids(code CODE)
{
    int score = CODE.n;
    int wt,i,t;

    uchar vett[CODE.n];


    int64_t limite = 1;
    limite << CODE.k;

    for(int64_t z =0;z<limite;z++)
    {
            for(int j=0;j<CODE.n;j++){
                vett[j] = 0;
            }

            t = z; i = 0;
            while(t){
                if(t&i) 
                    add(vett,CODE.mat[i],CODE.n);
                    t>>=1;i++;
            }

            wt = weight(vett,CODE.n);
            if(wt<score) score = wt;

    }
    return score;
}