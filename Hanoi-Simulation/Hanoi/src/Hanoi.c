/*****************************************************
Arxeio ylopoihshs	: Hanoi.c
Syggrafeas			:
Skopos				: Skeleton program gia Ylopoihsh Algorithmoy Hanoi me Stoives
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "TStoixeioyStoivas.h"

void Input(FILE * from, TStoivas *S, int *n);
void Output(FILE * to, TStoivas *S);
void Move(TStoivas *from, TStoivas *to);
void recursiveHanoi(int level, TStoivas *from, TStoivas *to, TStoivas *with);

int main(void){

	TStoivas A, B, C;
	FILE *inputFile, *outputFile;
	int num=0,i;

    inputFile = fopen("/home/savvas/Desktop/c/C-Projects/Hanoi_Simulation/Hanoi/data_input/AktinaYpsos.txt","r");
    if(inputFile == NULL){                                  /*elenxos gia ton an tha kataferei to programma na anoiksei ta arxeia */
            printf("Error file does not exist,check your File path\n\n");
        return 0;
    }
    outputFile = fopen("/home/savvas/Desktop/c/C-Projects/Hanoi_Simulation/Hanoi/data_input/Results.txt","w");
    if(outputFile == NULL){
        printf("Error file does not exist,check your File path\n\n");
        return 0;
    }
    /*anoigoume ta arxeia gia diabasma kai gia eggrafh */

	Stoiva_dimiourgia(&A);  /*dhmiourgia stoivas A*/
	Stoiva_dimiourgia(&B);  /*dhmiourgia stoivas B*/
	Stoiva_dimiourgia(&C);  /*dhmiourgia stoivas C*/

	Input(inputFile, &A, &num);

	printf("\n\nFirst State of the Stacks\n\n");    /*Mia grafikh anaparastash twn stoilwn kai diskwn*/
	for (i=num-1;i>=0;i--){
        printf("  %3d \n",A.pinakas[i].aktina);     /*gia t1 erwthmata 1,2 =>   A.pinakas[i].aktina ->  A.pinakas[i] */
	}
	printf("|______|    |______|    |______|\n  Start     Temporal     Finish\n");
	printf("\n.......Executing recursiveHanoi.......\n\n");

    recursiveHanoi(num, &A, &B, &C);

	printf("\nFinal State of the Stacks\n\n");      /*Mia grafikh anaparastash twn stoilwn kai diskwn*/
	for (i=num-1;i>=0;i--){
        printf("                          %3d \n",B.pinakas[i].aktina);/*gia t1 erwthmata 1,2 =>   B.pinakas[i].aktina ->  B.pinakas[i] */
	}
	printf("|______|    |______|    |______|\n  Start     Temporal     Finish\n");


	Output(outputFile, &B);

	return 0;
}

void Input(FILE *from, TStoivas *S, int *n) {

    int error;
    int number = 0;
    TStoixeioyStoivas stoixeio,stoixeio1;

    while(!feof(from)){                              /*sarwse olo to arxeio from*/
        TSstoiva_readValue(from,&stoixeio);          /*diabase ta stoixeia*/
        if((stoixeio.aktina==0)||(stoixeio.ypsos == 0)) /*stoxeio prepei na exei diastaseis, oxi mhden*/
        {   printf("\n Error at readValue,element without dimension !\n");  /*elenxos gia ta stoixeia ama einai ortha*/
            return;
              }
        if(Stoiva_keni(*S)||TSstoiva_mikrotero(stoixeio,stoixeio1)){  /*elenxos gia ton 1 kai 2 kanona*/
            Stoiva_othisi(S, stoixeio, &error);     /*kane othish "stoixeio" sthn stoiva*/
            printf("Inserting element with [ Radius =%3d , Hight = %d ].....\n",stoixeio.aktina,stoixeio.ypsos);/*gia ta erwthmata 1,2 =>  printf("Inserting element with [ Radius =%3d ,Hight = %d ].....\n",stoixeio);*/
            if(error){                              /*elenxos gia yperxeilhsh*/
	           printf("\nOverflow of the stack.The element has not been inserted\n\n");
	          return;
            }
            printf("Element has been insert succesfully.......\n");
            number++;               /*auksise to number,deixnei to plhthos twn stoixeiwn pou eisaxthsan*/
        }
        *n=number;                  /*dwse thn timh sto n*/
        Stoiva_TopValue(*S, &stoixeio1, &error);/*bale sto "stoixeio1" to panw stoixeio*/
    }                               /*ths stoivas,gia ton elenxo tis sunthikh 2 gia pio panw*/
    fclose(from);                   /*kleise to reuma from*/
}

void Move(TStoivas *Source, TStoivas *Target) {

    int error,error2,error3;                     /*metablhtes gia ta lathu*/
    TStoixeioyStoivas temp;                      /*prwsorinh metablhth*/
    Stoiva_TopValue(*Source,&temp,&error);       /*bale sthn prwsorinh metablhth to panw stoixeio ths stoivas*/
    if(error){                                   /*elenxos gia upoxeilhsh*/
        printf("\nUnderflow of stack.Stack is empty!\n");
        return;
        }
    else{                                        /*H stoiva dn einai adeia*/
        Stoiva_PopState(Source,&error2);         /*meiwse thn stoiva A kata ena,exei bgei to stoixeio*/
       /* if(error2){
            printf("\nYpoxeilhsh stoivas.Dn uparxei kanena stoixeio !\n");}*/
        Stoiva_othisi(Target,temp,&error3);      /*bale to stoixeio apo thn A sthn allh stoiva*/
        if(error3){
            printf("\nOverflow of the stack.The element has not been inserted!\n\n");
            return;
        }
    }

}

void recursiveHanoi(int level, TStoivas *from, TStoivas *to, TStoivas *with) {
     if (level >= 1) {
        recursiveHanoi(level - 1, from, with, to);
        Move(from, to);
        recursiveHanoi(level - 1, with, to, from);
     }
}

void Output(FILE *to, TStoivas *S){

    TStoixeioyStoivas stoxeio_teliko;
    int error = 0,error2;   /*arxikopoihsh tou error*/
    while(error == 0){      /*Epanelabe mexri to error != 0 dhladh oi stoiva na adeiasei*/
        Stoiva_TopValue(*S,&stoxeio_teliko,&error2);  /*pairnoume to panw stoixeio tis stoivas*/
        if(error2)
         {   printf("\nError at TopValue,could't find element from stack!\n");  /*elenxos gia lathos*/
             return;
              }
        TSstoiva_writeValue(to,stoxeio_teliko); /*grapse sto arxeio "to" ta stoixeia*/
        Stoiva_PopState(S, &error);             /*meiwse thn stoiva kata ena*/
    }
    fclose(to); /*kleise to reuma "to"*/
}
