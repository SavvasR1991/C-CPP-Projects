/***************************************************************************
Arxeio ylopoihshs	: Stack.c
Syggrafeas			: Õ. Cotronis
Skopos				: Ylopoihsh me pinaka, ATD Stoiva me Merikh Apokrypsh
Ana8ewrhsh          : X. Georgakopoylos, S. Gkiokas
****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/*orismos synarthsewn*/

void Stoiva_dimiourgia(TStoivas *stoiva)
{
 /*
 *	Pro: 		Kamia
 *	Meta: 		Dhmioyrgia kenhs stoivas
*/
	stoiva->korifi = -1;
}

int  Stoiva_keni(TStoivas stoiva)
{
 /*
 *	Pro: 	    Dhmioyrgia ths stoiva
 *	Meta: 		Epistrefei 1 an h stoiva einai kenh alliws 0
*/
	return (stoiva.korifi == -1);
}


void Stoiva_othisi(TStoivas *stoiva,TStoixeioyStoivas stoixeio,int *yperxeilisi)
{
 /*
 *	Pro: 		Dhmioyrgia ths stoiva
 *	Meta: 		Wtheitai to stoixeio sth stoiva
*/
	if (stoiva->korifi == PLITHOS -1)
		*yperxeilisi = 1;
	else
	{
		*yperxeilisi = 0;
		stoiva->korifi++;
		TSstoiva_setValues(&(stoiva->pinakas[stoiva->korifi]), stoixeio);
	}
}

void Stoiva_TopValue(TStoivas stoiva,TStoixeioyStoivas *stoixeio,int *ypoxeilisi){
        /*H Stoiva_TopValue epistrefei sto "stoixeio" to stoixeio pou exei h stoiva sthn korifh*/
    if (Stoiva_keni(stoiva))    /*elenxos ama einai kenh h stoiva*/
		*ypoxeilisi = 1;
	else                        /*ama h stoiva dn einai kenh*/
	{
		*ypoxeilisi = 0;
		TSstoiva_setValues(stoixeio, stoiva.pinakas[stoiva.korifi]);   /*epestrepe sto stoixeio*/
	}
}

void Stoiva_PopState(TStoivas *stoiva,int *ypoxeilisi){
    /*meiwnei thn stoiva kata ena*/
    if (Stoiva_keni(*stoiva))   /*elenxos ama einai kenh h stoiva*/
		*ypoxeilisi = 1;
	else{                       /*ama h stoiva dn einai kenh*/
        *ypoxeilisi = 0;
        stoiva->korifi--;       /*meiwse thn stoiva*/
        if (Stoiva_keni(*stoiva))/*elenxos gia thn stoiva an einai kenh*/
            *ypoxeilisi = 1;
	}
}
