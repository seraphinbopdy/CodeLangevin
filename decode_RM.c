

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decode_RM.h"


int Decode_RM(uchar fonct[],int q) //q represente ici (2^m).
{
    int vett[q];

    int x;
    int b;
    int s;

    for(x=0;x<q;x++)
    {
        vett[x] = fonct[x]?-1:1;
    }
    // je cherche le plus grand Coefficient de Fourier.
    // j'appelle la Fonction de Fourier deja implementer ici
    Fourier(vett,q);
    s = vett[0]; 
    b = 0;

    for(int a = 0;a<q;a++)
    {
        if(abs(vett[a])>s)
        {
            s = abs(vett[a]);
            b = a;
        }
    } 
    
    if(vett[b]<b)
        return -b;
    return b

}