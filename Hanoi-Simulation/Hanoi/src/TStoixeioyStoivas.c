#include "TStoixeioyStoivas.h"

void TSstoiva_setValues (TStoixeioyStoivas *target, TStoixeioyStoivas source)
{
	*target=source;
}

/*int TSstoiva_readValue (FILE *from, TStoixeioyStoivas *ElemPtr)
{
     return fscanf(from, "%d", ElemPtr);
}*/

int TSstoiva_readValue (FILE *from, TStoixeioyStoivas *ElemPtr)
{
     return fscanf(from, "%d\t%d", &ElemPtr->aktina,&ElemPtr->ypsos);
}
/*
int TSstoiva_mikrotero(TStoixeioyStoivas left, TStoixeioyStoivas right)
{
	return left < right ;
}
*/
int TSstoiva_mikrotero(TStoixeioyStoivas left, TStoixeioyStoivas right)
{
    int result_left,result_right;
    result_left = (left.aktina)*(left.aktina)*(left.ypsos);
    result_right = (right.aktina)*(right.aktina)*(right.ypsos);
	return result_left < result_right ;
}

/*int TSstoiva_writeValue (FILE *to, TStoixeioyStoivas Elem)
{
	return fprintf(to, "%d", Elem);
}*/

int TSstoiva_writeValue (FILE *to, TStoixeioyStoivas Elem)
{
	return fprintf(to, "\n%d\t%d", Elem.aktina,Elem.ypsos);
}
