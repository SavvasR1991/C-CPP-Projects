/*////////////////////////////////////////////////////////////
// SUNARTHSH DYNAMIKHS DESMEUSHS MNHMHS DI-DIASTATOU PINAKA //
////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>

int MatrixMalloc(int n,int m){
    int i,j,**matrix;
    matrix=malloc(n * sizeof(int *));    /*dunamikh desmeush gia ton pinaka (n x m)*/
    if(matrix==NULL){
        printf("Cannot allocate memory\n");
        return 1;}
    for (i = 0 ; i < n ; i++) {
      matrix[i] = malloc(m * sizeof(int));
      if(matrix[i]==NULL){
        printf("Cannot allocate memory\n");
        return 1;}
      for (j = 0 ; j < m ; j++){        /*arxikopoihsh  tou pinaka me -1(pinakas merikwn a8roismatwn */
            matrix[i][j]=-1;            /*gia tis sunarthseis iterative kai matrRecursive*/
      }
    }
    return matrix;
}
