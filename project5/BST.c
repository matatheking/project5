#include <stdio.h>
#include "BST.h"
void initBST(BST* bst) {
	bst->root = NULL;
}

void insertBST(BST* bst, int value) {

	if (bst->root == NULL)
	{
		bst->root = createNode(value);
		return;
	}
	else {
		insertNode(bst->root, value);
	}

}

TreeNode* createNode(int value) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = NULL;
	node->right = NULL;
	node->element = value;
	return node;
}


void insertNode(TreeNode* node, int value) {

	if (node->element > value)
	{
		if (node->left == NULL)
		{
			node->left = createNode(value);
		}

		else
		{
			/*node->left = createNode*/;
			insertNode(node->left, value);
		}
	}
	if (node->element <= value)
	{
		if (node->right == NULL)
		{
			node->right = createNode(value);
		}
		else
		{
			//node->right = createNode();
			insertNode(node->right, value);
		}
	}
}


void printTreeInorder(BST* bst) {

	if (bst->root != NULL)//
	{
		inOrder(bst->root);//calling the helping function
	}
	else {
		printf("Empty tree");
	}
}

void inOrder(TreeNode* root) {
	if (root==NULL)
	return;
	inOrder(root->left);
	printf("%d, ", root->element);
	inOrder(root->right);
}

void destroyBST(BST* bst) {
	if (bst->root == NULL)
		return;
	else
	{
		destroyNodes(bst->root);
	}
}

void destroyNodes(TreeNode* node) {
	if (node->left != NULL || node->right != NULL)
	{
		if (node->left != NULL)
		{
			destroyNodes(node->left);
		}

		if (node->right != NULL)
		{
			destroyNodes(node->right);
		}
	}
	free(node);
}

int findIndexNFromLast(BST* bst, int N) {
	int element_index = countingAndReturnValue(bst->root, N);
	return element_index;
}


int countingAndReturnValue(TreeNode* node, int N)
{

	if (N == 0)
	{
		return node->element;
	}
	if (node->left != NULL || node->right != NULL)//if its not the last / only node
	{
		//go over the right nodes
		if (node->right != NULL)
		{
			countingAndReturnValue(node->right, N);
		}
		//when the right elements recrucion stops,it move to the left nodes rerucsion,and return	N-1 (counter -1)   
		if (node->left != NULL && N > 0)
		{
			countingAndReturnValue(node->left, N - 1);
		}
	}

}





/*int sameHeightLeaves(BST * bst) {

}


}
}*/

