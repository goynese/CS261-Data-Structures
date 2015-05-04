/*	stack.c: Stack application. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
    DynArr *c = newDynArr(8);
    char i = nextChar(s);
    while(i!= '\0')
    {
    if(i == '{' || i == '(' || i == '[')
    pushDynArr(c, i);

    if(i == '}' || i == ')' || i == ']')
    {
        if(isEmptyDynArr(c))
            return 0;

        popDynArr(c);

    }
    i = nextChar(s);
    }
    if(isEmptyDynArr(c))
    return 1;

	return 0;
}

int main(int argc, char* argv[]){

    assert(argv != 0);

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}

/*
int main()
{
    DynArr *a = newDynArr(100);



    // Here I testest all my functions.


    addDynArr(a,'e');
    addDynArr(a,'e');
    addDynArr(a,'e');

    printf("%d\n", sizeDynArr(a));


    printf("%c\n", getDynArr(a, 0));


    printf("%d\n", sizeDynArr(a));


    putDynArr(a, 1, 's');
    printf("%c\n", getDynArr(a, 1));
    putDynArr(a,0, 'f');
    printf("%c\n", getDynArr(a, 0));

    swapDynArr(a, 0, 1);

    printf("The size is %d\n", sizeDynArr(a));

    removeAtDynArr(a, 0);
    printf("%c\n", getDynArr(a, 1));
    printf("%c\n", getDynArr(a, 0));
    pushDynArr(a, 'e');
    pushDynArr(a, 'd');
    pushDynArr(a, 'd');
    pushDynArr(a, 'i');
    pushDynArr(a, 'e');
    printf("The size is %d\n", sizeDynArr(a));

    printf("%c\n" , topDynArr(a));
    popDynArr(a);

    printf("The size is %d\n", sizeDynArr(a));
    printf("%c\n" , topDynArr(a));

    printf("The size is %d\n", sizeDynArr(a));

    printf("%d\n", containsDynArr(a, 'i'));
    removeDynArr(a, 'i');
    printf("%d\n", containsDynArr(a, 'i'));

    printf("The size of the synamic array is %d after removal\n", sizeDynArr(a));

    printf("The dynamic array is empty %d\n", isEmptyDynArr(a));




    deleteDynArr(a);


    return 0;
}
*/
