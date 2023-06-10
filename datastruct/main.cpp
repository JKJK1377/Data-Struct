#include "sequence_list.h"
#include "linklist.h"
#include "stack.h"
#include "class_queue.h"
#include "class_stack.h"
#include "bitree.h"
#include "huffman.h"
#include "graph.hpp"
int main() {
	//Sqlist* L = new Sqlist;
	//InitSL(L,3);
	//LocateElem(L, 2);

	//LNode* LN = new LNode;
	//InitLL(LN);
	//CreatLL_R(LN, 3);

	//PStack S = new SqStack;
	//InitStack(S);
	//Push(S, 'C');
	//Push(S, 'B');
	//Push(S, 'A');
	//while (!IsEmpty(S))
	//{
	//	StackElemType a;
	//	Pop(S,&a);
	//	printf("%c", a);
	//}

	//structstack::LinkStack L = new structstack::StackNode;
	//InitStack(L);
	//Push(L, 'A');
	//Push(L,'B');
	//Push(L, 'C');
	//while (!IsEmpty(L))//while Œ™true‘Ú÷¥––
	//{
	//	structstack::StackElemType e;
	//	Pop(L, &e);
	//	printf("%c \n", e);
	//}


	//SqQueue<char> q1;
	//LinkQueue<int> q2;
	//q1.IN('A');
	//q2.IN(3.14);
	//char a;
	//q1.OUT(&a);
	//printf("%c ", a);
	//int e;
	//q2.OUT(&e);
	//printf("%d \n", e);
	////delete &q1,&q2;            ???????????

	//classstack::SqStack<int> s1;
	//s1.Push(1);
	//printf("%d \n",s1.GetTop());
	//printf("%d \n", s1.Pop());
	//s1.Pop();
	//printf("%d \n", s1.IsEmpty());

	//classstack::LinkStack<char> l1;
	//l1.Push('A');
	//printf("%c \n", l1.Pop());

	//BiTree T = NULL;
	//Creat_BiTree_Pre(T);
	//InOrder(T);
	//printf("\n");
	//PreOrder(T);
	//printf("\n");
	//LevelOrer(T);


	AMGraph<char,int,int> G;
	G.Create_unAMG_unweight();
	//G.DFS_G();
	G.BFS_AMGraph();

	return OK;
}

