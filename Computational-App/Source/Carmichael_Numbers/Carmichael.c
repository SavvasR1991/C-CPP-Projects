/* File: carmichael.c */
#include <stdio.h>                                
#include<math.h>                                      /*Header file for math library*/
#define MAXNUM  1000000                   /*Define const for user input, max number to search*/

main(){
    int num;                     /*Variables*/
    int deix,par;
    int arit;
    unsigned int ele=0;                           /*flag */
    for(num=561;num<=MAXNUM;num=num+2){            /*Main loop for search area*/
        par=3;                                     /*initialization of par,ele,deix*/
        ele=0;
        if(num%2==0)
            continue;
        deix=num;
        while((ele==0)&&(par<=sqrt(num))){          /*Korselt theorim*/
            if (num%(par*par)==0){                    /*1st criterion Korselt, if num is square free*/
                break;}
             while((deix%par==0)&&((num-1)%(par-1)==0)){  /*2nd criterion Korsel,if num divide perfectly par,and num-1 with par-1*/
                 deix=deix/par;                           /*divide num(deix) with par */
                 if(deix==1){                             /*if num full divided and criterion Korset in action*/
                  ele=1;                                  /*check flag */
                  break;}
             }
                 par=par+2;                                    /*par +2 only even numbers*/
        }
        deix=num;                                              /*take value*/
        if(ele==1){                                          /*print number carmichael*/
            printf("\n%6d is a Carmichael number =(",num);    /*only if criterion Korselt in action*/
            par=3;
            while(par<=(sqrt(deix))){                      
                while(deix%par==0){                        
                    printf(" %d x ",par);                   
                    deix=deix/par;
                }
                par=par+2;                                  /*par + 2 */
            }
                if(deix!=1)                               
                printf(" %d )",deix);                        
        }
    }
    printf("\n-> End of programm \n");
}






