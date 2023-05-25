#pragma once
#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifndef __LINKLIST_H
#define __LINKLIST_H

typedef int LLElemtype;
typedef struct LNode {
	LLElemtype data;
	LNode* next;
}LNode, *LinkList;

Status InitLL(LinkList& L);
void CreatLL_H(LinkList& L, int n);
void CreatLL_R(LinkList& L, int n);
LLElemtype GetElem(LinkList L, int position, LLElemtype* e);
LinkList LocateElem(LinkList L, LLElemtype e);
Status LlInsert(LinkList& L, int position, LLElemtype e);
Status LlDelete(LinkList& L, int position, LLElemtype* e);
Status Traverse(LinkList L);
Status LlDestroy(LinkList& L);
LinkList Merge_LinkedList(LinkList& La, LinkList& Lb, LinkList& Lc);
#endif // !__LINKLIST_H£¬avoid include repeat

