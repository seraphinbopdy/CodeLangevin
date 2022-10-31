

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ANF_Fonction.h"


void Fonction_ANF(int Fonction[],int q)
{
    int u;

    if(q==1) return;

    Fonction_ANF(Fonction,q/2);
    Fonction_ANF(Fonction+q/2,q/2);

    for(u=0;u<q/2;u++)
    {
        Fonction[u+q/2] = Fonction[u]; 
    }

}