


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fonction_Printf.h"




//Une fonction d'affichage
void print(uchar*fct, int m) 
{

    int u;
    int v;
    int l;
    anf(fct,1<<m);
    for(u=0;u<(1<<m);u++)
    {
        //ici je dois controller la valeur des unites de U(abc) et regarder si c'est null ou pas  
        if(fct[u]){
            v = u; l = 'a';
            while(v){
                if(v&1) putchar(l);
                l++;v = v>>1;
            }
            putchar('+');
        }
    }anf(fct,1<<m);
}
