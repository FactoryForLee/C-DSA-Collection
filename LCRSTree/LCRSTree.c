#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;// 안전하게 NULL로 초기화
	NewNode->Data = NewData;

	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);// 자유저장소에서 해제
}

void LCRS_DestroyTree(LCRSNode* Root)// 재귀로 트리 삭제 (후위 순회)
{
	if (Root->RightSibling != NULL)
	{
		LCRS_DestroyTree(Root->RightSibling);
	}

	if (Root->LeftChild != NULL)
	{
		LCRS_DestroyTree(Root->LeftChild);
	}

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)// 자식 연결 로직
{
	if (Parent->LeftChild == NULL)// 자식이 없다면 자식으로 연결
	{
		Parent->LeftChild = Child;
	}

	else// 자식이 있다면 형제들 중 하나로 연결
	{
		LCRSNode* Cur = Parent->LeftChild;

		while (Cur->RightSibling != NULL)
			Cur = Cur->RightSibling;

		Cur->RightSibling = Child;
	}
}
// Root부터 모든 노드를 출력 Root -> 자식 -> 형제 순
void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	//들여쓰기
	for (int i = 0; i < Depth - 1; i++)
		printf("   "); // 공백 3개

	if (Depth > 0) // 자식 노드 여부 표시
		printf("+--");

	// 노드 데이터 출력
	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

// 특정 레벨에 있는 노드를 출력.
void LCRS_PrintNodeAtLevel(LCRSNode* Node, int Level)
{
	if (Node == NULL)
		return;

	if (Level == 0)// 0을 기준으로 도달 여부 확인
	{
		printf("%c ", Node->Data);
	}

	else if (Level > 0)// 아직 층이 낮기에 다음 레벨로 이동
	{
		LCRS_PrintNodeAtLevel(Node->LeftChild, Level - 1);
	}
	// 맞는 층이라면 출력을 위해 아니라면 형제의 자식을 찾기 위해 호출
	LCRS_PrintNodeAtLevel(Node->RightSibling, Level);
}