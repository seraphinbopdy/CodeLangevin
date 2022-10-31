

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "table_verite.h"


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
    anf(fonction,1<<m);
    return fonction;
}