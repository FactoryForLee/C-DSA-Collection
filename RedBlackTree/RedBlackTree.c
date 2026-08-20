#include "RedBlackTree.h"
#include <string.h>

extern RBTNode* Nil;

RBTNode* RBT_CreateNode(ElementType NewData)
{
	RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));
	NewNode->Parent = NULL;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	NewNode->Color = BLACK;

	return NewNode;
}

void RBT_DestroyTree(RBTNode* Tree)
{
	if (Tree == Nil) return;

	RBT_DestroyTree(Tree->Left);
	RBT_DestroyTree(Tree->Right);

	Tree->Left = Nil;
	Tree->Right = Nil;
	RBT_DestroyNode(Tree);
}

void RBT_DestroyNode(RBTNode* Node)
{
	free(Node);
}

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target)
{
	if (Tree == Nil)
		return NULL;

	if (Tree->Data > Target)
		return RBT_SearchNode(Tree->Left, Target);
	else if (Tree->Data < Target)
		return RBT_SearchNode(Tree->Right, Target);
	else
		return Tree;
}

RBTNode* RBT_SearchMinNode(RBTNode* Tree)
{
	if (Tree == Nil)
		return Nil;

	if (Tree->Left == Nil)
		return Tree;
	else
		return RBT_SearchMinNode(Tree->Left);
}

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode)
{
	RBT_InsertNodeHelper(Tree, NewNode);

	NewNode->Color = RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RBT_RebuildAfterInsert(Tree, NewNode);
}

void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode)
{// 기존 이진 탐색 트리 규칙 그대로 삽입
	if ((*Tree) == NULL)
		(*Tree) = NewNode;

	if ((*Tree)->Data < NewNode->Data)
	{
		if ((*Tree)->Right == Nil)
		{
			(*Tree)->Right = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
			RBT_InsertNodeHelper(&(*Tree)->Right, NewNode);
	}
	else if ((*Tree)->Data > NewNode->Data)
	{
		if ((*Tree)->Left == Nil)
		{
			(*Tree)->Left = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
			RBT_InsertNodeHelper(&(*Tree)->Left, NewNode);
	}
}

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent)
{
	// 1. 왼쪽 자식의 오른쪽 자식, 부모의 왼쪽 자식으로
	RBTNode* LeftChild = Parent->Left;

	Parent->Left = LeftChild->Right;

	if (LeftChild->Right != Nil)
		LeftChild->Right->Parent = Parent;

	LeftChild->Parent = Parent->Parent;

	// 2. 왼쪽 자식 부모 자리로 이동
	if (Parent->Parent == NULL)// 뿌리에서 진행된 것이라면 왼쪽 자식은 새로운 뿌리로
		(*Root) = LeftChild;
	else// 그것이 아니라면 부모가 존재 좌, 우 여부에 따라 위치 지정
	{
		if (Parent == Parent->Parent->Left)
			Parent->Parent->Left = LeftChild;
		else
			Parent->Parent->Right = LeftChild;
	}

	// 3. 기존 부모를 새로운 부모의 오른쪽 자식으로 이동
	LeftChild->Right = Parent;
	Parent->Parent = LeftChild;
}

void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* RightChild = Parent->Right;

	Parent->Right = RightChild->Left;

	if (RightChild->Left != Nil)
		RightChild->Left->Parent = Parent;

	RightChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
		(*Root) = RightChild;
	else
	{
		if (Parent == Parent->Parent->Left)
			Parent->Parent->Left = RightChild;
		else
			Parent->Parent->Right = RightChild;
	}

	RightChild->Left = Parent;
	Parent->Parent = RightChild;
}

void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X)
{
	while (X != (*Root) && X->Parent->Color == RED)// 4번 조건이 만족 될때까지
	{
		if (X->Parent == X->Parent->Parent->Left)// 부모가 왼쪽 자식일 때
		{
			RBTNode* Uncle = X->Parent->Parent->Right;
			if (Uncle->Color == RED)// 경우 1: 삼촌이 빨간색인 경우
			{
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent->Color = RED;

				X = X->Parent->Parent;
			}
			else
			{
				if (X == X->Parent->Right)// 경우 2: 삼촌이 검은색이고, 새 노드가 오른쪽 자식인 경우
				{
					X = X->Parent;
					RBT_RotateLeft(Root, X);
				}
				// 경우 3: 삼촌이 검은색이고, 새 노드가 왼쪽 자식인 경우
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;

				RBT_RotateRight(Root, X->Parent->Parent);
			}
		}
		else// 부모가 오른쪽 자식일 때
		{
			RBTNode* Uncle = X->Parent->Parent->Left;
			if (Uncle->Color == RED)
			{
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent->Color = RED;

				X = X->Parent->Parent;
			}
			else
			{
				if (X == X->Parent->Left)
				{
					X = X->Parent;
					RBT_RotateRight(Root, X);
				}
				
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RBT_RotateLeft(Root, X->Parent->Parent);
			}
		}
	}

	(*Root)->Color = BLACK;
}

RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data)
{
	RBTNode* Removed = NULL;
	RBTNode* Successor = NULL;
	RBTNode* Target = RBT_SearchNode((*Root), Data);

	if (Target == NULL)
		return NULL;

	if (Target->Left == Nil || Target->Right == Nil)
	{
		Removed = Target;
	}
	else
	{
		Removed = RBT_SearchMinNode(Target->Right);
		Target->Data = Removed->Data;
	}

	if (Removed->Left != Nil)
		Successor = Removed->Left;
	else
		Successor = Removed->Right;

	Successor->Parent = Removed->Parent;

	if (Removed->Parent == NULL)
		(*Root) = Successor;
	else
	{
		if (Removed == Removed->Parent->Left)
			Removed->Parent->Left = Successor;
		else
			Removed->Parent->Right = Successor;
	}

	if (Removed->Color == BLACK)// 삭제한 노드가 검은색이라면
		RBT_RebuildAfterRemove(Root, Successor);// 대체 노드 넘기기(이중 흑색 노드)

	return Removed;
}

void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor)
{
	RBTNode* Sibling = NULL;
	// Successor가 뿌리 노드 혹은 빨간색 노드라면 종료(이중 흑색이 뿌리 혹은 빨간 노드로)
	while (Successor->Parent != NULL && Successor->Color == BLACK)
	{
		if (Successor == Successor->Parent->Left)// 이중 흑색 노드가 부모 노드의 왼쪽 자식인 경우
		{
			Sibling = Successor->Parent->Right;

			if (Sibling->Color == RED)// Case 1. 형제가 빨간색인 경우
			{// Case 2-1, 2-2, 2-3으로 상황을 위임
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;
				RBT_RotateLeft(Root, Successor->Parent);
			}
			else// Case 2. 형제가 검은색이며
			{
				if (Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK)
				{// Case 2-1. 양쪽 자식이 모두 검은색인 경우
					Sibling->Color = RED;
					Successor = Successor->Parent;// 부모로 위임
				}
				else
				{
					if (Sibling->Left->Color == RED)// Case 2-2. 왼쪽 자식이 빨간색인 경우
					{// Case 2-3으로 위임
						Sibling->Left->Color = BLACK;
						Sibling->Color = RED;

						RBT_RotateRight(Root, Sibling);
						Sibling = Successor->Parent->Right;
					}
					// Case 2-3. 오른쪽 자식이 빨간색인 경우
					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = BLACK;
					Sibling->Right->Color = BLACK;
					RBT_RotateLeft(Root, Successor->Parent);

					// 이중 흑색 문제 완전 해결, 루프 탈출을 위해 Successor를 뿌리로 이동
					Successor = (*Root);
				}
			}
		}
		else// 이중 흑색 노드가 부모 노드의 오른쪽 자식인 경우
		{   // 이하 왼쪽 로직과 같음
			Sibling = Successor->Parent->Left;

			if (Sibling->Color == RED)
			{
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;
				RBT_RotateRight(Root, Successor->Parent);
			}
			else
			{
				if (Sibling->Right->Color == BLACK && Sibling->Left->Color == BLACK)
				{
					Sibling->Color = RED;
					Successor = Successor->Parent;
				}
				else
				{
					if (Sibling->Right->Color == RED)
					{
						Sibling->Right->Color = BLACK;
						Sibling->Color = RED;

						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}

					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = BLACK;
					Sibling->Left->Color = BLACK;
					RBT_RotateRight(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
	}
	Successor->Color = BLACK;
}

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount)
{
	char c = 'X';
	int v = -1;
	char cnt[100];

	if (Node == NULL || Node == Nil)
		return;

	if (Node->Color == BLACK)
		BlackCount++;

	if (Node->Parent != NULL)
	{
		v = Node->Parent->Data;

		if (Node->Parent->Left == Node)
			c = 'L';
		else
			c = 'R';
	}

	if (Node->Left == Nil && Node->Right == Nil)
		sprintf(cnt, "--------- %d", BlackCount);
	else
		strncpy(cnt, "", sizeof(cnt));

	for (int i = 0; i < Depth; i++)
		printf("  ");

	printf("%d %s [%c, %d] %s\n", Node->Data, (Node->Color == RED) ? "RED" : "BLACK", c, v, cnt);
	// 출력: 노드 데이터, 노드 색, 노드 좌 또는 우 자리, 부모 데이터, 뿌리부터 잎까지의 검은 노드 수

	RBT_PrintTree(Node->Left, Depth + 1, BlackCount);
	RBT_PrintTree(Node->Right, Depth + 1, BlackCount);
}