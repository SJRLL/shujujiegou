#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
       return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->_data = a[*pi];

	++(*pi);
	root->left=BinaryTreeCreate(a, pi);

	++(*pi);
	root->right=BinaryTreeCreate(a, pi);

	return root;
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return NULL;

	BinaryTreeDestory(root->left);
    BinaryTreeDestory(root->right);

	free(root);
	root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL  && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);

}

int BinaryTreeLevelKSize(BTNode* root,int k)
{
	if (root == NULL)
		return 0;

	if (k==1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);

}

 BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->_data == x)
		return root;

	int lret = BinaryTreeFind(root->left, x);
	if (root != NULL)
		return lret;

	int rret = BinaryTreeFind(root->right, x);
	if (root != NULL)
		return rret;

	return NULL;
}

//Ç°£¬ÖĞ£¬ºóĞò±éÀú
void BinaryTreePrevorder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevorder(root->left);
	
	BinaryTreePrevorder(root->right);
	
}

void BinaryTreeInorder(BTNode* root)
{
	if (root == NULL)
		return ;
	BinaryTreePrevorder(root->left);
	printf("%c ", root->_data);
	BinaryTreePrevorder(root->right);
	
}

void BinaryTreePostorder(BTNode* root)
{
	if (root == NULL)
		return ;
	BinaryTreePrevorder(root->left);
	
	BinaryTreePrevorder(root->right);
    printf("%c ", root->_data);
	
}

//·Çµİ¹é±éÀú
//²ãĞò±éÀú

//void BinaryTreeLevelorder(BTNode* root);
//
////ÅĞ¶Ï¶ş²æÊ÷ÊÇ·ñÎªÍêÈ«¶ş²æÊ÷
//int BinaryTreeCoplete(BTNode* root);
//void BinaryTreePrevOrderNonR(BTNode* root);
//
//void BinarytreePrevOreder(BTNode* root);
//void BinarytreeInOreder(BTNode* root);
//void BinarytreePostOreder(BTNode* root);

void TestBinaryTree()
{
	int i = 0;
	char a[] = "ABD##E##CF##G##";

	BTNode *root = NULL;
	root=BinaryTreeCreate(a, &i);

	//BinaryTreePrevorder(root);
	//printf("\n");
	//BinaryTreeInorder(root);
	//printf("\n");
	//BinaryTreePostorder(root);
	//printf("\n");

	//int num1 = BinaryTreeSize(root);
	//printf("%d ", num1);

	/*int num2 = BinaryTreeLeafSize(root);
	printf("%d ", num2);*/

	int num3 = BinaryTreeLevelKSize(root, 3);
	printf("%d ", num3);

	BTNode* num4 = BinaryTreeFind(root, 'D');
	printf("%c ", num4->_data);
}
