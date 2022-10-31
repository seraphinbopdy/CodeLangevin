

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Distance_Minimale.h"



int Distance_Min(code C, int*cpt,int Limite)
{
   


    int i; //ligne
    int j; // colone
    int p,w = C.n,t;
    do{

            for(i = 0;i<C.k;i++)
            {
                do{p = random()%C.n}while(!C.mat[i][p]);
                for(k=0;k<C.n;k++)
                    if(k!=i && C.mat[k][p]) add(C.mat[k],C.mat[i],C.n);
                t = weight(C.mat[i],C.n);
                if(t<w) w = t;

                if(t[p]) add(t,C.mat[i],C.n); 
            }
            w = weight(t,C.n);
    }while ((*cpt)->0 && w>=limite)
   
    return w;
}

