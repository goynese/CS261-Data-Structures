#include "cirListDeque.h"
#include <stdio.h>
#include <malloc.h>

int main(){
	struct cirListDeque* q = (struct cirListDeque*)malloc(sizeof(struct cirListDeque));
	initCirListDeque(q);
	addBackCirListDeque(q, (TYPE)1);
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printCirListDeque(q);
	printf("%g\n", frontCirListDeque(q));
	printf("%g\n", backCirListDeque(q));
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printCirListDeque(q);
	reverseCirListDeque(q);
	printCirListDeque(q);
	getchar();
	return 0;
}
