#include <stdio.h>
#include "bst.h"
#include "assert.h"
#include "structs.h"
#include "type.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.
 
 if left < right return -1
 if left > right return 1
 if left = right return 0
 */
 
 /*Define this function type casting the value of void * to the desired type*/
int compare(TYPE left, TYPE right)
{
	struct data *l = (struct data*)left;
	struct data *r = (struct data*)right;

	if(l->number < r->number)
		return -1;
	if(l->number > r->number)
		return 1;
	return 0;
	
}

/*Define this function type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
	struct data *temp = (struct data*)curval;
	printf("%d", temp->number);
}


