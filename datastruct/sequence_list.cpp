#include "sequence_list.h"

#define _CRT_SECURE_NO_WARNINGS

Status InitSL(Sqlist* L, int length) {
	L->base = new SqlElemType[length];
	if (!L->base)
	{
		return OVERFLOW;
	}
	L->length = 0;
	for (int i = 1; i < length+1; i++)
	{
		SqlElemType e;
		scanf_s("%d",&e);
		SqlInsert(L, i, e);
	}
	return OK;
};

SqlElemType GetElem(Sqlist* L, int position, SqlElemType* e) {
	if (position < 1 || position > L->length)
		return ERROR;
	*e = L->base[position-1];
	return OK;
};

int LocateElem(Sqlist* L, SqlElemType e) {
	for (int i = 1; i <= L->length; i++)
	{
		if (e == L->base[i-1]) {
			//printf("%d", i);
			return i;
		}
	}
	return ERROR;
};

Status SqlInsert(Sqlist* L, int position, SqlElemType e) {
	if (position<1 || position > L->length+1 || L->length == MAXSIZE)
	{
		return ERROR;
	}
	for (int i = position-1; i >= position-1; i--)
	{
		L->base[i + 1] = L->base[i];
	}
	L->base[position - 1] = e;
	L->length++;
	return OK;
};
Status SqlDelete(Sqlist* L, int position) {
	if (position < 1 || position > L->length)
		return ERROR;
	for (int i = position; i < L->length; i++)
	{
		L->base[position - 1] = L->base[position];
	}
	L->length--;
	return OK;
};

Status SqlDestory(Sqlist* L) {
	if (L->base != NULL)
	{
		delete(L);
		return OK;
	}
	return ERROR;
};

Status SqlClear(Sqlist* L) {
	L->length = 0;
	return OK;
};

Status SqlIsEmpty(Sqlist* L) {
	if (L->length == 0)
	{
		return TRUE;
	}
	return FALSE;
};

Status MergeList(Sqlist* La, Sqlist* Lb) {
	int l = La->length;
	La->length = La->length + Lb->length;
	for (int i = 0; i < Lb->length; i++)
	{
		La->base[l + i] = Lb->base[i];
	}
	delete(Lb);
	return OK;
};

void Traverse(Sqlist* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d", L->base[i]);
	}
};

void MergeList_Seq(Sqlist* La, Sqlist* Lb, Sqlist* Lc) {
	Lc->length = La->length + Lb->length;
	SqlElemType* pa = La->base, * pa_last = pa + La->length - 1;
	// pa指向La->base的首地址，pa_last指向base中最后一个元素的地址，下面同理
	SqlElemType* pb = Lb->base, * pb_last = pb + Lb->length - 1;
	SqlElemType* pc = Lc->base;
	while (pa <= pa_last && pb <= pb_last) {
		//当pa>pa_last时说明，有集合中的元素已经全部加入到Lc中,*pa为La中的元素值
		if (*pa < *pb)
			*(pc++) = *(pa++);  //先赋值再++，指向下一个元素
		else
			*(pc++) = *(pb++);
	}
	while (pa <= pa_last)
		*(pc++) = *(pa++); //判断La的元素是否全部加入Lc中，下面同理
	while (pb <= pb_last)
		*(pc++) = *(pb++);
};