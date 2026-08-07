#include "CircularQueue.h"
#define CAPACITY 5

enum ECustomerType
{
	Normal,
	Premium,
	VIP,
	Count
};

int main(void)
{
	system("chcp 65001");

	int i;
	int maxRequest = 5;
	CircularQueue* Queues[Count];

	CQ_CreateQueue(&Queues[Normal], CAPACITY);
	CQ_CreateQueue(&Queues[Premium], CAPACITY);
	CQ_CreateQueue(&Queues[VIP], CAPACITY);

	CQ_Enqueue(Queues[Normal], "Jason");
	CQ_Enqueue(Queues[Normal], "Diana");
	CQ_Enqueue(Queues[Normal], "Hugo");
	CQ_Enqueue(Queues[Normal], "Tom");
	CQ_Enqueue(Queues[Premium], "Heinsberg");
	CQ_Enqueue(Queues[Premium], "Jacob");
	CQ_Enqueue(Queues[Premium], "Kate");
	CQ_Enqueue(Queues[VIP], "Arthur");
	CQ_Enqueue(Queues[VIP], "Karen");


	printf("===== 요청 %d건에 대한 처리 =====\n", maxRequest);

	for (int i = 0; i < maxRequest; i++)
	{
		Node Dequeued;
		char rank[10];

		if (!CQ_IsEmpty(Queues[VIP]))
		{
			Dequeued = CQ_Dequeue(Queues[VIP]);
			strcpy(rank, "VIP");
		}
		else if (!CQ_IsEmpty(Queues[Premium]))
		{
			Dequeued = CQ_Dequeue(Queues[Premium]);
			strcpy(rank, "Premium");
		}
		else if (!CQ_IsEmpty(Queues[Normal]))
		{
			Dequeued = CQ_Dequeue(Queues[Normal]);
			strcpy(rank, "Normal");
		}
		else
			break;


		printf("회원 등급: %s | 이름: %s | 처리 중\n", rank, Dequeued.Name);
	}


	printf("===== 남은 회원 현황 =====\n");

	for (int i = Count - 1; i >= 0; i--)
	{
		while (!CQ_IsEmpty(Queues[i]))
		{
			Node Dequeued = CQ_Dequeue(Queues[i]);
			printf("이름: %s | 대기 중\n", Dequeued.Name);
		}

		CQ_DestroyQueue(Queues[i]);
	}
}