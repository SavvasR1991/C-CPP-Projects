#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Contact_List.h"

///////////////////////////////////////////////////////////////////////
////                SYNARTHSEIS GIA TIS EPAFES                     ////
//////////////////////////////////////////////////////////////////////

typedef struct info_node
{   int      size;
	typos_deikti     arxi; 	/*deikths sto proto komvo tis listas*/
} info_node;     /* o komvos plhroforias ths listas*/


typedef struct typos_komvou
{   TStoixeioyListas onoma[MAX_ONOMATOS];
    typos_deikti_tilefwna_info tilefwna;      //Deiktis gia to prwto tilefwno ths epafhs
	typos_deikti    epomenos;
	typos_deikti    proigoumenos;
} typos_komvou;	   /*o typos toy kombou ths listas*/



info_deikti fortwsh_dedomenwn_arxeiou(FILE *from){
    info_deikti linfo;
    TStoixeioyListas    stoixeio[MAX_ONOMATOS];
    TStoixeioyListas    stoixeio2[MAX_NOUMERO];
    char    stoixeio3[2];
    char *empty ="\n";
    int error = 0;
    typos_deikti prodeikths = NULL;
     linfo=LIST_dimiourgia();
     while(!feof(from)){
        fgets(stoixeio, MAX_ONOMATOS,from);
        if((strcmp(stoixeio,empty)!=0)){
        printf("Eisagwgh epafhs kai twn stoixeiwn tou: %s\n\n",stoixeio);
        taksinomish(&linfo,&prodeikths,&stoixeio);
        if(prodeikths==NULL){
            eisagogi_arxi(&linfo, stoixeio, &error);
            linfo->arxi->tilefwna=LIST_dimiourgia_thlefwna();}
        else{
            eisagogi_meta(&linfo,stoixeio,prodeikths, &error);
               ((prodeikths)->tilefwna)=LIST_dimiourgia_thlefwna();
        }
        while(!0){

             fgets(stoixeio3,2,from);
             if((strcmp(stoixeio3,empty)==0))
                break;
             fgets(stoixeio2, MAX_NOUMERO,from);
             /*if(prodeikths==NULL){
                    isagogi_arxi_tilefwna(&( linfo->arxi->tilefwna), stoixeio2,stoixeio3, &error);
             }
             else{

                    eisagogi_arxi_tilefwna(&(prodeikths->tilefwna), stoixeio2,stoixeio3, &error);
             }*/
        }
        }
    }
    return linfo;

}


info_deikti LIST_dimiourgia( )
{
    info_deikti linfo;
    linfo = malloc(sizeof(info_node));
    linfo->size = 0;
	linfo->arxi = NULL;
    printf("\nH lista epafwn dimiourgithike!\n\n");
	return linfo;
}

void LIST_katastrofi(info_deikti * linfo,typos_deikti *current)
{/*	Pro: 	  Dhmioyrgia listas
  *	Meta: 	  Katastrofi ths listas kai apodesmeusi sto telos kai tou komvou linfo */

	typos_deikti todel,todel2;
    if((*linfo)==NULL)
    { printf("\nDen uparxei lista  gia na katastrafei  !\n");

    }
    else{
        todel= (*linfo)->arxi;
        if((*linfo)->arxi != NULL)
            do
            {   todel2=todel;
                todel=(todel)->epomenos;
                free(todel2);
            }while(todel!=(*linfo)->arxi);
        (*linfo)->arxi = NULL;
        free(*linfo);
        (*linfo)=NULL;
        printf("\nH lista katastrafike!\n");
        LIST_katastrofi_tilefwna(&(*current)->tilefwna);
        free((*current)->tilefwna);
       (*current)->tilefwna=NULL;

    }
}

void LIST_keni(const info_deikti  linfo)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		epistrefei 1 an h lista einai kenh, diaforetika 0 */
    if(linfo==NULL)
    {   printf("\nDen uparxei lista  gia na elexthei an einai kenh !\n");
    }
    else{
        if(linfo->arxi == NULL)
            printf("\nH lista einai kenh!\n");
        else
            printf("\nH lista DEN einai kenh!\n");
    }
}


void LIST_allagi(const info_deikti  linfo ,typos_deikti * const p)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Allazei ta dedomena ston komvo pou deixnei o p */
    char stoixeio[MAX_ONOMATOS];
    if(linfo==NULL)
    { printf("\nDen uparxei lista  gia na allaxthoun ta periexomena ths listas !\n");
    }
    else{
        if((*p)!=NULL){
            printf("\nDwse ena neo onoma gia allagh ths epafhs : %s \n",(*p)->onoma);
            fgets(stoixeio,MAX_ONOMATOS,stdin);
            strcpy((*p)->onoma, stoixeio);
            printf("\nH allagh egine!\n");
        }
        else
            printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");

    }
}

