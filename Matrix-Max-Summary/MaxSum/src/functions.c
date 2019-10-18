/*//////////////////////////////////
//      EPANALHPTIKH SYNARTHSH    //
//////////////////////////////////*/

void iterative (int **matr,int n,int m){
    int i,j,**sum,csum,a,b,maxsum=0,*path,cmax=0,countj;
    sum = MatrixMalloc(n,m);                     /*kalese sunarthsh dunamikhs desmeushs mnhmhs disdiastatou pinaka*/
      for (j = 0 ; j < m ; j++){                 /*arxikopoihsh pinaka sum*/
            sum[0][j]=matr[0][j];                /*h prwth grammh tou sum eina idia me authn tou matrix*/
    }
    path=MatrixMalloc(n,0);                      /*desmeush gia mono-diastato pinaka path[i]*/
    for(i=0;i<n-1;i++){                          /*mexri n-2 tha pame gt h teleutaia(n-1)grammh sumperilambanetai sta a,b!!*/
        a=i+1;                                   /* a metablhth pou deixnei stin akribws katw grammh apo authn pou eimaste*/
        for(j=0;j<m;j++){
            b=j-1;                               /*b metablhth pou deixnei sto aristero stoixeio (katw) apo auto pou eimaste*/
            if(b<0){                             /*an bgoume apo ta aristera ektos pinaka pigene stin teleutaia sthlh*/
                b=m-1;
            }
            csum=sum[i][j]+matr[a][b];           /*ypologismos a8roismatos tou merikou atroismastos me tin katw aristera timh tou pinaka matr*/
            if(sum[a][b]<=csum){                 /*an h csum einai megalhterh apo to proigoumeno upologismeno meriko a8roisma antikatesthse tin*/
                sum[a][b]=csum;
            }
            b=j+1;                               /*b metablhth pou deixnei sto deksio stoixeio (katw) apo auto pou eimaste*/
            if(b>m-1)                            /*an bgoume apo ta deksia ektos pinaka pigene stin prwth sthlh*/
                b=0;
            csum=sum[i][j]+matr[a][b];           /*ypologismos a8roismatos tou merikou atroismastos me tin katw deksia timh tou pinaka matr*/
            if(sum[a][b]<=csum){                 /*an h csum einai megalhterh apo to proigoumeno upologismeno meriko a8roisma antikatesthse tin*/
                sum[a][b]=csum;
            }
            b=j;                                 /*b metablhth pou deixnei sto stoixeio (katw) apo auto pou eimaste*/
            csum=sum[i][j]+matr[a][b];           /*ypologismos a8roismatos tou merikou atroismastos me tin apo katw timh tou pinaka matr*/
            if(sum[a][b]<=csum){                 /*an h csum einai megalhterh apo to proigoumeno upologismeno meriko a8roisma antikatesthse tin*/
                sum[a][b]=csum;}
        }
    }
    for(j=0;j<m;j++){                            /*ypologimos megistou a8roismatos*/
        if(sum[n-1][j]>maxsum) {                 /*sugkrine ta stoixeia tis teleutaias grammhs kai bres to megalutero */
            maxsum=sum[n-1][j];
            countj=j;}                           /*krata thn sthlh tou megaluterou a8roismatos*/
    }
    printf("Max sum in %d\n",maxsum);            /*ektupwse megisto athroisma*/
    path[0]=matr[n-1][countj];                   /*to teleutaio stoixeio tou megistou monopatiou*/
    for (i = n-1 ; i > 0 ; i--) {                /*psakse anapoda to megisto monopati*/
          cmax=sum[i][countj]-matr[i][countj];   /*diafora merikou athroismatos me thn antistoixh timh*/
          b=countj-1;                            /*phgaine panw deksia apo to shmeio pou eimaste*/
          if(b<0)                                /* an bgoume ektos phgaine stn teleutaia sthlh*/
                b=m-1;
          if(sum[i-1][b]==cmax){                 /*sugkrine thn diafora me to antistoixo meriko a8roisma*/
                countj=b;                        /*an tautizontai eimaste sto epomeno psifio tou max monopatiou*/
                path[n-i]=matr[i-1][b];}         /*krata thn sthlh gia ton epomeno elenxo*/
          b=countj+1;                            /*phgaine panw aristera apo to shmeio pou eimaste*/
          if(b>m-1)                              /* an bgoume ektos phgaine stn prwth sthlh*/
                b=0;
          if(sum[i-1][b]==cmax){                 /*sugkrine thn diafora me to antistoixo meriko a8roisma*/
                countj=b;                        /*an tautizontai eimaste sto epomeno psifio tou max monopatiou*/
                path[n-i]=matr[i-1][b];}
          b=countj;                              /*phgaine panw apo to shmeio pou eimaste*/
          if(sum[i-1][b]==cmax){                 /*sugkrine thn diafora me to antistoixo meriko a8roisma*/
                countj=b;                        /*an tautizontai eimaste sto epomeno psifio tou max monopatiou*/
                path[n-i]=matr[i-1][b]; }        /*krata thn sthlh gia ton epomeno elenxo*/
    }
    for(i=n-1;i>0;i--)                           /*ektupwse to megisto monopati*/
        printf("%d -> ",path[i]);
    printf("%d\n",path[0]);                      /*ksexwrista to teleutaio stoixeio gia na mn teleiwsoume me "->"*/
    for (i = 0 ; i < n ; i++)                    /*apodesmush mnhmhs*/
      free(sum[i]);
    free(sum);
}

