


#include "read_code.h";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


code reade_code(char*nom)
{
    code res; 
    char ligne[1024],*ptr;
    File*src;
    int n,k;
    int k,j ;
    int i = 0; 

    src = fopen(nom,"r")
    if(!src) {perror(" ")}
    while(fgets(ligne,sizeof(ligne),src) != NULL) {
        switch(ligne[0]){
            case '#': break;
            case 'm': sscanf(ligne, "m=%d", &n) break;
            case 'k': sscanf(ligne, "k=%d", &k) ;
            res = Init_Code(k,n);
            break;
            case '[' j=0; ptr = &ligne[0];

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