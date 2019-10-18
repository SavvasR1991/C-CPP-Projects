#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "Contact_List.h"


///////////////////////////////////////////////////////////////////////
////                SYNARTHSEIS GIA TA THLEFWNA                    ////
//////////////////////////////////////////////////////////////////////

typedef struct info_node_thlefwna
{   int      size;
	typos_deikti_tilefwna     arxi_thlefwna; 	/*deikths sto proto komvo tis listas*/
	//typos_deikti_tilefwna    deikths_tilefwna;
} info_node_thlefwna;     /* o komvos plhroforias ths listas*/

typedef struct lista_tilefwnwn{
    char typos_tilefonou;                //O tupos tous thlefwnou
    char noumero[MAX_NOUMERO];           //O ari8mos
    typos_deikti_tilefwna epomenos;      //Deixnei sto epomeno thlefwno
    typos_deikti_tilefwna proigoumenos;  //Deixnei sto proigoumeno thlefwno
} lista_tilefwnwn;



typos_deikti_tilefwna_info LIST_dimiourgia_thlefwna( )
{/*	Pro: 		kamia
  *	Meta: 		Dhmioyrgia kenhs syndedemenhs listas meso tis desmeusis kai arxikopoiisis tou  komvou
                linfo pou leitourgei os komvos pliroforias kai tha sindethei me ton proto komvo pou tha
                eisaxthei */
    typos_deikti_tilefwna_info linfo;
    linfo = malloc(sizeof(info_node_thlefwna));
    linfo->size = 0;
	linfo->arxi_thlefwna = NULL;
    printf("\nLista thlefwnwn dhmiourghthike!!\n\n");
    return linfo;
}
void LIST_keni_tilefwna(const typos_deikti_tilefwna_info  linfo)
{
   if(linfo==NULL)
    {   printf("\nDen uparxei lista gia na elexthei an einai kenh !\n");
    }
    else{
        if(linfo->arxi_thlefwna == NULL)
            printf("\nH lista einai kenh!\n");
        else
            printf("\nH lista DEN einai kenh!\n");
    }
}

void LIST_eisagogi_tilefwna(typos_deikti_tilefwna_info * const linfo)
{
	int error=0;
    char stoixeio[MAX_NOUMERO];
    char kathgoria;
    if((*linfo)==NULL)
    { printf("\nDen uparxei lista tilefwnwn  gia na eisaxthei stoixeio!\n");
    }
    else{
        fputs("\nDwse to thlefwno tis epafhs gia eisagwgh : \n",stdout);
        fgets(stoixeio,MAX_NOUMERO,stdin);
        printf("Dwste kathgoria thlefwnou :\n-> G Geniko\n-> H House\n-> W Work\n-> M Mobile\n\n : ");
        scanf("%c",&kathgoria);
        while(kathgoria!='h'&&kathgoria!='H'&&kathgoria!='g'&&kathgoria!='G'&&kathgoria!='M'&&kathgoria!='m'&&kathgoria!='W'&&kathgoria!='w'){
            printf("Sfalma epelekse apo auta edw :\n-> G Geniko\n-> H House\n-> W Work\n-> M Mobile\n\n : ");
            getchar();
            scanf("%c",&kathgoria);
        }
        eisagogi_arxi_tilefwna(linfo, stoixeio,kathgoria, &error);


        if(error)
            printf("\nError! Adynamia desmeyshs mnhmhs(malloc)!\n");
        else{
            fputs("\nEisaxthei to thlefwno :",stdout);
            puts(stoixeio);

        }
    }
}
void eisagogi_arxi_tilefwna(typos_deikti_tilefwna_info *  const linfo,TStoixeioyListas *stoixeio,char kathgoria, int *error)
{
	typos_deikti_tilefwna prosorinos,temp=NULL,prosorinos2;
	prosorinos = malloc(sizeof(lista_tilefwnwn));

	if ( prosorinos == NULL )
	{   *error=1;
	}
	else{

        if((*linfo)->arxi_thlefwna == NULL){
            strcpy(prosorinos->noumero, stoixeio);
            prosorinos->typos_tilefonou=kathgoria;
            prosorinos->epomenos = prosorinos;
            prosorinos->proigoumenos = prosorinos;
        }
        else{
            strcpy(prosorinos->noumero, stoixeio);
            prosorinos->typos_tilefonou=kathgoria;
            prosorinos2=(*linfo)->arxi_thlefwna;
            while (prosorinos2->epomenos != (*linfo)->arxi_thlefwna){
                prosorinos2=prosorinos2->epomenos;
            }
            temp=prosorinos2;
            prosorinos->epomenos = (*linfo)->arxi_thlefwna;
            prosorinos->proigoumenos=temp;
            temp->epomenos = prosorinos;
        }

        if ((*linfo)->arxi_thlefwna != NULL)
            (*linfo)->arxi_thlefwna->proigoumenos = prosorinos;
        (*linfo)->arxi_thlefwna = prosorinos;
        (*linfo)->size ++;
	}
}