/*/////////////////////////////////////
// ANADRIMIKH SYNARTHSH XWRIS PINAKA //
/////////////////////////////////////*/

int pureRecursive (int **matr,int n,int m,int i,int j){
    int sa,sb,sc,sd,se,sf,sg,sh,si;               /*dhlwseis metablhtwn gia na perastoun sthn max*/
    if(i>=n-1)                                    /*otan ftasoume sthn teleutaia grammh tou pinaka matr*/
        return matr[i][j];                        /*epestrepse ta a(i,j) (prwth sunthikh ,i=n)*/
    else{
        if(j==0){                                 /*an isxuei i deuterh sunthhkh j=0(prwth sthlh)*/
            sa=pureRecursive(matr,n,m,i+1,m-1);   /*eimaste ektos(aristera) tou pinaka phgaine sth m-1 sthlh*/
            sb=pureRecursive(matr,n,m,i+1,0);     /*elenkse to apo katw stoixeio apo auto pou eimaste*/
            sc=pureRecursive(matr,n,m,i+1,1);     /*elenkse to apo katw deksia stoixeio apo auto pou eimaste*/
            return matr[i][j]+max(sa,sb,sc);      /*epestepse to megisto apo ta apotelesmata twn anadromikwn klhsewn*/

        }                                         /*kai prosthese to me to antistoixo stoixeio(kai upologise to antistoixo meriko a8roisma)*/
        else if(j==m-1){                          /*an isxuei i tetarth sunthhkh j=m-1(teleutaia sthlh)*/
            sd=pureRecursive(matr,n,m,i+1,m-2);   /*elenkse to apo katw aristera stoixeio apo auto pou eimaste*/
            se=pureRecursive(matr,n,m,i+1,m-1);   /*elenkse to apo katw stoixeio apo auto pou eimaste*/
            sf=pureRecursive(matr,n,m,i+1,0);     /*eimaste ektos(deksia) tou pinaka phgaine sth 0 sthlh*/
            return matr[i][j]+max(sd,se,sf);      /*epestepse to megisto apo ta apotelesmata twn anadromikwn klhsewn*/
        }
        else{                                     /*an isxuei i trith sunthhkh 0<j<m-1(teleutaia sthlh)*/
            sg=pureRecursive(matr,n,m,i+1,j-1);   /*elenkse to apo katw aristera stoixeio apo auto pou eimaste*/
            sh=pureRecursive(matr,n,m,i+1,j);     /*elenkse to apo katw stoixeio apo auto pou eimaste*/
            si=pureRecursive(matr,n,m,i+1,j+1);   /*elenkse to apo katw deksia stoixeio apo auto pou eimaste*/
            return matr[i][j]+max(sg,sh,si);      /*epestepse to megisto apo ta apotelesmata twn anadromikwn klhsewn*/
        }                                         /*kai prosthese to me to antistoixo stoixeio(kai upologise to antistoixo meriko a8roisma)*/
    }
}


