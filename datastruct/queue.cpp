#include "queue.h"
namespace structqueue {
	Status InitQueue(sqqueue& L) {
		L->base = new QElemType;
		L->front = L->rear = 0;
		return OK;
	};
	Status IN(sqqueue& L, QElemType e) {
		if (L->front == (L->rear + 1) % Qmaxsize)
			return OVERFLOW;
		L->base[L->rear] = e;
		L->rear = (L->rear + 1) % Qmaxsize;
		return OK;
	};
	Status OUT(sqqueue& L, QElemType* e) {
		if (L->front == L->rear)
			return ERROR;
		*e = L->base[L->front];
		L->front = (L->front + 1) % Qmaxsize;
		return OK;
	};
	Status IsEmpty(sqqueue L) {
		if (L->front == L->rear)
			return TRUE;
		else
			return FALSE;
	};
	Status IsFull(sqqueue L) {
		if (L->front == (L->rear + 1) % Qmaxsize)
			return TRUE;
		else
			return FALSE;
	};
	QElemType GetFront(sqqueue L) {
		if (IsEmpty(L))
			return ERROR;
		else
			return L->base[L->front];
	};
	int LengthQueue(sqqueue L) {
		return (L->rear - L->front + Qmaxsize) % Qmaxsize;
	};


	//------------------------------------------------
	Status InitQueue(pLinkQueue& L) {
		if (!(L->front = L->rear = new QueueNode))
			return ERROR;
		L->front->next = nullptr;
		return OK;
	};
	Status IN(pLinkQueue& L, QElemType e) {
		pQueueNode n = new QueueNode;
		n->data = e;
		n->next = nullptr;
		L->rear->next = n;
		L->rear = n;
		return OK;
	};
	Status OUT(pLinkQueue& L, QElemType* e) {
		if (L->rear == L->front)
			return ERROR;
		pQueueNode p = L->front->next;
		*e = p->data;
		L->front->next = p->next;
		if (L->rear == p)//若p为队尾，删除后rear指向不明,
			L->rear = L->front;
		delete(p);
		return OK;
	};
}