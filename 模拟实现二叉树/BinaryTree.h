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


//ͨ��ǰ�����������"ABD##E##CF##G##"����������

BTNode* BinaryTreeCreate(BTDataType* a, int* pi);

void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root);

BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//ǰ���У��������
void BinaryTreePrevorder(BTNode* root);
void BinaryTreeInorder(BTNode* root);
void BinaryTreePostorder(BTNode* root);

//�ǵݹ����
//�������

void BinaryTreeLevelorder(BTNode* root);

//�ж϶������Ƿ�Ϊ��ȫ������
int BinaryTreeCoplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);

void BinarytreePrevOreder(BTNode* root);
void BinarytreeInOreder(BTNode* root);
void BinarytreePostOreder(BTNode* root);

void TestBinaryTree();
