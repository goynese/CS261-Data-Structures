#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "type.h"
#include "structs.h"

/* Example main file to begin exercising your tree */

int main(int argc, char *argv[])
{	
	struct BSTree *tree	= newBSTree();		
		
	/*Create value of the type of data that you want to store*/
	struct data myData1;
	struct data myData2;
	struct data myData3;
	struct data myData4;
		
	myData1.number = 5;
	myData1.name = "rooty";
	myData2.number = 1;
	myData2.name = "lefty";
	myData3.number = 10;
	myData3.name = "righty";
	myData4.number = 3;
	myData4.name = "righty";
	
	/*add the values to BST*/
	
	addBSTree(tree, &myData1);
	addBSTree(tree, &myData2);
	addBSTree(tree, &myData4);
	addBSTree(tree, &myData3);
		addBSTree(tree, &myData1);
	addBSTree(tree, &myData2);
	addBSTree(tree, &myData4);
	addBSTree(tree, &myData3);
			addBSTree(tree, &myData1);
	addBSTree(tree, &myData2);
	addBSTree(tree, &myData4);
	addBSTree(tree, &myData3);
			addBSTree(tree, &myData1);
	addBSTree(tree, &myData2);
	addBSTree(tree, &myData4);
	addBSTree(tree, &myData3);

	printf("\n %d \n", containsBSTree(tree, &myData2));

	printTree(tree);

	printf("\n");
	removeBSTree(tree, &myData1);
	removeBSTree(tree, &myData2);
	removeBSTree(tree, &myData3);
	removeBSTree(tree, &myData4);
		removeBSTree(tree, &myData1);
	removeBSTree(tree, &myData2);
	removeBSTree(tree, &myData3);
	removeBSTree(tree, &myData4);
		removeBSTree(tree, &myData1);
	removeBSTree(tree, &myData2);
	removeBSTree(tree, &myData3);
	removeBSTree(tree, &myData4);

	printTree(tree);	


	if( containsBSTree(tree, &myData1))
		printf("\n It contains it");
	printf("\n");
	/*Print the entire tree*/	
	printTree(tree);	

	/*(( 1 ( 3 ) ) 5 ( 10 ))*/
	return 1;
}

