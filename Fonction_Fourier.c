

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Fonction_Fourier.h"


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