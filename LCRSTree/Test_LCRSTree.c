#include "LCRSTree.h"

int main(void)
{
	// 노드 생성
	LCRSNode* Root = LCRS_CreateNode('A');
	LCRSNode* B = LCRS_CreateNode('B');
	LCRSNode* C = LCRS_CreateNode('C');
	LCRSNode* D = LCRS_CreateNode('D');
	LCRSNode* E = LCRS_CreateNode('E');
	LCRSNode* F = LCRS_CreateNode('F');
	LCRSNode* G = LCRS_CreateNode('G');
	LCRSNode* H = LCRS_CreateNode('H');
	LCRSNode* I = LCRS_CreateNode('I');
	LCRSNode* J = LCRS_CreateNode('J');
	LCRSNode* K = LCRS_CreateNode('K');
	LCRSNode* L = LCRS_CreateNode('L');
	LCRSNode* M = LCRS_CreateNode('M');

	// 트리에 노드 추가 (자식 관계를 나타내기 위해 코드 들여쓰기)
	LCRS_AddChildNode(Root, B);
	LCRS_AddChildNode(B, C);
	LCRS_AddChildNode(C, D);
	LCRS_AddChildNode(C, E);
	LCRS_AddChildNode(B, F);
	LCRS_AddChildNode(F, G);
	LCRS_AddChildNode(F, H);

	LCRS_AddChildNode(Root, I);
	LCRS_AddChildNode(I, J);

	LCRS_AddChildNode(Root, K);
	LCRS_AddChildNode(K, L);
	LCRS_AddChildNode(L, M);

	// 트리 출력
	LCRS_PrintTree(Root, 0);

	LCRS_PrintNodeAtLevel(Root, 2);

	// 트리 소멸
	LCRS_DestroyTree(Root);
}