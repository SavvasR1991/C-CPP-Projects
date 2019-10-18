#ifndef __TStoixeioyStoivas_H__
#define __TStoixeioyStoivas_H__
#include <stdio.h>
#define pi 3.14159  /*den xreiazetai na to xrhshmopoihsoume afou aplopoihte sthn mathimatikh mas praksh*/

/*typedef int TStoixeioyStoivas;*/
typedef struct
{
	int aktina;
	int ypsos;
}TStoixeioyStoivas;


void TSstoiva_setValues (TStoixeioyStoivas *target, TStoixeioyStoivas source);
int TSstoiva_readValue (FILE *from,  TStoixeioyStoivas *Elem);
int TSstoiva_mikrotero(TStoixeioyStoivas left, TStoixeioyStoivas right);
int TSstoiva_writeValue (FILE *to, TStoixeioyStoivas Elem);
#endif
