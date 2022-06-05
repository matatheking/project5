#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"
main() {

	BST* bst = (BST*)calloc(1,sizeof(BST));
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	initBST(bst);//initialize binary tree
	//insert elements 
	insertBST(bst, 5);
	insertBST(bst, 2);
	insertBST(bst, 8);
	insertBST(bst, 7);
	insertBST(bst, 4);
	insertBST(bst, 1);
	insertBST(bst, 9);
	insertBST(bst, 10);
	
	print_ascii_tree(bst->root);
	printf("\n");
	printTreeInorder(bst);//print tree's elements from smallest to heighest.
	int N = 3;
	int index_value = findIndexNFromLast(bst, N);//return the N biggest element 
	printf("\n");
	printf("the third biggest element is %d \n", index_value);
	//check if 
	(sameHeightLeaves(bst) == 1 ? printf("All the leaves are in the same height\n") : printf("All the leaves are not in the same height\n"));
	destroyBST(bst);
	






}