#include "BinarySearchTree.h"

int main()
{
	BSTNode* Tree = NULL;

	// 영단어 파일 불러오기
	ReadCSV(&Tree);

	printf("============= 영어 사전 ============\n");
	printf("1. 뜻 찾기\n");
	printf("2. 단어 삭제\n");
	printf("3. 단어 추출\n");
	printf("4. 전체 출력\n");
	printf("5. 종료\n");


	while (1)
	{
		fflush(stdin);
		int menu;
		scanf("%d", &menu);
		char word[20];

		switch (menu)
		{
		case 1:
			printf("단어 입력: ");
			scanf("%s", word);
			BSTNode* Searched = BST_SearchNode(Tree, word);

			if (Searched == NULL)
			{
				printf("%s는 없는 단어 입니다.\n", word);
			}
			else
			{
				printf("%s의 뜻 %s.\n", word, Searched->Meaning);
			}
			break;

		case 2:
			printf("단어 입력: ");
			scanf("%s", word);
			BST_RemoveNode(&Tree, word);
			printf("삭제 실행됨.\n");
			break;
		case 3:
			printf("단어 입력: ");
			scanf("%s", word);
			BSTNode* extracted = BST_ExtractNode(&Tree, word);
			if (extracted == NULL)
			{
				printf("%s는 없는 단어 입니다.\n", word);
			}
			else
			{
				printf("추출된 %s의 뜻 %s.\n", word, extracted->Meaning);
			}
			break;
		case 4:
			printf("=====      전체 출력      =====\n");
			BST_InorderPrintTree(Tree);
			break;
		case 5:
			printf("프로그램 종료.\n");
			return 0;
			break;
		}
	}

	return 0;
}