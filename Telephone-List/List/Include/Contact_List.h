#ifndef CONTACT_LIST
#define CONTACT_LIST
#define MAX_ONOMATOS 25
#define MAX_NOUMERO 15

typedef char TStoixeioyListas;


typedef struct info_node_thlefwna  * typos_deikti_tilefwna_info;
typedef struct lista_tilefwnwn *typos_deikti_tilefwna;
typedef struct info_node  * info_deikti;
typedef struct typos_komvou *typos_deikti;
typedef char typos_stoixeiou;
/*dhlwseis synarthsewn*/



/*dhmioyrgia/katastrofi listas*/
info_deikti LIST_dimiourgia();
info_deikti fortwsh_dedomenwn_arxeiou(FILE *from);
void LIST_katastrofi(info_deikti * linfo,typos_deikti *current);
void LIST_keni(const info_deikti  linfo);
void LIST_allagi(const info_deikti  linfo, typos_deikti * const p);
void LIST_diadromi(const info_deikti  linfo);
void LIST_eisagogi(info_deikti * const linfo,typos_deikti prodeiktis);
void LIST_diagrafi(info_deikti * const linfo, typos_deikti *deiktis);
void eisagogi_arxi(info_deikti * const,TStoixeioyListas * onoma_epafis, int *);
void eisagogi_meta(info_deikti *  const,TStoixeioyListas * onoma_epafis, typos_deikti, int *);
void LIST_epomenos(const info_deikti  linfo, typos_deikti * const p);
void LIST_proigoymenos(const info_deikti linfo, typos_deikti * const p);
void LIST_first(const info_deikti  linfo, typos_deikti * const first);
void LIST_last(const info_deikti  linfo, typos_deikti * const last);
void LIST_anazitisi(const info_deikti  linfo,typos_deikti *prodeiktis);
void taksinomish(info_deikti * const linfo,typos_deikti *prodeiktis,TStoixeioyListas * onoma_epafis);



void eisagwfh_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current);
void diadromh_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current);
void dhmiourgia_listas_thlefwnwn(const info_deikti linfo,typos_deikti * const p);
void elenxos_kenis_listas_thlefwnwn(const info_deikti linfo,const typos_deikti);
void epomenos_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current);
void allagi_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current);
void allagi_tupou_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current);
void diagrafh_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current);
void katastrofh_thlefwnou_epafhs(const info_deikti linfo,typos_deikti *current);




typos_deikti_tilefwna_info LIST_dimiourgia_thlefwna( );
void LIST_keni_tilefwna(const typos_deikti_tilefwna_info );
void LIST_eisagogi_tilefwna(typos_deikti_tilefwna_info * const  );
void eisagogi_arxi_tilefwna(typos_deikti_tilefwna_info *  const linfo,TStoixeioyListas *thlefwno,char kathgoria, int *);
void LIST_diadromi_tilefwna(const typos_deikti_tilefwna_info *linfo);
void LIST_epomenos_tilefwna(typos_deikti_tilefwna_info *  const linfo);
void LIST_proigoymenos_tilefwna(typos_deikti_tilefwna_info *  const linfo);
void LIST_allagi_noumero_tilefwna(typos_deikti_tilefwna_info *  const linfo);
void LIST_allagi_tupou_tilefwna(typos_deikti_tilefwna_info *  const linfo);
void LIST_diagrafi_tilefwna(typos_deikti_tilefwna_info *  const linfo);
void LIST_katastrofi_tilefwna(typos_deikti_tilefwna_info *  const linfo);


#endif /*#ifndef __POINTER__LIST_ */
