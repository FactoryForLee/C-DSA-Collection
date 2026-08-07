#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20

typedef struct tagNode
{
	char Name[MAX_NAME_LEN];
}Node; // 노드가 곧 한 사람의 데이터

typedef struct tagCircularQueue
{
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
}CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, char* Name);
Node CQ_Dequeue(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);
#endif // !CIRCULAR_QUEUE_H