void LIST_diadromi(const info_deikti  linfo)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Grafei stin eksodo ola ta stoixeia tis listas */
    typos_deikti temp;

    if(linfo==NULL)
    { printf("\nDen uparxei lista  gia na ektypothoun ta periexomena ths listas !\n");
    }
    else {
        temp=linfo->arxi;
        if(linfo->arxi == NULL)
        {   printf("\nH lista einai kenh!\n");
        }
        else{
            printf("\nEktypwsh twn periexomenwn ths listas!\n");
            do
            {   printf("-->%s ",temp->onoma);
                temp=temp->epomenos;
            }
            while(temp!=linfo->arxi);
        }
    }
}

void LIST_eisagogi(info_deikti * const linfo,typos_deikti prodeiktis)
{/*	Pro: 		Dhmiourgia listas
  * Meta: 		Eisagetai to "stoixeio" meta ton "prodeikti",an einai null autos to stoixeio mpainei
                stin arxi tis listas allios mpainei meta apo ton komvo pou deixnei autos */
    int error=0;
	char stoixeio[MAX_ONOMATOS];
	if((*linfo)==NULL)
    { printf("\nDen uparxei lista  gia na eisaxthei stoixeio!\n");
    }
    else{
        fputs("\nDwse to onoma tis epafhs gia eisagwgh : \n",stdout);
        fgets(stoixeio,MAX_ONOMATOS,stdin);
        taksinomish(linfo,&prodeiktis,stoixeio);

        if(prodeiktis==NULL)
            eisagogi_arxi(linfo, stoixeio, &error);
        else
            eisagogi_meta(linfo,stoixeio,prodeiktis, &error);
        if(error)
            printf("\nError! Adynamia desmeyshs mnhmhs(malloc)!\n");
        else{
            fputs("\nEisaxthei h epafh me onoma : ",stdout);
            puts(stoixeio);
        }

    }
}

void eisagogi_arxi(info_deikti *  const linfo,TStoixeioyListas *stoixeio, int *error)
{/*	Pro: 		Dhmiourgia listas
  *	Meta: 		O kombos me ta dedomena stoixeio exei eisax8ei sthn arxh ths listas */
	typos_deikti prosorinos,temp; /*Deixnei ton neo kombo pou prokeitai na eisax8ei*/
	prosorinos = malloc(sizeof(typos_komvou));
	if ( prosorinos == NULL )
	{   *error=1;
	}
	else{
        if((*linfo)->arxi == NULL){
            strcpy(prosorinos->onoma, stoixeio);
            prosorinos->epomenos = prosorinos;
            prosorinos->proigoumenos = prosorinos;
        }
        else{
            strcpy(prosorinos->onoma, stoixeio);
            LIST_last(*linfo, &temp);
            prosorinos->epomenos = (*linfo)->arxi;
            prosorinos->proigoumenos=temp;
            temp->epomenos = prosorinos;
        }
        if ((*linfo)->arxi != NULL)
            (*linfo)->arxi->proigoumenos = prosorinos;
        (*linfo)->arxi = prosorinos;
        (*linfo)->size ++;
        prosorinos->tilefwna=NULL;
	}
}

void eisagogi_meta(info_deikti *  const linfo,TStoixeioyListas *stoixeio,
					typos_deikti prodeiktis, int *error)
{ /* Pro: 		Dhmioyrgia listas
   * Meta: 		O kombos me ta dedomena stoixeio eisagetai
   *			meta ton kombo pou deixnei o prodeikths*/

	typos_deikti prosorinos; /*Deixnei ton neo kombo pou prokeitai na eisax8ei*/

	prosorinos = malloc(sizeof(typos_komvou));
	if ( prosorinos == NULL )
	{   *error = 1;

	}
	else
	{   strcpy(prosorinos->onoma, stoixeio);
		prosorinos->epomenos = prodeiktis->epomenos;
		prosorinos->proigoumenos = prodeiktis;
		if(prosorinos->epomenos!=NULL)
			prosorinos->epomenos->proigoumenos = prosorinos;
		prodeiktis->epomenos = prosorinos;
		(*linfo)->size ++;
		prosorinos->tilefwna=NULL;
	}
}

