#ifndef CODE_H
#define CODE_H

typedef unsigned char uchar;

typedef struct code
{
    int n;
    int k;
    uchar**mat;
}code;
int Combinaison_De_N_Dans_K(int n,int k); 

#endif

