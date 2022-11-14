
#include "Binomial.h"
#include"code.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





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

void affiche_Matrice(code c)
{
    for(int i = 0;i<c.k;i++)
    {
        for(int j=0;j<c.n;j++)
        {
            printf("%d  ",c.mat[i][j]);
        }
        printf("\n");
    }
}

void Liberer_Memoire(code c){
    for(int i=0;i<c.k;i++)
    {
            free(c.mat[i]);
            c.mat[i] = NULL;
    }

        free(c.mat);
        c.mat = NULL;
}

void add(uchar dest[], uchar src[],int q)
{
    for(int i =0;i<q;i++)
    {
        dest[i] = dest[i]^src[i];
    }
}


//Calcul du poids d'un vecteur
int weight(uchar*s,int n)
{
    int res = 0;
    for(int j=0;j<n;j++)
    {
        res+=s[j];
    }
    return  res;
}

//calcul du poids d'un code.
int poids(code CODE)
{
    int score = CODE.n;
    int wt,i,t;

    uchar vett[CODE.n];


    //int limite = 1;
    //limite << CODE.k;

    for(int z =0;z<(1<<CODE.k);z++)
    {
            for(int j=0;j<CODE.n;j++){
                vett[j] = 0;
            }

            t = z; i = 0;
            while(t){
                if(t&i) 
                    add(vett,CODE.mat[i],CODE.n);
            t>>=1;
            i++;
            }

            wt = weight(vett,CODE.n);
            if(wt<score) score = wt;

    }
    return score;
}




// Une Autre fonction pour le Calcul du Binomial
int Combinaison_De_N_Dans_K(int n,int k)
{
    if(k==1)
        return n;
    else if(n==k)
        return 1;
    else return (Combinaison_De_N_Dans_K(n-1,k)+Combinaison_De_N_Dans_K(n-1,k-1));
}



//Calcul de la Somme du binomial pour trouver la dimension 
int rmdimen(int k, int m)
{
    int r = 0;
    for(int i=0;i<=k;i++)
    {
        r+=Combinaison_De_N_Dans_K(i,m);
    }
    return r;
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

code RM(int k, int m)
{
    code res;
    int u,i,x;

    res = Init_Code((rmdimen(k,m)),(1<<m));
    i=0;
    for(u=0;u<res.n;u++)
    {
        if(wt(u)<=k)//Calcule du poids qui nous returne un entier
        {
            for(x=0;x<res.n;x++)
                res.mat[i][x] = ((x&u)==u);
            i++;
        }
    }
    return res;
}




int main(int argc, char *argv[])
{
    int k ,n;
    k = atoi(argv[1]);
    n = atoi(argv[2]);

    code CODE = Init_Code(k,n);  
    affiche_Matrice(CODE);
    
    int result_Poids = poids(CODE);

    printf("----> %d \n",result_Poids);

    printf("%d ",Combinaison_De_N_Dans_K(n,k));

    printf(">>>%d \n",rmdimen(k,n));  

    code f = RM(8,4);
    affiche_Matrice(f);
    

    Liberer_Memoire(CODE);
    return 0;
}
