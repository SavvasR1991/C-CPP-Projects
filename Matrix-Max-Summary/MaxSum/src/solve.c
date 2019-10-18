#include "Headerfunctions.h"     /*dhlwsh ths Kefalidas pou perilambanei tis sunarthseis*/
#include "HeaderMatrixMalloc.h"  /*dhlwsh ths Kefalidas pou perilambanei tIN sunarthsh*/
#include<stdio.h>                     /*dunamikhs desmeushs mnhmhs 2-diastatou pinaka*/
#define  MATRREC                 /*analoga me to orisma tou define 8a ektelestei i analogh sunarthsh*/




/*///////////////////////////////
// KLHSH EPANALHPTIKH ME8ODOY  //
///////////////////////////////*/

#ifdef ITER                      /*an orisma einai INTER ektelhtai h epanalhptikh me8odos*/
void solve (int n,int m,int **matr){
    printf("Running iterative\n");
    iterative(matr,n,m);
}
#endif


/*//////////////////////////////////////
// KLHSH ANADRIMIKHS ME8ODOY ME PINAKA//
//////////////////////////////////////*/

#ifdef MATRREC                   /*an orisma einai MATRREC ektelhtai h anadromikh me8odos,me xrhsh pinaka*/
void solve (int n,int m,int **matr){
    int **sum,i,j,maxsum=0,maxpath,maxpoint,b;
    printf("Running matrRecursive\n");
    sum = MatrixMalloc(n,m);     /*kalese sunarthsh dunamikhs desmeushs mnhmhs disdiastatou pinaka*/
    i=0;
	for(j=0;j<m;j++)             /*Kalese tin anadromikh,exontas afethria ta stoixeia tis prwths grammhs*/
        matrRecursuve(matr,n,m,i,j,sum);/*euresh megistwn monopatiwn */
	for(j=0;j<m;j++)             /*h matrRecursive epistrefei ta megiasta merika a8roismata apo tn (1)-(n-1) grammh*/
		sum[0][j]+=matr[0][j];   /*ara gia tn grammh (0) 8a pros8esoume ta merika a8roismata me tin (0)grammh*/
	for(j=0;j<m;j++){            /*Euresh timhs tou megistou monopatiou*/
	    if(maxsum<sum[0][j]){    /*Sugkrish olwn twn stoixeiwn ths prwths grammhs*/
            maxsum=sum[0][j];  /*uplogise to megisto */
            maxpoint=j;             /*kai krata kai tin thesh tou*/
	    }
	}
    printf("Max sum is %d \n",maxsum);/*ektupwsh apotelesmatos*/
    maxsum=maxsum-matr[0][maxpoint];
    printf("%d -> ",matr[0][maxpoint]);
	for(i=1;i<n;i++){            /*ypologismos monopatiou*/
	    if(i<n-1){              /*upologise apo tin deuterh grammh ews tin proteleutaia*/
	      b=maxpoint-1;                            /*phgaine panw deksia apo to shmeio pou eimaste*/
          if(b<0)                                /* an bgoume ektos phgaine stn teleutaia sthlh*/
                b=m-1;
          if(maxsum-matr[i][b]==sum[i][b]){   /*an to trexwn megisto meion ton antistoixo stoixeio pou eimaste*/
                maxpoint=b;                     /*einai iso me to meriko a8roisma tou brikame to stoixeio tou monopatiou*/
                printf("%d -> ",matr[i][b]);    /*ektupwse to stoixeio*/
                maxsum=maxsum-matr[i][maxpoint]; /*upologise to epomeno megisto tis epomenis grammhs*/
                continue;
          }
          b=maxpoint+1;                            /*phgaine panw aristera apo to shmeio pou eimaste*/
          if(b>m-1)                              /* an bgoume ektos phgaine stn prwth sthlh*/
                b=0;
          if(maxsum-matr[i][b]==sum[i][b]){ /*an to trexwn megisto meion ton antistoixo stoixeio pou eimaste*/
                maxpoint=b;                     /*einai iso me to meriko a8roisma tou brikame to stoixeio tou monopatiou*/
                printf("%d -> ",matr[i][b]);    /*ektupwse to stoixeio*/
                maxsum=maxsum-matr[i][maxpoint];/*upologise to epomeno megisto tis epomenis grammhs*/
                continue;
          }
          b=maxpoint;
          if(maxsum-matr[i][b]==sum[i][b]){/*an to trexwn megisto meion ton antistoixo stoixeio pou eimaste*/
                maxpoint=b;                     /*einai iso me to meriko a8roisma tou brikame to stoixeio tou monopatiou*/
                printf("%d -> ",matr[i][b]);     /*ektupwse to stoixeio*/
                maxsum=maxsum-matr[i][maxpoint];/*upologise to epomeno megisto tis epomenis grammhs*/
                continue;
          }
	    }
        if(i==n-1)    /*otan ftaseis sth teleutaia grammh ektupwse to teleutaio athroisma*/
            printf("%d \n",maxsum); /*dld to teleutaio stoixeio tou monopatiou*/
	}
    for (i = 0 ; i < n ; i++)                 /*apodesmush mnhmhs*/
       free(sum[i]);
    free(sum);
}
#endif


/*////////////////////////////////////////
//KLHSH ANADRIMIKHS ME8ODOY XWRIS PINAKA//
////////////////////////////////////////*/

#ifdef PUREREC                              /*an orisma einai PUREREC ektelhtai h anadromikh me8odos,xwris xrhsh pinaka*/
void solve (int n,int m,int **matr){
    int sumpure,maxsum=0,i=0,j;
    printf("Running pureRecursive\n");
    for(j=0;j<m;j++){                       /*eiswdos twn stoixeiwn ths prwths grammhs tou pinaka matr*/
        sumpure=pureRecursive(matr,n,m,i,j);/*euresh megistou monopatiou me afeteria to matr[0][j]*/
        if(sumpure>=maxsum)                 /*sugkrish twn athroismatwn gia th euresh tou megistou athroismaros*/
            maxsum=sumpure;
    }
    printf("Max sum is %d\n",maxsum);       /*ektupwse apotelesma */
}
#endif
