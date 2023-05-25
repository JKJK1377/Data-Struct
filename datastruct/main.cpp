#include "sequence_list.h"
#include "linklist.h"
#include "stack.h"
int main() {
	//Sqlist* L = new Sqlist;
	//InitSL(L,3);
	//LocateElem(L, 2);

	//LNode* LN = new LNode;
	//InitLL(LN);
	//CreatLL_R(LN, 3);

	PStack S = new SqStack;
	InitStack(S);
	Push(S, 'C');
	Push(S, 'B');
	Push(S, 'A');
	while (!IsEmpty(S))
	{
		StackElemType a;
		Pop(S,&a);
		printf("%c", a);
	}

	LinkStack L = new StackNode;
	InitStack(L);
	Push(L, 'A');
	Push(L,'B');
	Push(L, 'C');
	while (!IsEmpty(L))//while Œ™true‘Ú÷¥––
	{
		StackElemType e;
		Pop(L, &e);
		printf("%c", e);
	}
	return OK;
}