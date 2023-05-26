#include "stack.h"
#include <cstddef>
namespace structstack {
	Status InitStack(PStack& L) {
		L->base = new StackElemType;
		L->top = L->base;
		L->stacksize = MaxSize;
		return OK;
	};
	Status Push(PStack& L, StackElemType e) {
		if (L->top - L->base == L->stacksize)
			return ERROR;
		*(L->top++) = e;
		return OK;
	};
	Status Pop(PStack& L, StackElemType* e) {
		if (L->top == L->base)
			return ERROR;
		*e = *(--(L->top));  //top指向地址为空
		return OK;
	};
	Status IsEmpty(PStack L) {
		if (L->top == L->base)
			return TRUE;
		else
			return FALSE;
	};
	Status IsFull(PStack L) {
		if (L->top - L->base == L->stacksize)
			return TRUE;
		else
			return FALSE;
	};
	StackElemType GetTop(PStack L) {
		if (!IsEmpty(L))
			return *(L->top - 1);
		else
			return ERROR;
	};


	//--------------------------------------
	Status InitStack(LinkStack& L) {
		L = NULL;
		return OK;
	};
	Status Push(LinkStack& L, StackElemType e) {
		LinkStack p = new StackNode;
		p->data = e;
		p->next = L;
		L = p;
		return OK;
	};
	Status Pop(LinkStack& L, StackElemType* e) {
		LinkStack p = L;
		*e = L->data;
		L = L->next;
		delete(p);
		return OK;
	}
	Status IsEmpty(LinkStack L) {
		if (L == NULL)
			return TRUE;
		else
			return FALSE;
	};
	StackElemType GetTop(LinkStack L) {
		if (L)
			return L->data;
	};
}