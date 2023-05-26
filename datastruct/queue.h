#pragma once
#include "define.h"

#define Qmaxsize 100
namespace structqueue {
	typedef char QElemType;
	typedef struct _SqQueue {
		QElemType* base;
		int front, rear;
	}SqQueue, * sqqueue;

	Status InitQueue(sqqueue& L);
	Status IN(sqqueue& L, QElemType e);
	Status OUT(sqqueue& L, QElemType* e);
	Status IsEmpty(sqqueue L);
	Status IsFull(sqqueue L);
	QElemType GetFront(sqqueue L);
	int LengthQueue(sqqueue L);

	typedef struct _QueueNode {
		QElemType data;
		_QueueNode* next;
	}QueueNode, * pQueueNode;
	typedef struct _LinkQueue {
		QueueNode* front;
		QueueNode* rear;
	}LinkQueue, * pLinkQueue;

	Status InitQueue(pLinkQueue& L);
	Status IN(pLinkQueue& L, QElemType e);
	Status OUT(pLinkQueue& L, QElemType* e);
}