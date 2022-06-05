#include <stdio.h>
#include "BST.h"
#include <string.h> 
//#define Is_NULL(s);\
//while (!s)\
//{
//puts("allocation failed");
//	exit(1);
//}
//Is_NULL;



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
	//Is_allocation(node);
	node->left = NULL;
	node->right = NULL;
	node->element = value;
	return node;
}
void insertNode(TreeNode* node, int value) {
	//if element > value : if left node is empty create new one and implement its element with the value, if its not NULL go left
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
	//if element <= value : if right node is empty create new one and implement its element with the value, if its not NULL go right

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
void inOrder(TreeNode* root) {//function that go over the tree's elements from the smallest to the biggest
	if (root == NULL)
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
void destroyNodes(TreeNode* node) {//destroy function
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
int findIndexNFromLast(BST* bst, int N) {//function that recieve index and return the element index,start counting from the biigest element
	int count = 0;//count elements in the tree
	countingSteps(bst->root, &count);//calling helping recruicive function that updeates count
	int tree_num = 0;//this int will contain all the elements from the biggest to the smallest	
	 StepsValue(bst->root,&tree_num);//helping function that updates "tree_num" - implement all the elements from the biggest to the smallest
	 for (int i = count; i > N; i--)//divide the big number ("tree_num") until it reach th N element
	 {
		 tree_num = tree_num / 10;
	 }
	 tree_num = tree_num % 10;//modudle what left from the big number in order to return the N element.
	 return tree_num;
}
void StepsValue(TreeNode* node,int* tree_num) {////helping recruision function that updeats tree_num, makes it a big numder that contains all the trees element
	if (node == NULL)
	{
		return;
	}
	StepsValue(node->right,tree_num);
	 *tree_num = *tree_num * 10 +node->element;
	 StepsValue(node->left,tree_num);

}
void countingSteps(TreeNode* node,int* count) //helping recruision function that counting num of element.
{
	if (node ==NULL)
	{
		return;
	}
	countingSteps(node->right, count);
	*count = *count + 1;
	countingSteps(node->left, count);
}
/* function which checks whether all leaves are at same level */
int checkHight(TreeNode* node, int level, int* leafLevel)
{
	// Base case
	if (node == NULL)  return 1;

	// If a leaf node is discovered
	if (node->left == NULL && node->right == NULL)
	{
		// When a leaf node discovered for the first time
		if (*leafLevel == 0)
		{
			*leafLevel = level;
			return 1;
		}

		// If this is not the first leaf, compare its level with
		// first leaf's level
		return (level == *leafLevel);
	}

	// If this is not a leaf,check left and right subtrees
	return checkHight(node->left, level + 1, leafLevel) && checkHight(node->right, level + 1, leafLevel);
}

int sameHeightLeaves(BST* bst)
{
	int level = 0, leafLevel = 0;
	return checkHight(bst->root, level, &leafLevel);//calling the helping function
}