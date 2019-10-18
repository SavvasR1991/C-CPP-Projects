#include <stdio.h>                                          
#include <time.h>                                           
#include <stdlib.h>                                         
#define COMPUTATIONS 100000                                 

int main(void)
{   int ps,n,ath,i,k,tr,ta,tb,mp;                           
    long curtime;                                           /*Time time */
    double me;                                              /*percentage*/
    me=0;                                                   
    curtime=time(NULL);                                     
    printf("-> Current time is %ld\n\n",curtime);
    srand((unsigned int)curtime);                           
    for(i=1;i<=COMPUTATIONS;i++){                          
        ta=rand();                                          
        tb=rand();                                          
        n=((ta%32768)+1)*((tb%32768)+1)+1;                  /*Check (n=[((ta mod 32768)+1)*((tb mod 32768)+1)+1])*/
        if(n%2==0||n%3==0||n%5==0||n%7==0){                 /*Ignore multiples of 2,3,5,7*/
            continue;}
        ath=0;                                              
        k=n;                                                
        while(ath!=1&&ath!=89&&ath!=4&&ath!=145&&ath!=42    /*Check: (1) if happy prime*/
                &&ath!=20&&ath!=16&&ath!=37&&ath!=58){      /*Check: (2) unhappy -> {89,145,42,20,4,16,37,58}*/
            ath=0;                                          
            while(n!=0){                                    /*Digits of number*/
                ps=n%10;                                    
                ath=ath+ps*ps;                             
                n=n/10;
	    }                                   
            n=ath;                                          /*next number*/
                }
            if(n==1){                                       /*if n=1 happy number*/
                tr=1;                                       
                mp=0;
                while(tr*tr<=k){                            
                    if(k%tr==0){                            
                        mp++;                               /*Prime number*/
                        if(mp>=3)                           /*comblex number*/
                            break;                          
                        }
                    tr++;                                   
                    }
                if(mp<2){                                   /*Prime number*/
                    printf("%11d is happy prime\n",k);       /*Results*/
                    me++;                                   
                    }
            }
    }
    printf("\n\n");
    printf(" Found %3.3f%% happy prime numbers\n\n",(me/1000));/*Results*/
    printf("\n-> End of programm \n");
    return 1;
}
