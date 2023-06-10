#pragma once
#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "stack.h"
#include "class_queue.h"

typedef char BitreeElemType;
typedef struct __BiNode {
	BitreeElemType data;
	__BiNode *lchild, *rchild;
} BiNode, *BiTree;
void Creat_BiTree_Pre(BiTree& T);
void InOrder(BiTree T);
void InOrder_unrec(BiTree T);
void PreOrder(BiTree T);
void PostOrder(BiTree T);
void LevelOrer(BiTree T);
void Copy(BiTree& Tnew, const BiTree T);
int Depth(BiTree T);
int Nodes(BiTree T);
void Destroy_unrec(BiTree* root);
void Destroy(BiTree& root);