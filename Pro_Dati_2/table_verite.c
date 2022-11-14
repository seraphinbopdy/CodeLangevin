

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "table_verite.h"




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


uchar*TBV(char*exp,int m)
{
    char*ptr;
    int u=0;

    uchar*fonction = malloc(1<<m,sizeof(char));

    ptr = exp;

    while(*ptr!= '=') ptr++;
    ptr++;

    while(*ptr){
        if(isalpha(*ptr))
                u^=1<<(*ptr-'a');
        if(*ptr == '+'){fonction[u]=1;u=0;}
        ptr++;
    }

    fonction[u] = 1;
    Fonction_ANF(fonction,1<<m);
    return fonction;
}
