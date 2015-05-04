#include "listbag.h"
#include "type.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/*
	function to initialize the list, set the sentinels and set the size
	param lst the list
	pre: lst is not null
	post: lst size is 0
*/

void initList (struct list *lst) {
	assert(lst !=0);
 	lst->head = (struct DLink *)malloc(sizeof(struct DLink));
	assert(lst->head);
	lst->tail = (struct DLink *)malloc(sizeof(struct DLink));
	assert(lst->tail);

	lst->head->next = lst->tail;
	lst->tail->prev = lst->head;
	lst->tail->next = 0;

	lst->size = 0;
}


/*
	_addLink
	Funtion to add a value v to the list before the link l
	param: lst the list
	param: lnk the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: lnk is not null
	post: lst is not empty
*/

void _addLink(struct list *lst, struct DLink *lnk, TYPE v)
{
	assert(lst != 0 && lnk != 0);
	struct DLink *newlink = (struct DLink *)malloc(sizeof(struct DLink));
	assert(lst != 0);

	newlink->value = v;
	newlink->next = lnk;
	newlink->prev = lnk->prev;
	lnk->prev->next = newlink;
	lnk->prev = newlink;

	lst->size++;
}

/*
	addFrontList
	Function to add a value to the front of the list, can use _addLink()
	param: lst the list
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct list *lst, TYPE e)
{	
	assert(lst != 0);
	struct DLink *newlink = (struct DLink *)malloc(sizeof(struct DLink));
	assert(newlink != 0);

	_addLink(lst, lst->head->next , e);
}

/*
	addBackList
	Function to add a value to the back of the list, can use _addlink()
	param: lst the list
	pre: lst is not null
	post: lst is not empty
*/

void addBackList(struct list *lst, TYPE e) {
	assert(lst != 0);

	_addLink(lst, lst->tail , e);

}

/*
	frontList
	function to return the element in the front of the  list
	param: lst the list
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct list *lst) {
	assert(lst != 0);
	if(lst->size != 0)
		return lst->head->next->value;
	return 0;
}

/*
	backList
	function to return the element in the back of the  list
	param: lst the list
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct list *lst)
{
	assert(lst != 0);
	if(lst->size != 0)
		return lst->tail->prev->value;
	return 0;
}

/*
	_removeLink
	Function to remove a given link
	param: lst the list
	param: lnk the linke to be removed
	pre: lst is not null
	pre: lnk is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct list *lst, struct DLink *lnk)
{
	assert(lst != 0);
	assert(lnk != 0);

	lnk->next->prev = lnk->prev;
	lnk->prev->next = lnk->next;
	free(lnk);

	lst->size--;
}

/*
	removeFrontList
	Function to remove element from front of list, can use _removelink()
	param: lst the list
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct list *lst) {
	assert(lst != 0);
	if(lst != 0)
		_removeLink(lst, lst->head->next);
}

/*
	removeBackList
	Function to remove element from back of list, can use _removelink()
	param: lst the list
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct list *lst)
{
	assert(lst != 0);
	if(lst != 0)
		_removeLink(lst, lst->tail->prev);
}

/*
	isEmptyList
	param: q the list
	pre: q is not null
	post: none
*/

int isEmptyList(struct list *lst) {
	assert(lst != 0);
	return !lst;
}

/* Function to print list
   Pre: lst is not null
*/
void _printList(struct list* lst)
{
	assert(lst != 0);
	struct DLink *current = (struct DLink *)malloc(sizeof(struct DLink));
	current = lst->head->next;

	
	while(current->next->next != 0)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

/* Iterative implementation of contains()
	Function to find if a given value belongs in the list
   Pre: lst is not null
*/
int listContains (struct list *lst, TYPE e) {

	assert(lst != 0);
	struct DLink *current = lst->head->next;

	while(current != lst->tail)
	{
		if(EQ(current->value, e))
			return 1;
		current = current->next;
	}
	return 0;
}

/* Iterative implementation of remove()
	Function to remove a given value from the list
   Pre: lst is not null
*/
void listRemove (struct list *lst, TYPE e) {
	assert(lst != 0);

	if(listContains(lst, e))
	{
		struct DLink *current = lst->head->next;

			while(current != lst->tail)
			{
				if(EQ(current->value, e))
					_removeLink(lst, current);
				current = current->next;
			}
	}
}
