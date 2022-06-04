#pragma once
#ifndef _BST_ADT_H
#define _BST_ADT_H

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;


void initBST(BST* bst);
void insertBST(BST* bst, int value);
void printTreeInorder(BST* bst);
void destroyBST(BST* bst);
int findIndexNFromLast(BST* bst, int N);
int sameHeightLeaves(BST* bst);
void insertNode(TreeNode* node, int value);
void inOrder(TreeNode* root);
void destroyNodes(TreeNode* node);
int countingAndReturnValue(TreeNode* node, int N,int* check,int berrier);
TreeNode* createNode(value);
void countingSteps(TreeNode* node, int* count);
int returnByCount(TreeNode* node, int* count);
void StepsValue(TreeNode* node,int* tree_num);






#endif // !_BST_ADT_H