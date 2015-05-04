#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cirListDeque.h"

/* internal functions interface */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);

/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void initCirListDeque (struct cirListDeque *q) 
{
	assert(q != 0);
	q->Sentinel = (struct DLink *)malloc(sizeof(struct DLink));
	assert(q->Sentinel != 0);
	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;

	q->size = 0;
}

/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	struct DLink *newlink = (struct DLink *)malloc(sizeof(struct DLink));
	newlink->value = val;
	return newlink;
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	newLnk	pointer to the new link to add after the existing link
	pre:	q is not null
	pre: 	lnk and newLnk are not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk)
{
	assert(q != 0);
	assert(lnk != 0 && newLnk != 0);
	struct DLink *current = q->Sentinel;
	do{
		if(EQ(current, lnk))
		{
			newLnk->next = lnk->next;
			lnk->next->prev = newLnk;
			lnk->next = newLnk;
			newLnk->prev = lnk;
			q->size++;
		}
	current = current->next;
	}while(current != q->Sentinel);
	assert(EQ(lnk->next, newLnk));
	
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	assert(q != 0);
	struct DLink *newlink = _createLink (val);
	_addLinkAfter(q, q->Sentinel->prev, newlink);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	assert(q != 0);
	struct DLink *newlink = _createLink (val);
	_addLinkAfter(q, q->Sentinel, newlink);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	assert(q != 0 && q->size > 0);
	return q->Sentinel->next->value;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	assert(q != 0 && q->size > 0);
	return q->Sentinel->prev->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	pre:	lnk is in the deque 
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	assert(q != 0 && q->size > 0);
	if(q->size > 0)
	{
		struct DLink *current = q->Sentinel;
		do{
		current = current->next;
			if(EQ(current, lnk))
			{
				lnk->next->prev = lnk->prev;
				lnk->prev->next = lnk->next;
				free(lnk);
				q->size--;
				break;
			}
		}while(current != q->Sentinel);
	}
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	assert(q != 0 && q->size > 0);
	_removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	assert(q != 0 && q->size > 0);
	_removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including backSentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	if(q->size > 0)
	{
		struct DLink *current = q->Sentinel->next;
		struct DLink *Temp;
		do{
		Temp = current;
		current = current->next;
		free(Temp);
		q->size--;
		}while(current != q->Sentinel);
	}
	assert(q->size == 0);
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	assert(q != 0);
	return !q->size;
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	assert(q != 0 && q->size > 0);
	struct DLink *current = q->Sentinel->next;
	if(q->size > 0)
	{
		do{
		printf("%d \n", current->value);
		current = current->next;
		}while(current != q->Sentinel);
	}
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	assert(q != 0 && q->size > 0);

	struct DLink *current = q->Sentinel;
	struct DLink *temp;
	if(q->size > 0)
	{
		do{
		temp = current;
		current->next = current->prev;
		current->prev = temp->next;
		current = current->prev;
		}while(current != q->Sentinel);
	}
}