/*////////////////////////////////////
//  ANADRIMIKH SYNARTHSH ME PINAKA  //
////////////////////////////////////*/

int matrRecursuve(int **matr,int n,int m,int i,int j,int **sum){
    int sa,sb,sc,sd,se,sf,sg,sh,si;
        if(i>=n-1){     /*otan ftasoume sthn teleutaia grammh tou pinaka matr*/
            return matr[i][j];/*epestrepse ta a(i,j) (prwth sunthikh ,i=n)*/
        }
        else{
            if(j==0){
                if(sum[i][j]==-1){ /*an o pinakas merikwn a8roismatwn sto sugkekrimenw stoixeio einai adeios*/
                    if(i==0)
                        sum[0][j]=matr[0][j];
                    sa=matrRecursuve(matr,n,m,i+1,m-1,sum); /*eimaste ektos(aristera) tou pinaka phgaine sth m-1 sthlh*/
            		sb=matrRecursuve(matr,n,m,i+1,0,sum);   /*elenkse to apo katw stoixeio apo auto pou eimaste*/
            		sc=matrRecursuve(matr,n,m,i+1,1,sum);/*elenkse to apo katw deksia stoixeio apo auto pou eimaste*/
                    sum[i][j]=max(sa,sb,sc);  /*epestepse to megisto apo ta apotelesmata twn anadromikwn klhsewn*/
                }
            return matr[i][j]+sum[i][j]; /*epestrepse to meriko max a8roisma prosthemeno me to antistoixo stoixeio*/
            }
            else if(j==m-1){
                if(sum[i][j]==-1){/*an o pinakas merikwn a8roismatwn sto sugkekrimenw stoixeio einai adeios*/
                    if(i==0)
                        sum[0][j]=matr[0][j];
            		sd=matrRecursuve(matr,n,m,i+1,m-2,sum);  /*elenkse to apo katw aristera stoixeio apo auto pou eimaste*/
            		se=matrRecursuve(matr,n,m,i+1,m-1,sum);/*elenkse to apo katw stoixeio apo auto pou eimaste*/
            		sf=matrRecursuve(matr,n,m,i+1,0,sum);/*elenkse to apo katw deksia stoixeio apo auto pou eimaste*/
                    sum[i][j]=max(sd,se,sf);  /*epestepse to megisto apo ta apotelesmata twn anadromikwn klhsewn*/
                }
            return matr[i][j]+sum[i][j];/*epestrepse to meriko max a8roisma prosthemeno me to antistoixo stoixeio*/
            }
            else{
                if(sum[i][j]==-1){/*an o pinakas merikwn a8roismatwn sto sugkekrimenw stoixeio einai adeios*/
                    if(i==0)
                        sum[0][j]=matr[0][j];
                    sg=matrRecursuve(matr,n,m,i+1,j-1,sum); /*elenkse to apo katw aristera stoixeio apo auto pou eimaste*/
            		sh=matrRecursuve(matr,n,m,i+1,j,sum);/*elenkse to apo katw stoixeio apo auto pou eimaste*/
            		si=matrRecursuve(matr,n,m,i+1,j+1,sum);/*elenkse to apo katw deksia stoixeio apo auto pou eimaste*/
                    sum[i][j]=max(sg,sh,si);  /*epestepse to megisto apo ta apotelesmata twn anadromikwn klhsewn*/
                }
            return matr[i][j]+sum[i][j];/*epestrepse to meriko max a8roisma prosthemeno me to antistoixo stoixeio*/
            }
        }
}