void LIST_diagrafi(info_deikti * const linfo, typos_deikti *deiktis)
{/*	Pro: 		Dhmiourgia Listas
  *	Meta: 		Diagrafetai to stoixeio ths listas pou deixnei o "deiktis" */

    typos_deikti prosorinos,previous,temp;
	char ch;
    if((*linfo)==NULL)
    { printf("\nDen uparxei lista  gia na diagrafoun ta onomata ths listas !\n");

    }
    else {
        if ((*linfo)->arxi == NULL|| (*deiktis==NULL))
        {   printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
        }
        else{
            printf("\nEiste sigouroi pws theletai na diagrafei o : \n %s ",(*deiktis)->onoma);
            printf("me ola ta noumera tou?[y,n]\n");
            scanf("%c",&ch);
            if((ch=='y')||(ch=='Y')){
                if((*linfo)->arxi==*deiktis)  //an einai o protos kombos tis listas
                {    LIST_last(*linfo, &temp);
                     prosorinos=*deiktis;
                    *deiktis=prosorinos->epomenos;
                    (*linfo)->arxi=prosorinos->epomenos;
                    (*linfo)->arxi->proigoumenos=temp;
                    temp->epomenos=(*linfo)->arxi;
                    free(prosorinos);
                    prosorinos=NULL;
                }
                else        //se kathe alli periptosi
                {   prosorinos=*deiktis;
                    previous=prosorinos->proigoumenos;
                    *deiktis=prosorinos->epomenos;
                    previous->epomenos=prosorinos->epomenos;
                    if((*deiktis)!=NULL)
                        (*deiktis)->proigoumenos = previous;
                    free(prosorinos);
                    prosorinos = NULL;
                }
            (*linfo)->size--;
             printf("\nDiagrafhke o kombos pou edeixne o dromeas!\n");
            }
        }
    }
}

void LIST_epomenos( info_deikti  const linfo, typos_deikti * const p)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Epistrefei ton epomeno komvo tou "p" kai sto error 0,an o p einai null tote epistrefei
                sto error 2 allios an den iparxei epomenos epistrefei sto error 1 */
    if(linfo==NULL)
    { printf("\nDen uparxei lista  gia na paei o kersoras stin proigoumeni thesi tis !\n");

    }
    else{
        if((*p)!=NULL){
            *p=(*p)->epomenos;
            printf("\nO dromeas metakinh8hke sthn epafh %s\n",(*p)->onoma);

        }
        else
            printf("\nError o deikths einai null!\n");


    }

}

void LIST_proigoymenos(const info_deikti linfo, typos_deikti * const p)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Epistrefei ton prohgoumeno komvo tou "p" kai sto error 0,an o p einai null tote epistrefei
                sto error 2 allios an o p einai o protos komvos tis listas epistrefei sto error 1 */
    if(linfo==NULL)
    { printf("\nDen uparxei lista  gia na paei o kersoras stin proigoumeni thesi tis !\n");

    }
    else{
        if((*p)!=NULL){
            *p=(*p)->proigoumenos;
            printf("\nO dromeas metakinh8hke sthn epafh %s\n",(*p)->onoma);
        }
        else
            printf("\nError o deikths einai null!\n");
    }

}

void LIST_first(info_deikti  const linfo, typos_deikti * const first)
{ /*Pro: 		Dhmiourgia Listas
   *Meta:		Epistrefei ton  proto komvo ths listas diaforetika epistrefei 1 sto error */
    if(linfo==NULL)
    { printf("\nDen uparxei lista  gia na paei o kersoras stin proti thesi tis !\n");

    }
    else{
	*first=linfo->arxi;
	if(linfo->arxi == NULL)
        printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
    else
        printf("\nO dromeas deixnei ston prwto kombo ths listas %s\n",(*first)->onoma);
    }

}

void LIST_last(info_deikti  const linfo, typos_deikti * const last)
{/*	Pro: 		Dhmiourgia listas
  *	Meta:		Epistrefei ton  teleutaio komvo ths listas diaforetika 1 sto error an einai kenh auti */
    if(linfo==NULL)
    { printf("\nDen uparxei lista  gia na paei o kersoras stin proti thesi tis !\n");

    }
    else{
	typos_deikti prosorinos;
	*last=NULL;
	if(linfo->arxi == NULL)
        printf("\nError! O deikths einai NULL 'h h lista einai kenh!\n");
	else
	{   prosorinos=linfo->arxi;
	    while (prosorinos->epomenos != linfo->arxi){
			prosorinos=prosorinos->epomenos;

	    }
		*last=prosorinos;
		 printf("\nO dromeas deixnei ston teleytaio kombo ths listas %s\n",(*last)->onoma);
	}
    }
}

