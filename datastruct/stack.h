#pragma once
#include "define.h"
namespace structstack{
	typedef char StackElemType;
#define MaxSize 100
	typedef struct _SqStack {
		StackElemType* base;
		StackElemType* top;
		int stacksize;
	}SqStack, * PStack;

	Status InitStack(PStack& L);
	Status Push(PStack& L, StackElemType e);
	Status Pop(PStack& L, StackElemType* e);
	Status IsEmpty(PStack L);
	Status IsFull(PStack L);
	StackElemType GetTop(PStack L);

	typedef struct _StackNode {
		StackElemType data;
		_StackNode* next;
	}StackNode, * LinkStack;

	Status InitStack(LinkStack& L);
	Status Push(LinkStack& L, StackElemType e);
	Status Pop(LinkStack& L, StackElemType* e);
	Status IsEmpty(LinkStack L);
	StackElemType GetTop(LinkStack L);
}