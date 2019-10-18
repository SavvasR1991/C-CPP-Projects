#include <stdio.h>              /*Dhlwseis gia protuph biblio8hkh kai stdlib.h gia thn malloc*/
#include "HeaderMatrixMalloc.h"
#include "Headersolve.h"        /*dhlwsei gia tin Kefalida Headersolve pou periexei thn sunarthsh solve*/

int main(){
    int **matr,n,m,i,j;         /*dhlwseis metablhtwn*/
    scanf("%d",&n);             /*eisodos diastasewn tou pinaka */
    scanf("%d",&m);
    matr = MatrixMalloc(n,m);   /*kalese sunarthsh dunamikhs desmeushs mnhmhs disdiastatou pinaka*/
    for (i = 0 ; i < n ; i++) {
       for (j = 0 ; j < m ; j++)
          scanf("%d", &matr[i][j]);/*eisagwgh twn stoixeiwn tou pinaka */
    }
    solve(n,m,matr);            /*Klhsh sunarthshs solve*/
    for (i = 0 ; i < n ; i++)   /*apodesmush mnhmhs*/
       free(matr[i]);
    free(matr);
    return 0;
}

