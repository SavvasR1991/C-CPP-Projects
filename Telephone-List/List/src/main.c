#include <stdio.h>
#include "Contact_List.h"

void print_options(void);

int main(void)
{   int option;
	info_deikti list;
	typos_deikti  cur;
	list=NULL;
	cur=NULL;
    FILE *inputFile;
	/*printf("\n\nFortwsh dedomenwn...........\n");
	inputFile = fopen("C:\\Users\\Rostantakia\\Desktop\\Askhsh_2\\ffffff.txt","r");
    if(inputFile == NULL){
        printf("Apotuxia fortwshs twn dedomenwn ....Telos programmatos\n\n");
        return 0;
    }
    //list=fortwsh_dedomenwn_arxeiou(inputFile);   /*!!!!!!!!!!!!!! den ekteleitai swsta.....h "kataskeuh apo to arxeio"!!!!!!!!!!!*/
   // printf("\nDedomenena fortwthikan epitixws!!!!!!\n");
	do{ print_options();
		scanf("%d", &option);
		getchar();
		switch(option)
	   {case 1:
		    list=LIST_dimiourgia();
			break;
		case 2:
            LIST_keni(list);
            break;
		case 3:
            LIST_eisagogi(&list, cur);
            break;
		case 4:
	        LIST_first(list, &cur);
            break;
		case 5:
            LIST_last(list, &cur);
            break;
		case 6:
            LIST_epomenos(list, &cur);
            break;
		case 7:
            LIST_proigoymenos(list, &cur);
            break;
		case 8:
            LIST_diagrafi(&list, &cur);
            break;
		case 9:
            LIST_diadromi(list);
            break;
		case 10:
            LIST_allagi(list,&cur);
            break;
		case 11:
            LIST_anazitisi(list, &cur);
            break;
		case 12:
            LIST_katastrofi(&list,&cur);
            list=NULL;
            break;
		case 13:
            break;
		case 14:
            dhmiourgia_listas_thlefwnwn(list,&cur);
		    break;
        case 15:
            elenxos_kenis_listas_thlefwnwn(list,cur);
		    break;
        case 16:
            eisagwfh_thlefwnou_epafhs(list,&cur);
            break;
        case 17:
            diadromh_thlefwnou_epafhs(list,&cur);
            break;
        case 18:
            epomenos_thlefwnou_epafhs(list,&cur);
            break;
        case 19:
            proigoumenos_thlefwnou_epafhs(list,&cur);
            break;
        case 20:
            allagi_thlefwnou_epafhs(list,&cur);
            break;
        case 21:
            allagi_tupou_thlefwnou_epafhs(list,&cur);
            break;
	    case 22:
            diagrafh_thlefwnou_epafhs(list,&cur);
            break;
	    case 23:
            katastrofh_thlefwnou_epafhs(list,&cur);
            break;}
	}while(option);
	return 0;
}

void print_options(void)
{  printf("\n\n1. Dhmioyrgia listas epafwn\n\
2. Elegxos gia kenh lista epafwn\n\
3. Eisagwgh onomatos sth lista epafwn\n\
4. Metakinhsh toy dromea ston prwto kombo ths listas epafwn\n\
5. Metakinhsh toy dromea ston teleytaio kombo ths listas epafwn\n\
6. Metakinhsh toy dromea ston epomeno kombo sth lista epafwn\n\
7. Metakinhsh toy dromea ston prohgoymeno kombo sth lista epafwn\n\
8. Diagrafh epafhs apo th lista epafwn\n\
9. Diadromh oloklhrhs ths listas kai ektypwsh twn epafwn\n\
10.Allagh toy onomatos ths epafhs poy deixnei o dromeas\n\
11.Anazhthsh onomatos sth lista epafwn\n\
12.Katastrofh ths listas epafwn kai thlefwnwn\n\
13.\n\
14.Dhmioyrgia listas thlefwnwn\n\
15.Elengos gia kenh lista thlefwnwn\n\
16.Eisagwgh thlefwnoy sthn epafh\n\
17.Diadromh oloklhrhs ths listas kai ektupwsh thlefwnwn\n\
18.Metakinhsh toy dromea ston epomeno kombo sth lista thlefwnwn\n\
19.Metakinhsh toy dromea ston proigoumeno kombo sth lista thlefwnwn\n\
20.Allagh tou noumerou ths epafhs poy deixnei o dromeas\n\
21.Allagh toy tupou thlefwnou ths epafhs poy deixnei o dromeas\n\
22.Diagrafh thlefwnoy apo th lista thlefwnwn\n\
23.Katastrofh ths listas thlefwnwn\n\n\
Dwste thn epilogh sas(1-23, 0 gia eksodo):");
}
