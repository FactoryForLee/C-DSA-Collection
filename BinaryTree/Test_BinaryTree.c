#include "BinaryTree.h"

int main()
{
	SBTNode* First = SBT_CreateNode("1st");
	SBTNode* Second = SBT_CreateNode("2nd");
	SBTNode* third = SBT_CreateNode("3rd");
	SBTNode* fourth = SBT_CreateNode("4th");
	SBTNode* fifth = SBT_CreateNode("5th");
	SBTNode* sixth = SBT_CreateNode("6th");
	SBTNode* seventh = SBT_CreateNode("7th");

	// Left sub tree
	First->Left = Second;
	Second->Left = third;
	Second->Right = fourth;

	// Right sub tree
	First->Right = fifth;
	fifth->Left = sixth;
	fifth->Right = seventh;

	printf("===== Preorder =====\n");
	SBT_PreorderPrintTree(First);
	printf("\n\n");

	printf("===== Inorder ======\n");
	SBT_InorderPrintTree(First);
	printf("\n\n");

	printf("===== Postorder ====\n");
	SBT_PostorderPrintTree(First);
	printf("\n\n");

	SBT_DestroyTree(First);

	return 0;
}