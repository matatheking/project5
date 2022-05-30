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

int findIndexNFromLast(BST* bst, int N) {
	
	
	if (bst->root->left!=NULL||bst->root->right!=NULL)//if its not the last / only node
	{
		//go over the right nodes
		if (bst->root->right!=NULL)
		{
			return findIndexNFromLast(bst->root->right, N);
		}
	
		
	    //when the right elements recrucion stops,it move to the left nodes rerucsion,and return	N-1 (counter -1) and also return addition 1  
		if (bst->root->left!=NULL && N>0)
		{
		 return findIndexNFromLast(bst->root->left, N-1)+1;

		}
	
	}



}


