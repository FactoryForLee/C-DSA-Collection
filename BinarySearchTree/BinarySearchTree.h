#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* ElementType;

typedef struct tagBSTNode
{
	struct tagNSTNode* Left;
	struct tagNSTNode* Right;

	ElementType Word;
	ElementType Meaning;
}BSTNode;

BSTNode* BST_CreateNode(ElementType Word, ElementType Meaning);
void BST_DestroyNode(BSTNode* Node);
void BST_DestroyTree(BSTNode* Tree);

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target);
BSTNode* BST_SearchMinNode(BSTNode* Tree);
BSTNode* BST_InsertRecursive(BSTNode* Tree, BSTNode* Child);
void BST_InsertNode(BSTNode** Tree, BSTNode* Child);
void BST_RemoveNode(BSTNode** Tree, ElementType Target);
BSTNode* BST_RemoveRecursive(BSTNode* Tree, ElementType Target);
BSTNode* BST_ExtractNode(BSTNode** Tree, ElementType Target);
void BST_InorderPrintTree(BSTNode* Node);

int ReadCSV(BSTNode** Tree);
#endif // !BINARY_SEARCH_TREE_H
