#pragma once
#include "define.h"
#include <stdio.h>
#define MAXSIZE 100

typedef int SqlElemType;
typedef struct Squence {
	SqlElemType* base;
	int length;
}Sqlist;

Status InitSL(Sqlist* L,int length);
SqlElemType GetElem(Sqlist* L, int position, SqlElemType* e);
int LocateElem(Sqlist* L, SqlElemType e);
Status SqlInsert(Sqlist* L, int position, SqlElemType e);
Status SqlDelete(Sqlist* L, int position);
Status SqlDestory(Sqlist* L);
Status SqlClear(Sqlist* L);
Status SqlIsEmpty(Sqlist* L);
Status MergeList(Sqlist* La, Sqlist* Lb);
void Traverse(Sqlist* L);
void MergeList_Seq(Sqlist* La, Sqlist* Lb, Sqlist* Lc);