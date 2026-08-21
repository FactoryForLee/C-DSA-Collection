#include "Heap.h"

Heap* HEAP_Create(int InitialSize)
{
	Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
	NewHeap->Capacity = InitialSize;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);
	
	return NewHeap;
}

void HEAP_Destroy(Heap* H)
{
	free(H->Nodes);
	free(H);
}

void HEAP_Insert(Heap* H, ElementType NewData)
{
	int CurrentPosition = H->UsedSize;
	int ParentPosition = HEAP_GetParent(CurrentPosition);

	if (H->UsedSize == H->Capacity)
	{
		H->Capacity *= 2;// Capacity를 두 배로 늘림. C#의 여러 자료구조도 비슷한 로직을 사용
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}

	H->Nodes[CurrentPosition].Data = NewData;

	// 후속 처리
	while (CurrentPosition > 0 &&// 뿌리에 도달하거나 더 큰 노드를 만나면 탈출
		H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
	{
		HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

		CurrentPosition = ParentPosition;
		ParentPosition = HEAP_GetParent(CurrentPosition);
	}

	H->UsedSize++;
}

void HEAP_SwapNodes(Heap* H, int Index1, int Index2)
{
	HeapNode Temp = H->Nodes[Index1];
	H->Nodes[Index1] = H->Nodes[Index2];
	H->Nodes[Index2] = Temp;
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root)
{
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPosition = 0;

	*Root = H->Nodes[0];// Root에 최솟값 저장
	memset(&H->Nodes[0], 0, sizeof(HeapNode));

	H->UsedSize--;
	HEAP_SwapNodes(H, 0, H->UsedSize);// 최하단우측을 뿌리로

	LeftPosition = HEAP_GetLeftChild(0);
	RightPosition = LeftPosition + 1;

	while (1)
	{
		int SelectedChild = 0;

		if (LeftPosition >= H->UsedSize)// 끝에 도달하여 종료
			break;

		if (RightPosition >= H->UsedSize)
		{
			SelectedChild = LeftPosition;
		}
		else
		{
			// 더 작은 자식 찾기
			if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
				SelectedChild = RightPosition;
			else
				SelectedChild = LeftPosition;
		}

		if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
		{// 작은 자식과 자리 바꾸기
			HEAP_SwapNodes(H, ParentPosition, SelectedChild);
			ParentPosition = SelectedChild;
		}
		else
			break;

		LeftPosition = HEAP_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition + 1;
	}

	if (H->UsedSize < (H->Capacity / 2))
	{
		H->Capacity /= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}
}

int HEAP_GetParent(int Index)
{
	return (int)((Index - 1) / 2);
}

int HEAP_GetLeftChild(int Index)
{
	return (2 * Index) + 1;
}

void HEAP_PrintNodes(Heap* H)
{
	for (int i = 0; i < H->UsedSize; i++)
	{
		printf("%d ", H->Nodes[i].Data);
	}
	printf("\n");
}

void HEAP_PrintAtLevel(Heap* H, int Level)
{
	int k = 0;
	int rightEnd = 0;

	for (int i = 0; i < Level; i++)
	{
		k = 2 * k + 1;
		rightEnd = 2 * rightEnd + 2;
	}

	if (k >= H->UsedSize) return;
	if (rightEnd >= H->UsedSize) rightEnd = H->UsedSize - 1;
	
	printf("Print Level %d\n", Level);

	for (int i = k; i <= rightEnd; i++)
	{
		printf("%d ", H->Nodes[i].Data);
	}
}