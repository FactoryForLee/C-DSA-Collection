#include "BinarySearchTree.h"

#define MAX_LINE_LENGTH 1024 // 한 줄의 최대 길이
const char* FileName = "words.txt";

int ReadCSV(BSTNode** Tree)
{
    // 1. 파일 열기 (test.csv 파일이 같은 폴더에 있다고 가정)
    FILE* file = fopen(FileName, "r");

    if (file == NULL)
    {
        printf("CSV 파일을 열 수 없습니다.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    // 2. 파일 끝까지 한 줄씩 읽어오기
    // fgets는 줄바꿈 문자('\n')를 만날 때까지 읽어 line 배열에 저장합니다.
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        // 줄바꿈 문자 제거 (깔끔한 출력을 위해)
        line[strcspn(line, "\n")] = 0;

        // 3. strtok 함수로 쉼표(,)를 기준으로 문자열 자르기
        char* word = strtok(line, ",");
        char* meaning = strtok(NULL, ",");

        BST_InsertNode(Tree, BST_CreateNode(word, meaning));
    }

    // 4. 메모리 누수 방지를 위해 파일 닫기
    fclose(file);

    return 0;
}