void LIST_diadromi_tilefwna(const typos_deikti_tilefwna_info const *linfo)
{
    typos_deikti_tilefwna temp;
    if((*linfo)==NULL)
    { printf("\nDen uparxei lista  gia na ektypothoun ta periexomena ths listas !\n");
    }
    else if((*linfo)->arxi_thlefwna == NULL)
    {   printf("\nH lista einai kenh!\n");
    }
    else {
        temp=(*linfo)->arxi_thlefwna;
        if((*linfo)->arxi_thlefwna == NULL)
        {   printf("\nH lista einai kenh!\n");
        }
        else{
            printf("\nEktypwsh twn thlefwnwn ths listas!\n");
            do
            {   printf("--> '%c'  %s ",temp->typos_tilefonou,temp->noumero);
                temp=temp->epomenos;
            }
            while(temp!=(*linfo)->arxi_thlefwna);
        }
    }
}
void LIST_epomenos_tilefwna(typos_deikti_tilefwna_info *  const linfo){
    if((*linfo)==NULL)
    {   printf("\nDen uparxei lista  gia na metakinhthei o deikths  sto epomeno thlefwno ths listas !\n");
    }
    else if((*linfo)->arxi_thlefwna == NULL)
    {   printf("\nH lista einai kenh!\n");
    }
    else {
        (*linfo)->arxi_thlefwna = (*linfo)->arxi_thlefwna->epomenos;
        printf("\nO dromeas metakinh8hke sthn epafh:  '%c'  %s  \n",(*linfo)->arxi_thlefwna->typos_tilefonou,(*linfo)->arxi_thlefwna->noumero);
    }
}
void LIST_proigoymenos_tilefwna(typos_deikti_tilefwna_info *  const linfo){
    if((*linfo)==NULL)
    {    printf("\nDen uparxei lista  gia na metakinhthei o deikths  sto proigoumeno thlefwno ths listas !\n");
    }
    else if((*linfo)->arxi_thlefwna == NULL)
    {   printf("\nH lista einai kenh!\n");
    }
    else {
        (*linfo)->arxi_thlefwna = (*linfo)->arxi_thlefwna->proigoumenos;
        printf("\nO dromeas metakinh8hke sthn epafh:  '%c'  %s  \n",(*linfo)->arxi_thlefwna->typos_tilefonou,(*linfo)->arxi_thlefwna->noumero);
    }
}
void LIST_allagi_noumero_tilefwna(typos_deikti_tilefwna_info *  const linfo){

    char stoixeio[MAX_NOUMERO];
    if((*linfo)==NULL)
    {   printf("\nDen uparxei lista  gia na allaksei to noumero ths listas !\n");
    }
    else if((*linfo)->arxi_thlefwna == NULL)
    {   printf("\nH lista einai kenh!\n");
    }
    else {
        printf("\nDwse ena neo noumero gia allagh ths epafhs : %s \n",(*linfo)->arxi_thlefwna->noumero);
        fgets(stoixeio,MAX_NOUMERO,stdin);
        strcpy((*linfo)->arxi_thlefwna->noumero, stoixeio);
        printf("\nH allagh egine!\n");
    }
}
void LIST_allagi_tupou_tilefwna(typos_deikti_tilefwna_info *  const linfo){

    char stoixeio;
    if((*linfo)==NULL)
    {   printf("\nDen uparxei lista  gia na allaksei o tupos thlefwnou ths listas !\n");
    }
    else if((*linfo)->arxi_thlefwna == NULL)
    {   printf("\nH lista einai kenh!\n");
    }
    else {
        printf("\nDwste nea kathgoria thlefwnou :\n-> G Geniko\n-> H House\n-> W Work\n-> M Mobile\n\n : ");
        scanf("%c",&stoixeio);
        while(stoixeio!='h'&&stoixeio!='H'&&stoixeio!='g'&&stoixeio!='G'&&stoixeio!='M'&&stoixeio!='m'&&stoixeio!='W'&&stoixeio!='w'){
            printf("Sfalma epelekse apo auta edw :\n-> G Geniko\n-> H House\n-> W Work\n-> M Mobile\n\n : ");
            getchar();
            scanf("%c",&stoixeio);
        }
        (*linfo)->arxi_thlefwna->typos_tilefonou = stoixeio;
        printf("\nH allagh egine!\n");
    }
}

void LIST_diagrafi_tilefwna(typos_deikti_tilefwna_info *  const linfo){

    typos_deikti_tilefwna prosorinos,previous;
	char ch;
    if((*linfo)==NULL)
    { printf("\nDen uparxei lista  gia na diagrafoun ta onomata ths listas !\n");

    }
    else {
        if ((*linfo)->arxi_thlefwna == NULL)
        {   printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
        }
        else{
            printf("\nEiste sigouroi pws theletai na diagrafei to :\n %s ",((*linfo)->arxi_thlefwna)->noumero);
            printf("kathgorias : '%c' ?[y,n]\n",((*linfo)->arxi_thlefwna)->typos_tilefonou);
            scanf("%c",&ch);
            if((ch=='y')||(ch=='Y')){
                prosorinos=(*linfo)->arxi_thlefwna;
                previous=prosorinos->proigoumenos;
                (*linfo)->arxi_thlefwna=prosorinos->epomenos;
                previous->epomenos=prosorinos->epomenos;
                if(((*linfo)->arxi_thlefwna)!=NULL)
                    ((*linfo)->arxi_thlefwna)->proigoumenos = previous;
                free(prosorinos);
                prosorinos = NULL;
                (*linfo)->size--;
             printf("\nDiagrafhke o kombos pou edeixne o dromeas!\n");
            }
        }
    }
}

void  LIST_katastrofi_tilefwna(typos_deikti_tilefwna_info * const linfo){
    typos_deikti_tilefwna todel,todel2;
    if((*linfo)==NULL)
    { printf("\nDen uparxei lista thlefwnwn gia na katastrafei  !\n");

    }
    else{
        todel= (*linfo)->arxi_thlefwna;
        if((*linfo)->arxi_thlefwna != NULL)
            do
            {   todel2=todel;
                todel=(todel)->epomenos;
                free(todel2);
            }while(todel!=(*linfo)->arxi_thlefwna);
        (*linfo)->arxi_thlefwna = NULL;
        printf("\nH lista katastrafike!\n");
    }


}

