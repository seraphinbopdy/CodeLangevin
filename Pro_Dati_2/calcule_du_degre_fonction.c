#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ANF_Fonction.h"
#include "calcule_du_degre_fonction.h"
#include "poids.h"
#include "code.h"   



//#include "calcul_du_degre_fonction.h"
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



//Calcule du poids d'un entier
int wt(int z)
{
    int r =0;
    while(z)
    {
        r = r+(z&1);
        z = z>>1;
    }
    return r;
}





int degre_fonction(int*f,int m)
{
    int u;
    int res = -1;

    for(u =0;u< (1<<m);u++)
    {
        if(f[u] && (wt(u)> res)) res = wt(u);

        //Anf c'est une fonction a definir dehors et a implementer
    }
    Fonction_ANF(f,1<<m);
    return res;
}
