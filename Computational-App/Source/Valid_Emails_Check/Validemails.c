/*File:Validemails.c */
#include <stdio.h>                                                
main(){
    int ch,j,m,k,b,n,p,l;                                                
    unsigned d,e,u,jj,hh;                                     
    j=1;                                                         
    ch=getchar();                                                     
    printf("-> To exit the programm press ctrl + D \n");
    printf("Line %d: E-mail address \"",j);
    while(ch!=EOF){                                                 
        d=0;                                                         
        u=0;                                                         /*Check <tlevdom>  e-mail*/
        m=0;                                                         /*Check <user> error*/
        k=0;                                                         
        b=0;                                                         /*Check <dotatom>*/
        n=0;                                                         
        p=0;                                                         /*Check <tlevdom>*/
        l=0;                                                         
        jj=0;                                                        /*Check <dotatom>*/
        hh=0;                                                        /*Check <dotatom>*/
        while(ch!='\n'){                                             
            if((ch=='@')&&(k==0)&&(m!=0)){                          /*Until ch='@' and k == ERROR */
                putchar(ch);                                        
                d=1;                                                    
                break;}
            if((ch<='Z')&&(ch>='A')||(ch<='z')&&(ch>='a')||(ch<='9')&&(ch>='0') /*Check <user>*/
            ||(ch=='+')||(ch=='-')||(ch=='_')||(ch=='.')||(ch=='%')){
                m=m+1;}                                                
            else{                                                       /*Check <user>*/
                k=k+1;}                                                /*ch invalid*/
            putchar(ch);
            ch=getchar();                                                   /*next character*/
        }
        if(d==1){                                                      
            ch=getchar();                                                /*next character*/
            while(ch!='\n'){                                     
                if((ch=='.')&&(n==0)&&(b!=0)){                   /*Check <dotatom> (ch='.')  */
                    b=0;                                         
                    n=0;                                         /*Reset*/
                   jj=jj+1;}                                                     
                if(ch!='.'){                                    /*Check <dotatom> */
                  if((ch<='Z')&&(ch>='A')||(ch<='z')&&(ch>='a')||   /*valid character*/
                     (ch<='9')&&(ch>='0')||(ch=='-')){
                      b=b+1;}
                  else{
                      n=n+1;}
                }
                if(b==0){                                    
                      hh=hh+1;}
                if(hh!=jj){                                 /*if hh=jj then d true*/
                     d=0;}                                    /*dots in front of(<dotatom>)*/
                putchar(ch);
                ch=getchar();                                        /*next Char*/
                if((ch<='z')&&(ch>='a')||(ch<='Z')&&(ch>='A')){        /*check  <tlevdom>*/
                    p=p+1;}                                           /*ch valid character p++*/
                else {                                                /*Error*/
                    l=l+1;}
                if(ch=='.'){                                    /*reset p,u,l*/
                    p=0;                                        /*check for  <dotatom>*/
                    u=0;
                    l=0;}
                if((ch=='\n')&&(l==1)&&(p>=2)&&(p<=4)){   /*end of check  <dotatom> */
                    u=1;}                                   
            }                                               
        }
        if ((d==1)&&(u==1)&&(n==0)){                /*if d,u true and error counter <dotatom> zero*/
            printf("\" is valid\n\n");}                                     
        else{
            printf("\" is invalid\n\n");}                               
        ch=getchar();                                                 /*next e-mail*/
        j=j+1;                                                     /*Results*/
        printf("Line %d: E-mail address \"",j);
    }
}



