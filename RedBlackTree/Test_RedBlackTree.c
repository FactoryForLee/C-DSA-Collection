#include "RedBlackTree.h"

RBTNode* Nil;

int main(void)
{
	RBTNode* Tree = NULL;
	RBTNode* Node = NULL;

	Nil = RBT_CreateNode(0);
	Nil->Color = BLACK;

	while (1)
	{
		int cmd = 0;
		int param = 0;
		char buffer[10] = { 0, };

		printf("Enter command number:\n");
		printf("(1) Create a node, (2) Remove a node, (3) Search a Node\n");
		printf("(4) Display Tree, (5) quit\n");
		printf("command number:");

		fgets(buffer, sizeof(buffer) - 1, stdin);
		sscanf(buffer, "%d", &cmd);
		
		if (cmd < 1 || cmd > 5)// 입력 예외
		{
			printf("Invalid command number.\n");
			continue;
		}
		else if (cmd == 4)// 전체 트리 출력
		{
			RBT_PrintTree(Tree, 0, 0);
			printf("\n");
			continue;
		}
		else if (cmd == 5)// 종료
			break;

		printf("Enter parameter (1~200):\n");

		fgets(buffer, sizeof(buffer) - 1, stdin);
		sscanf(buffer, "%d", &param);

		if (param < 1 || param > 200)
		{
			printf("Invalid parameter.%d\n", param);
			continue;
		}

		switch (cmd)
		{
		case 1:// 새로운 노드 추가
			RBT_InsertNode(&Tree, RBT_CreateNode(param));
			break;
		case 2:// 특정 노드 제거
			Node = RBT_RemoveNode(&Tree, param);

			if (Node == NULL)
				printf("Not found node to delete:%d\n", param);
			else
				RBT_DestroyNode(Node);
			break;
		case 3:// 특정 노드 찾기
			Node = RBT_SearchNode(Tree, param);

			if (Node == NULL)
				printf("Not fount node:%d\n", param);
			else
				printf("Found node: %d(Color:%s)\n", Node->Data, (Node->Color == RED) ? "RED" : "BLACK");
			break;
		}

		printf("\n");
	}

	RBT_DestroyTree(Tree);
	return 0;
}