#include "bitree.h"

void Creat_BiTree_Pre(BiTree& T) {
	char c;
	std::cin >> c;
	if ('#' == c)
		T = NULL;
	else
	{
		T = new BiNode;
		T->data = c;
		Creat_BiTree_Pre(T->lchild);
		Creat_BiTree_Pre(T->rchild);
	}
};
//中序遍历 左根右
void InOrder(BiTree T) {  
	if (!T)
		return ;
	InOrder(T->lchild);
	printf("%c", T->data);
	InOrder(T->rchild);
};
//前序遍历 根左右
void PreOrder(BiTree T) {
	if (!T)
		return; 
	printf("%c", T->data);
	PreOrder(T->lchild);
	PreOrder(T->rchild);
};
//后序 左右根
void PostOrder(BiTree T) {
	if (!T)
		return;
	PreOrder(T->lchild);
	PreOrder(T->rchild);
	printf("%c", T->data);
};
void LevelOrer(BiTree T) {
	BiTree temp = NULL;
	classqueue::SqQueue<BiTree> Q;
	if (T)
		Q.IN(T);
	while (!Q.IsEmpty())
	{
		Q.OUT(&temp);
		std::cout << temp->data;
		if (temp->lchild)
			Q.IN(temp->lchild);
		if (temp->rchild)
			Q.IN(temp->rchild);
	}
};
void Copy(BiTree& Tnew, const BiTree T) {
	if (!T)
	{
		Tnew = NULL;
		return;
	}
	else
	{
		Tnew = new BiNode;
		Tnew->data = T->data;
		Copy(Tnew->lchild,T->lchild);
		Copy(Tnew->rchild, T->rchild);
	}
};
int Depth(BiTree T) {
	if (!T)
		return 0;
	else
	{
		return Depth(T->lchild) > Depth(T->rchild) ? Depth(T->lchild) + 1 : Depth(T->rchild) + 1;
	}
};
int Nodes(BiTree T) {
	if (!T)
		return 0;
	else
	{
		return 1 + Nodes(T->lchild) + Nodes(T->rchild);
	}
};
void Destroy_unrec(BiTree* root);
void Destroy(BiTree& root) {
	if (!root)
		return;
	else
	{
		Destroy(root->lchild);
		Destroy(root->rchild);
		delete(root);
		root = NULL;
	}
};