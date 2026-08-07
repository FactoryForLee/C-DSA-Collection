#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CircularQueue* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, char* Name)
{
	if (CQ_IsFull(Queue)) return;

	// 1. 값 대입
	strcpy(Queue->Nodes[Queue->Rear].Name, Name);

	// 2. 배열을 넘지 않기 위한 나머지 연산
	Queue->Rear = (Queue->Rear + 1) % Queue->Capacity;
}

Node CQ_Dequeue(CircularQueue* Queue)
{
	Node Dequeued = { 0, };

	if (CQ_IsEmpty(Queue))
	{
		printf("큐가 비어있습니다.");
		return Dequeued;
	}

	// 1. 데이터 추출
	strcpy(Dequeued.Name, Queue->Nodes[Queue->Front].Name);

	// 2. 추출 후 해당 인덱스 비우기
	memset(Queue->Nodes[Queue->Front].Name, 0, MAX_NAME_LEN);

	// 3. 배열을 넘지 않기 위한 나머지 연산
	Queue->Front = (Queue->Front + 1) % Queue->Capacity;

	return Dequeued;
}

int CQ_GetSize(CircularQueue* Queue)
{
	return (Queue->Rear - Queue->Front + Queue->Capacity) % Queue->Capacity;
}

int CQ_IsEmpty(CircularQueue* Queue)
{
	return Queue->Front == Queue->Rear;
}

int CQ_IsFull(CircularQueue* Queue)
{
	return Queue->Front == (Queue->Rear + 1) % Queue->Capacity;
}