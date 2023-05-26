#include "LinkList.h"


Status InitLL(LinkList& L) {
	L = new LNode;
	L->next = nullptr;
	return OK;
}
//ʹ���������Ͳ��ܶԴ��ݵĲ���������в������޸�
//��������Ҫ�ں����ڲ��޸����������ʱ����Ҫʹ���������ͻ�ָ�����͵Ĳ���ʹ�ú��������޸�ԭ����
//��������ֻ����Ҫ������������������ʱ������Ҫ�޸�ԭ��������ֱ�Ӵ��ݿ�������
void CreatLL_H(LinkList& L, int n){
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void CreatLL_R(LinkList& L, int n) {
	LNode* r = L;
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		std::cin >> p->data;
		r->next = p;
		p->next = nullptr;
		r = p;
	}
}

LLElemtype GetElem(LinkList L, int position, LLElemtype* e) {
	LNode* p = L->next;
	int i = 1;
	if (position < 1 || !p)
		return ERROR;
	while (p && i<position)
	{
		p = p->next;
		i++;
	}
	if (!p)
		return ERROR;
	*e = p->data;
	return *e;
};

LinkList LocateElem(LinkList L, LLElemtype e) {
	LNode* p = L->next;
	while (p && e != p->data)
	{
		p = p->next;
	}
	if (!p)
		return NULL;
	return p;
};

Status LlInsert(LinkList& L, int position, LLElemtype e) {
	LNode* p = L;
	int i = 0;
	while (p && i<position-1)
	{
		i++;
		p = p->next;
	}
	if (!p || i > position - 1)
		return ERROR;
	LNode* n = new LNode;
	n->data = e;
	n->next = p->next;
	p->next = n;
	return OK;
};

Status LlDelete(LinkList& L, int position, LLElemtype* e) {
	LNode* p = L;
	int i = 0;
	while (p && i < position - 1)
	{
		i++;
		p = p->next;
	}
	if (!p || i > position - 1 || !p->next)
		return ERROR;
	LNode* dn = p->next;
	*e = dn->data;
	p->next = dn->next;
	delete(dn);
	return OK;
};

Status Traverse(LinkList L) {
	if (!L->next)
		return ERROR;
	LNode* p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}

Status LlDestroy(LinkList& L) {
	LNode* p = L;
	if (!p)
		return ERROR;
	while (p)
	{
		LNode* fp = p;
		p = p->next;
		delete(fp);
	}
	delete(L);
	return OK;
};

LinkList Merge_LinkedList(LinkList& La, LinkList& Lb, LinkList& Lc);