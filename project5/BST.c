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
	int count = 0;
	countingSteps(bst->root, &count);
	int tree_num = 0;	
	 StepsValue(bst->root,&tree_num);
	 for (int i = count; i > N; i--)
	 {
		 tree_num = tree_num / 10;
	 }
	 tree_num = tree_num % 10;
	 return tree_num;
}
void StepsValue(TreeNode* node,int* tree_num) {
	if (node == NULL)
	{
		return;
	}
	StepsValue(node->right,tree_num);
	 *tree_num = *tree_num * 10 +node->element;
	 StepsValue(node->left,tree_num);

}


void countingSteps(TreeNode* node,int* count)
{
	if (node ==NULL)
	{
		return;
	}
	countingSteps(node->right, count);
	*count = *count + 1;
	countingSteps(node->left, count);
}




















	



/*int sameHeightLeaves(BST * bst) {

}


}
}*/

