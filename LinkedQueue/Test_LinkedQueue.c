#include "LinkedQueue.h"

enum ECustomerType
{
	Normal,
	Premium,
	VIP,
	Count
};

int main(void)
{
	int i;
	int maxRequest = 5;
	LinkedQueue* Queues[Count];

	LQ_CreateQueue(&Queues[Normal]);
	LQ_CreateQueue(&Queues[Premium]);
	LQ_CreateQueue(&Queues[VIP]);

	LQ_Enqueue(Queues[Normal], LQ_CreateNode("Jason"));
	LQ_Enqueue(Queues[Normal], LQ_CreateNode("Diana"));
	LQ_Enqueue(Queues[Normal], LQ_CreateNode("Hugo"));
	LQ_Enqueue(Queues[Normal], LQ_CreateNode("Tom"));
	LQ_Enqueue(Queues[Premium], LQ_CreateNode("Heinsberg"));
	LQ_Enqueue(Queues[Premium], LQ_CreateNode("Jacob"));
	LQ_Enqueue(Queues[Premium], LQ_CreateNode("Kate"));
	LQ_Enqueue(Queues[VIP], LQ_CreateNode("Arthur"));
	LQ_Enqueue(Queues[VIP], LQ_CreateNode("Karen"));


	printf("===== 요청 %d건에 대한 처리 =====\n", maxRequest);

	for (int i = 0; i < maxRequest; i++)
	{
		Node* Dequeued;
		char rank[10];

		if (!LQ_IsEmpty(Queues[VIP]))
		{
			Dequeued = LQ_Dequeue(Queues[VIP]);
			strcpy(rank, "VIP");
		}
		else if (!LQ_IsEmpty(Queues[Premium]))
		{
			Dequeued = LQ_Dequeue(Queues[Premium]);
			strcpy(rank, "Premium");
		}
		else if (!LQ_IsEmpty(Queues[Normal]))
		{
			Dequeued = LQ_Dequeue(Queues[Normal]);
			strcpy(rank, "Normal");
		}
		else
			break;


		printf("회원 등급: %s | 이름: %s | 처리 중\n", rank, Dequeued->Data);
	}


	printf("===== 남은 회원 현황 =====\n");

	for (int i = Count - 1; i >= 0; i--)
	{
		while (!LQ_IsEmpty(Queues[i]))
		{
			printf("이름: %s | 대기 중\n", LQ_Dequeue(Queues[i])->Data);
		}

		LQ_DestroyQueue(Queues[i]);
	}
}