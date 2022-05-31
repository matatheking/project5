#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"
main() {

	BST* bst = (BST*)calloc(1,sizeof(BST));
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	initBST(bst);
	insertBST(bst, 5);
	insertBST(bst, 2);
	insertBST(bst, 8);
	insertBST(bst, 7);
	insertBST(bst, 4);
	insertBST(bst, 1);
	insertBST(bst, 9);
	//print_ascii_tree(bst->root);

	printf("\n");
	printTreeInorder(bst);






}