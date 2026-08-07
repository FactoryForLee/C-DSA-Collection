#ifndef LINKEDLIST_STACH_H
#define LINKEDLIST_STACH_H
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode; // 다음 노드를 가리키기 위한
}Node;

typedef struct tagLinkedListStack
{
	int Count; // 삽입/삭제 시 개수를 갱신
	Node* Top; // 스택을 가리키는 포인터 빈 스택은 NULL이다
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(Node* _Node);

void LLS_Push(LinkedListStack* Stack, Node* newNode);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Peek(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);

#endif // !LINKEDLIST_STACH_H