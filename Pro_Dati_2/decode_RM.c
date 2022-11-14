

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fonction_Fourier.h"
#include "decode_RM.h"
#include "code.h"




void F_Fourier(int *fonct, int q)
{
    int u;
    int variable_soutient;
    if(q == 1) return;

    F_Fourier(fonct,q/2);
    F_Fourier(fonct+q/2,q/2);

    for(u = 0; u <q/2; u++)
    {
        variable_soutient = fonct[u];
        fonct[u] = variable_soutient + fonct[u+q/2];
        fonct[u+q/2] = variable_soutient - fonct[u+q/2];
    }
}


int Decode_RM(int fonct[],int q) //q represente ici (2^m).
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
    F_Fourier(vett,q);
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
    return b;

}
