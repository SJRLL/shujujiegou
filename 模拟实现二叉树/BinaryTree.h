#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType _data;
}BTNode;


//通过前序遍历的数组"ABD##E##CF##G##"构建二叉树

BTNode* BinaryTreeCreate(BTDataType* a, int* pi);

void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root);

BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//前，中，后序遍历
void BinaryTreePrevorder(BTNode* root);
void BinaryTreeInorder(BTNode* root);
void BinaryTreePostorder(BTNode* root);

//非递归遍历
//层序遍历

void BinaryTreeLevelorder(BTNode* root);

//判断二叉树是否为完全二叉树
int BinaryTreeCoplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);

void BinarytreePrevOreder(BTNode* root);
void BinarytreeInOreder(BTNode* root);
void BinarytreePostOreder(BTNode* root);

void TestBinaryTree();
