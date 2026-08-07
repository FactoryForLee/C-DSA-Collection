#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
	while (!LQ_IsEmpty(Queue))
	{
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestoryNode(Popped);
	}

	free(Queue);
}

Node* LQ_CreateNode(char* Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewNode) + 1);

	strcpy(NewNode->Data, Data);

	NewNode->NextNode = NULL;

	return NewNode;
}
void LQ_DestoryNode(Node* _Node) 
{
	free(_Node->Data);
	free(_Node);
}

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	// 공백을 기준으로 분기가 나뉨
	if (LQ_IsEmpty(Queue))
	{
		Queue->Front = NewNode; // 첫 삽입 Front 함께 초기화
		Queue->Rear = NewNode;
	}

	else // 이후부턴 계속해서 후단 업데이트
	{
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}

	Queue->Count++;
}

Node* LQ_Dequeue(LinkedQueue* Queue)
{
	if (LQ_IsEmpty(Queue)) return NULL;

	Node* Dequeued = Queue->Front;
	Queue->Front = Queue->Front->NextNode; // 전단 후방으로 이동

	if (LQ_IsEmpty(Queue)) // 옮긴 전단이 NULL이면 공백
		Queue->Rear = NULL;

	Queue->Count--;

	return Dequeued;
}

int LQ_GetSize(LinkedQueue* Queue)
{
	return Queue->Count;
}

int LQ_IsEmpty(LinkedQueue* Queue) // Front가 NULL인 상태를 공백으로 정의
{
	return Queue->Front == NULL;
}