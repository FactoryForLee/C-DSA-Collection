#include "LinkedListStack.h"

int main(void)
{
	Node* Popped;
	LinkedListStack* Stack;
	int Count = 0;

	LLS_CreateStack(&Stack);
	// abc <- def <- efg <- hij(Top) 로 스택에 저장 (<-는 포인터 연결 방향)
	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("efg"));
	LLS_Push(Stack, LLS_CreateNode("hij"));

	Count = LLS_GetSize(Stack);
	printf("Size: %d, Top: %s\n\n", Count, LLS_Peek(Stack)->Data);

	// 모든 요소를 Pop하여 결과 확인
		// 출력: hij, efg, def, abc 순으로
	for (int i = 0; i < Count; i++)
	{
		if (LLS_IsEmpty(Stack))
			break;

		Popped = LLS_Pop(Stack);

		printf("Popped: %s, ", Popped->Data);

		LLS_DestroyNode(Popped);

		if (!LLS_IsEmpty(Stack))
		{
			printf("Current Top: %s\n", LLS_Peek(Stack)->Data);
		}
		else
		{
			printf("Stack Is Empty.\n");
		}
	}

	LLS_DestroyStack(Stack);

	return 0;

}