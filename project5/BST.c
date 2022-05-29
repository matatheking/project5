#include <stdio.h>
#include "BST.h"
void initBST(BST* bst) {
	bst->root = NULL;

}

void insertBST(BST* bst, int value) {

	if (bst->root==NULL)
	{
		bst->root->element = value;
		return;
	}

	if (bst->root->element<= value)
	{
		if (bst->root->left == NULL)
		{
			bst->root->left->element = value;
		}
		else
		{
			insertBST(bst->root->left, value);
		}
	
	}

	if (bst->root->element> value)
	{
		if (bst->root->right==NULL)
		{
			bst->root->right->element = value;
		}
		else
		{
			insertBST(bst->root->right, value);
		}
	}
}
void printTreeInorder(BST* bst) {

	if (bst->root!=NULL)
	{
		printTreeInorder(bst->root->left);
		printf("%d  ", bst->root->element);
		printTreeInorder(bst->root->right);
	}
}
void destroyBST(BST* bst){
	int berrier = bst->root->element;
	if (bst->root == NULL)
		return;
	
	if (bst->root->left != NULL || bst->root->right!=NULL)
	{
		if (bst->root->left != NULL)
		{
			destroyBST(bst->root->left);
		}

		if (bst->root->right != NULL)
		{
			destroyBST(bst->root->right);
		}
	}
	free(bst->root);
}


