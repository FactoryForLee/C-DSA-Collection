#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->Count = 0;
	(*Stack)->Top = NULL;
}

Node* LLS_CreateNode(char* NewData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = (char*)malloc(strlen(NewData) + 1); // 문자열 끝 /0를 반영하기 위한 +1

	strcpy(newNode->Data, NewData);
	newNode->NextNode = NULL;

	return newNode;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack)) // 스택의 내용물 비우기
	{
		Node* popped = LLS_Pop(Stack);
		LLS_DestroyNode(popped);
	}

	free(Stack); // 자유 저장소에서 해제
}

void LLS_DestroyNode(Node* _Node)
{ // 데이터 free 후 노드를 free해야한다.
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* newNode)
{
	newNode->NextNode = Stack->Top;
	Stack->Top = newNode;
	Stack->Count++;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	// Stack의 Top을 교체한 후 반환
	if (LLS_IsEmpty(Stack)) return NULL; // Stack 비었다면 return

	Node* popped = Stack->Top;
	Stack->Top = Stack->Top->NextNode; // 마지막 요소 뽑을 시 자동으로 NULL을 가리킴
	Stack->Count--;

	return popped;
}

Node* LLS_Peek(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	return Stack->Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return Stack->Count == 0;
}