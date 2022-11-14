

#include "code.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>



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


code reade_code(char*nom)
{
    code res; 
    char ligne[1024],*ptr;
    FILE*src;
    int n,k;
    int j ;
    int i = 0; 

    src = fopen(nom,"r");
    if(!src) {perror(" ");}
    while(fgets(ligne,sizeof(ligne),src) != NULL) {
        switch(ligne[0]){
            case '#': break;
            case 'n': sscanf(ligne, "m=%d", &n); break;
            case 'k': sscanf(ligne, "k=%d", &k) ;
            res = Init_Code(k,n);
            break;
            case '[': j=0; ptr = &ligne[0];

            while(*ptr)
            {
                if(*ptr == '0') res.mat[i][j++] = 0;
                if(*ptr == '1') res.mat[i][j++] = 1;
            }
            i++;
        break;
        default:
        }
        fclose(src);
    }
}