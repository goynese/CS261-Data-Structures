#include "dynArray.h"
#include <assert.h>
#include "type.h"
#include <stdlib.h>

/*Bag interface*/
/* Function to initialize bag:
	Pre: b is not null
	Post: list implementing the bag is initialized, size = 0
*/
void initBag(struct bag* b){
	assert(b != 0);	
	b->lst = (DynArr *)malloc(sizeof(DynArr));
	initDynArr(b->lst, 1000);
}

/* Function to add an element to the bag:
	Pre: b is not null
	Post: val is added to the bag ie the list implementing the bag*/
void addToBag(struct bag* b, TYPE val){
	assert(b != 0);	
	addDynArr(b->lst, val);
}

/* Function to remove an element from the bag:
	Pre: b is not null
	Post: Element (if found) removed from bag/list
*/
void removeFromBag(struct bag* b, TYPE val){
	assert(b != 0);	
	removeDynArr(b->lst, val);
}

/*Function to test if an element exists in the bag
	Pre: b is not null
*/
int bagContains(struct bag* b, TYPE val){
	assert(b != 0);	
	return containsDynArr(b->lst, val);
}

/*Function to test if the bag is empty
	Pre: b is not null
*/

int isEmptyBag(struct bag* b){
	assert(b != 0);	
	return(isEmptyDynArr(b->lst));
}
