/*///////////////////////////////////////////////////////
// SUNARTHSH EURESHS MEGISTOU STOIXEIO TRIWN STOIXEIWN //
///////////////////////////////////////////////////////*/


int max(int a,int b,int c){
    int current;
    if(a>=b){
        current=a;
        if(c>=a)
            current=c;
    }
    else
        if(b>=c)
            current=b;
        else
            current=c;
    return current;
}


