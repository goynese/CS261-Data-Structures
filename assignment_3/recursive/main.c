#include "listbag.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	struct bag* b = (struct bag*)malloc(sizeof(struct bag));/*Create new bag*/
	initBag(b);/*Initialize*/
	int i;
	for( i = 0 ; i < 20; i++)
		addToBag(b, (TYPE)i);/*Add elements*/
        _printList(b->lst);
        if( bagContains( b, (TYPE) 5.0))
	  printf("The bag contains 5.0 \n");
        else
          printf("The bag doesn't contain 5 \n");
        int j;
        for(j=0;j<20;j++)
	    removeFromBag( b, (TYPE) j);
		_printList(b->lst);
		printf("\n %d \n", b->lst->size);
		_printList(b->lst);
        printf("After removing: \n");
        if(isEmptyBag(b))
	  printf("The bag is empty. \n");
        else
          printf("The bag is not empty. \n");
		 _printList(b->lst);
		 printf("\n %d \n", b->lst->size);
		getchar();
	return 0;
}