void LIST_anazitisi(info_deikti  const linfo,typos_deikti *prodeiktis)
{
	TStoixeioyListas stoixeio[MAX_ONOMATOS];
	typos_deikti trexon;
	int vrethike;


	if(linfo==NULL)
    { printf("\nDen uparxei lista  gia na anazithithei stoixeio ths  !\n");
    }
    else{
        fputs("\nDwse to onoma tis epafhs gia anazhthsh : \n",stdout);
        fgets(stoixeio,MAX_ONOMATOS,stdin);
        trexon = linfo->arxi;
        *prodeiktis = NULL;
        vrethike = 0;
        do
        {
            if (strcmp(trexon->onoma,stoixeio)==0) //an vrethei to stoixeio
                vrethike =1;
            else
            {   *prodeiktis = trexon;
                trexon=(trexon)->epomenos;
            }
        } while ( (!(vrethike)) && (trexon!=linfo->arxi));
        if(vrethike)
            printf("\nTo onoma bre8hke!\n");
        else
            printf("\nTo onoma DEN bre8hke!\n");
    }
}


void taksinomish(info_deikti * const linfo,typos_deikti *prodeiktis,TStoixeioyListas * stoixeio){
    typos_deikti temp;
    int i=0;

    if((*linfo)->arxi!=NULL){
        temp=(*linfo)->arxi;
        do
        {   if (strcmp(temp->onoma,stoixeio) < 0){
                *prodeiktis = temp;
                temp=temp->epomenos;
                i++;
            }
            else
                break;

        }
        while(temp!=(*linfo)->arxi);



    }

}



///////////////////////////////////////////////////////////////////////
////     SYNARTHSEIS GIA THN SUNDESH EPAFWN KAI THLEFWNWN          ////
//////////////////////////////////////////////////////////////////////




void eisagwfh_thlefwnou_epafhs(const info_deikti  linfo,typos_deikti *current){
    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na dhmiourghthei lista thlefwnwn !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na dhmiourghthei lista thlefwnwn !\n");
    }
    else if((*current)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
        LIST_eisagogi_tilefwna(&(*current)->tilefwna);
    }
}
void dhmiourgia_listas_thlefwnwn(const info_deikti linfo,typos_deikti * const p){
    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na eisaxthoun thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na eisaxthoun thlefwna !\n");
    }
    else if((*p)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
        if((*p)->tilefwna==NULL)
            ((*p)->tilefwna)=LIST_dimiourgia_thlefwna();
        else
            printf("\nYparxei hdh dhmiourghmenh lista tilefwnwn\n");
    }

}
void elenxos_kenis_listas_thlefwnwn(const info_deikti linfo,const typos_deikti p){
    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na eisaxthoun thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na eisaxthoun thlefwna !\n");
    }
    else if((p)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
        LIST_keni_tilefwna((p)->tilefwna);
    }
}

 void diadromh_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current)
 {
     if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na ektupwthoun thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na ektupwthoun thlefwna !\n");
    }
    else if((*current)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
         LIST_diadromi_tilefwna(&(*current)->tilefwna);
    }
 }

void epomenos_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current){
    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na ektupwthoun thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na ektupwthoun thlefwna !\n");
    }
    else if((*current)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
         LIST_epomenos_tilefwna(&(*current)->tilefwna);
    }

}

void proigoumenos_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current){
    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na ektupwthoun thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na ektupwthoun thlefwna !\n");
    }
    else if((*current)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
         LIST_proigoymenos_tilefwna(&(*current)->tilefwna);
    }

}
void allagi_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current){

    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na allaksoun ta thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na allaksoun ta thlefwna !\n");
    }
    else if((*current)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
         LIST_allagi_noumero_tilefwna(&(*current)->tilefwna);
    }
}
void allagi_tupou_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current){

    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na allaksoun ta thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na allaksoun ta thlefwna !\n");
    }
    else if((*current)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
         LIST_allagi_tupou_tilefwna(&(*current)->tilefwna);
    }

}

void diagrafh_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current){

    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na allaksoun ta thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na allaksoun ta thlefwna !\n");
    }
    else if((*current)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
         LIST_diagrafi_tilefwna(&(*current)->tilefwna);
    }

}
void katastrofh_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current){

    if((linfo)==NULL)
    {   printf("\nDen uparxei lista  epafwn gia na allaksoun ta thlefwna !\n");

    }
    else if((linfo)->arxi==NULL){
        printf("\nDen uparxoun  epafes gia na allaksoun ta thlefwna !\n");
    }
    else if((*current)==NULL)
        printf("\nO deikths epafwn den deixnei pouthena\n");
    else{
         LIST_katastrofi_tilefwna(&(*current)->tilefwna);
    }

}

