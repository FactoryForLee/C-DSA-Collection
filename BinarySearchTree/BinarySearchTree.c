#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(ElementType Word, ElementType Meaning)
{
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Word = (char*)malloc(strlen(Word) + 1);
	NewNode->Meaning = (char*)malloc(strlen(Meaning) + 1);
	strcpy(NewNode->Word, Word);
	strcpy(NewNode->Meaning, Meaning);
	NewNode->Left = NULL;
	NewNode->Right = NULL;
}

void BST_DestroyNode(BSTNode* Node)
{
	free(Node->Word);
	free(Node->Meaning);
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
	if (Tree == NULL) return;
	BST_DestroyTree(Tree->Left);
	BST_DestroyTree(Tree->Right);

	Tree->Left = NULL;
	Tree->Right = NULL;

	BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
	if (Tree == NULL) return NULL;

	int compare = strcmp(Target, Tree->Word);
	
	if (compare == 0)
	{
		return Tree;
	}

	else if (compare < 0)
	{
		return BST_SearchNode(Tree->Left, Target);
	}

	else
	{
		return BST_SearchNode(Tree->Right, Target);
	}
}

BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
	if (Tree == NULL) return NULL;

	if (Tree->Left == NULL) return Tree;

	else
		BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode** Tree, BSTNode* Child)
{
	(*Tree) = BST_InsertRecursive((*Tree), Child);
}

BSTNode* BST_InsertRecursive(BSTNode* Tree, BSTNode* Child)
{
	if (Tree == NULL)
	{
		return Child;
	}

	int compare = strcmp(Child->Word, Tree->Word);

	if (compare == 0)
	{
		printf("ERROR The word already exists.\n");
		return Tree;
	}

	else if (compare < 0)
	{
		Tree->Left = BST_InsertRecursive(Tree->Left, Child);
	}
	else
	{
		Tree->Right = BST_InsertRecursive(Tree->Right, Child);
	}

	return Tree;
}

void BST_RemoveNode(BSTNode** Tree, ElementType Target)
{
	(*Tree) = BST_RemoveRecursive((*Tree), Target);
}

BSTNode* BST_RemoveRecursive(BSTNode* Tree, ElementType Target)
{
	if (Tree == NULL)
		return NULL;

	int compare = strcmp(Target, Tree->Word);

	if (compare < 0)
		Tree->Left = BST_RemoveRecursive(Tree->Left, Target);
	else if (compare > 0)
		Tree->Right = BST_RemoveRecursive(Tree->Right, Target);
	else // 단어 일치
	{
		if (Tree->Left == NULL) // 오른쪽 자식만 존재하거나 둘 다 없거나
		{
			BSTNode* Temp = Tree->Right;
			BST_DestroyNode(Tree);
			return Temp;
		}

		else if (Tree->Right == NULL) // 왼쪽 자식만 존재하는 경우
		{
			BSTNode* Temp = Tree->Left;
			BST_DestroyNode(Tree);
			return Temp;
		}

		BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
		strcpy(Tree->Word, MinNode->Word);
		strcpy(Tree->Meaning, MinNode->Meaning);
		Tree->Right = BST_RemoveRecursive(Tree->Right, MinNode->Word);
	}

	return Tree; // 자신을 위로 넘겨 트리 유지
}

BSTNode* BST_ExtractNode(BSTNode** Tree, ElementType Target) 
{
	BSTNode* SearchedNode = BST_SearchNode((*Tree), Target);
	if (SearchedNode == NULL) return NULL;

	BSTNode* extractednode = BST_CreateNode(Target, SearchedNode->Meaning);
	BST_RemoveNode(Tree, Target);

	return extractednode;
}

void BST_InorderPrintTree(BSTNode* Node)
{
	if (Node == NULL) return;

	// 왼쪽 하위 트리 출력
	BST_InorderPrintTree(Node->Left);
	// 뿌리 노드 출력
	printf("%s : %s\n", Node->Word, Node->Meaning);
	// 오른쪽 하위 트리 출력
	BST_InorderPrintTree(Node->Right);
}