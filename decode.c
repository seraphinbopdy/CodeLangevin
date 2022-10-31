

#include "decode.h";


int decode(code C, char t[], int*cpt,int Limite)
{
    // recherche d'un mot de C tel que :
    // wt(c+t)<w( Limite dans ce ca s c'est notre Cible) // Limite ici c'est le poid et tant que ce poid 
    // n'est pas atteind je ne m'arrete pas  

    int i; //ligne
    int j; // colone
    int p,w;
    do{
            for(i = 0;i<C.k;i++)
            {
                //sur chaque ligne je genère une valeur et controle si ca vaut 1 ou 0
                do{p = random()%C.n}while(!C.mat[i][p]);
                for(k=0;k<C.n;k++)
                    if(k!=i && C.mat[k][p]) add(C.mat[k],C.mat[i],C.n);

                if(t[p]) add(t,C.mat[i],C.n); 
            }
            w = weight(t,C.n);
    }while ((*cpt)-->0 && w>=limite)
    // je controle puis je desincremente.
    // la comparaison avec limite c'est pour dire le poid ne doit pas depasser la taille limite donné en entrée.

    return w;
}
