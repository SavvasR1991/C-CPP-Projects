#include<stdio.h>                       

int main(void){
	int k,num=0,apotelesma=0,praksi=0,ath=0,ken=0,lathos=1; 
        int flag1=1,flag2=1,flag3=0;                       
	int met1=0,met2=0,met3=1,met=0;                    
	printf("-> To exit the programm press ctrl + D \n");
	while((k=getchar())!=EOF){               /*Run until EOF */
	    if(flag3==0&&(k=='+'||k=='-')){      /*Check for first input operator ex.+23-2 h -5+33-2*/
		flag1=0;              /*if flag3=0 input number and k is operator (+ or -) then lathos=2*/
		lathos=2;
	    }
	    if(k>='0'&&k<='9'){      /*case 1:if k is number calculate num*/
		num=num*10;          /*multiply with 10 ex.for 24 num=0->num=50-48+0=2,num=20->num=52-48+20=24*/
		if(k!=10){
		    num=k-48+num;    /*ancii k ,decimal number creation*/
		}
		met1=0;              /*+ counter for errors (++..+),ex.if met1 = 2 then input-> ++ etc*/
		met2=0;              /*- counter for errors (--..-),ex.if met2 = 2 then input-> -- etc*/
		flag3=1;             /*at least one numbers*/
		if(ken==1)           /*Space check (ex. 8 8+4-2)*/
		    met3++;          /*met3++ error  */
	    }
	    else if((((k>='!')&&(k<=')'))||((k>=':')&&(k<='~'))||(k==','||k=='.'||k=='/'||k=='*'))&&flag1==1){ /*Character check */
		flag1=0;
		lathos=1;
	    }
	    if((k==' '||k=='\t')&&met3==1&&flag3==1){     /*end of input ken=1*/
		ken=1;                         
	    }
	    if(met3>=2&&flag1==1) {            /*if met3!=1 space input */
		flag1=0;                       
		lathos=3;
	    }
	    if((k=='+'||k=='\n')&&flag1==1){   /*Addition case*/
		met1++;
		if(praksi==0){                 /*first number input */
		    apotelesma=num;
		praksi=1;}                     
		else{
		    if(praksi==1)
		        apotelesma=apotelesma+num;     /*Addition */
		    else if(praksi==2)                 /*Substruction */
		        apotelesma=apotelesma-num;     
		}
		num=0;                 /*next number */
		praksi=1;              /*reset */
		ken=0;                 /*arxikopoihsh metablitwn pou xreiazontai gia tin periptwsi lathous kenou anamese se num(lathos=3)*/
		met3=1;
		flag3=0;  }
	    if((k=='-'||k=='\n')&&flag1==1){     
		met2++;                          /*Error check (--)*/
		if(praksi==0){                   
		    apotelesma=num;
		    praksi=1;}                   
		else{
		    if(praksi==1)
		        apotelesma=apotelesma+num;   /*an praksi=1  kane tin prosthesi */
		    else if(praksi==2)               /*an i praksi mpei me tin timi 2(aferesis) tote praksi praksi afairesis */
		        apotelesma=apotelesma-num;   /*kane tin afairesi */
		}
		num=0;         /*reset number */
		praksi=2;      
		ken=0;         
		met3=1;
		flag3=0; }
	    if(met2==1&&met1==1&&flag1==1){    /*Error check +- or -+*/
		ath++;                        
		if(ath>=2)                     /*Error check +- or -+*/
		    flag2=0;
	    }
	    if(((met1>=2||met2>=2)||(flag2==0))&&flag1==1){   /*Error case ++..+,--..- and  +-*/
		flag1=0;
		lathos=2;}
	    if(k=='\n'){                    /*Next Line*/
		met++;
		if(flag1==1)                                               /*Result */
		    printf("Result %d: %d\n\n",met,apotelesma);
		if(flag1==0){                                          /*Error cases */
		    if(lathos==1)                                      /*if lathos=1 Wrong input */
		        printf("Result %d:Unknown character\n\n",met);
		    if(lathos==2)                                       /*if lathos=2 operators without numbers between p.x 3++-3+2*/
		        printf("Result %d: Missing numbers between operetors\n\n",met);
		    if(lathos==3)                                       /*if lathos=3 no operators between numbers p.x 8  8+2-11*/
		        printf("Result %d: Missing operetors between numbers\n\n",met);
		}
		apotelesma=0;                                              /*reset parameters */
		lathos=0;
		met3=1;
		met2=0;
		met1=0;
		flag1=1;
		flag2=1;
		flag3=0;
		ath=0;
		num=0;
		ken=0;
		praksi=0;
	    }

	}
    printf("\n-> End of programm \n");
}
