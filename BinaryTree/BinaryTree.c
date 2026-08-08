#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType NewData)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);
	strcpy(NewNode->Data, NewData);
	NewNode->Left = NULL;
	NewNode->Right = NULL;

	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node->Data);
	free(Node);
}

/// <summary>
/// Delete by postorder
/// (Left sub tree -> right sub tree -> root)
/// </summary>
/// <param name="Root"></param>
void SBT_DestroyTree(SBTNode* Root)
{
	if (Root == NULL) return;
	SBT_DestroyTree(Root->Left); // 왼쪽 하위 트리 제거
	SBT_DestroyTree(Root->Right);// 오른쪽 하위 트리 제거
	SBT_DestroyNode(Root);		 // Root 제거
}

/// <summary>
/// print root -> print left sub tree -> print right sub tree
/// </summary>
/// <param name="Node"></param>
void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL) return;
	printf(" %s", Node->Data);
	SBT_PreorderPrintTree(Node->Left);
	SBT_PreorderPrintTree(Node->Right);
}

/// <summary>
/// print left sub tree -> print root -> print right sub tree
/// </summary>
/// <param name="Node"></param>
void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == NULL) return;
	SBT_InorderPrintTree(Node->Left);
	printf(" %s", Node->Data);
	SBT_InorderPrintTree(Node->Right);
}

/// <summary>
/// print left sub tree -> print right sub tree -> print root
/// </summary>
/// <param name="Node"></param>
void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == NULL) return;
	SBT_PostorderPrintTree(Node->Left);
	SBT_PostorderPrintTree(Node->Right);
	printf(" %s", Node->Data);
}