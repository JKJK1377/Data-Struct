#pragma once
#include "define.h"
#include <string.h>
#include <climits>
#include <stdio.h>
#include <corecrt_malloc.h>
#pragma warning(disable:4996)
#ifndef __HUFFMANTREE_H
#define __HUFFMANTREE_H

typedef struct __HTNode {
	int weight;
	int parent, lchild, rchild;
} HTNode, * HTree;
typedef char** HuffmanCode;
void Select_Min(const HTree T, int length, int* e1, int* e2) {
	int min1, min2;
	min1 = min2 = INT_MAX;
	int pos1, pos2;
	pos1 = pos2 = 0;
	for (int i = 1; i < length + 1; ++i) {
		if (T[i].parent == 0) { //! parent==0 ˵����ɭ����
			if (T[i].weight < min1) {
				min2 = min1;
				pos2 = pos1;
				min1 = T[i].weight;
				pos1 = i;
			}
			else if (T[i].weight < min2) {
				min2 = T[i].weight;
				pos2 = i;
			}
		}
	}
	*e1 = pos1;
	*e2 = pos2;
};
void Creat_Huffman(HTree& T, int n) {
	if (n <= 1)
		return;
	int m = 2 * n - 1; //����2
	T = new HTNode[m+1]; // 0��λ�ò���Ԫ��
	for (int i = 1; i < m + 1; ++i) { //���г�ʼ��
		T[i].lchild = T[i].rchild = 0;
		T[i].parent = 0;
	}
	for (int i = 1; i < n + 1; ++i) { //��ֵweight
		scanf(" %d", &(T[i].weight));
	}
	//-------------------��ʼ����ϣ���ʼ����--------------------------
	int min1, min2; //��ʾ��һС�͵ڶ�С��λ��
	for (int i = n + 1; i < m + 1; ++i) { // n+1��λ��Ϊ�¹���Ľڵ��±�
		Select_Min(T, i - 1, &min1, &min2); //! ������� ��̬��ѡ���С
		T[min1].parent = T[min2].parent = i; //�ϲ�
		T[i].lchild = min1; //�½ڵ�����Һ���
		T[i].rchild = min2;
		T[i].weight = T[min1].weight + T[min2].weight; //��ֵȨֵ
	}
};
HuffmanCode Creat_HuffmanCode(const HTree HT, int n) {
	// HC�͹�������һ������ʹ��0���±�
	HuffmanCode HC = (char**)malloc(sizeof(char*) * (n + 1));
	char* temp_string = (char*)malloc(sizeof(char) * n); //������ʹ��0���±�
	temp_string[n - 1] = '\0'; //��Ϊ����ַ����������һ��λ�� '\0'
	for (int i = 1; i < n + 1; ++i) {
		int parent = HT[i].parent; //��Ҫ���ϻ���
		int current = i; //�����е�ǰ�ڵ�
		int start = n - 1; //���������һ��λ�ã���'\0'
		while (parent) {
			if (current == HT[parent].lchild) //��������ӣ���ôΪ'0'
				temp_string[--start] = '0';
			else
				temp_string[--start] = '1'; //�Һ���Ϊ '1'
			current = parent;
			parent = HT[parent].parent;
		}
		//���㳤��:��Ϊstrat��ʾ�ַ�������ʼ�±꣬n-1��ʾĩβ������'\0',���� length
		//= n-1-start+1=n-start;
		HC[i] = (char*)malloc(sizeof(char) * (n - start)); //���ݳ��ȷ���ռ�
		strcpy(HC[i], &temp_string[start]); //�����ַ���
	}
	free(temp_string); //�ͷŶѿռ�
	return HC;
};
#endif
