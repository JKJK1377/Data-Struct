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
		if (T[i].parent == 0) { //! parent==0 说明在森林中
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
	int m = 2 * n - 1; //定理2
	T = new HTNode[m+1]; // 0号位置不存元素
	for (int i = 1; i < m + 1; ++i) { //进行初始化
		T[i].lchild = T[i].rchild = 0;
		T[i].parent = 0;
	}
	for (int i = 1; i < n + 1; ++i) { //赋值weight
		scanf(" %d", &(T[i].weight));
	}
	//-------------------初始化完毕，开始构造--------------------------
	int min1, min2; //表示第一小和第二小的位置
	for (int i = n + 1; i < m + 1; ++i) { // n+1号位置为新构造的节点下标
		Select_Min(T, i - 1, &min1, &min2); //! 核心语句 动态的选择大小
		T[min1].parent = T[min2].parent = i; //合并
		T[i].lchild = min1; //新节点的左右孩子
		T[i].rchild = min2;
		T[i].weight = T[min1].weight + T[min2].weight; //赋值权值
	}
};
HuffmanCode Creat_HuffmanCode(const HTree HT, int n) {
	// HC和哈夫曼树一样，不使用0号下标
	HuffmanCode HC = (char**)malloc(sizeof(char*) * (n + 1));
	char* temp_string = (char*)malloc(sizeof(char) * n); //此数组使用0号下标
	temp_string[n - 1] = '\0'; //因为存放字符串所以最后一个位置 '\0'
	for (int i = 1; i < n + 1; ++i) {
		int parent = HT[i].parent; //需要向上回溯
		int current = i; //回溯中当前节点
		int start = n - 1; //数组中最后一个位置，即'\0'
		while (parent) {
			if (current == HT[parent].lchild) //如果是左孩子，那么为'0'
				temp_string[--start] = '0';
			else
				temp_string[--start] = '1'; //右孩子为 '1'
			current = parent;
			parent = HT[parent].parent;
		}
		//计算长度:因为strat表示字符串的起始下标，n-1表示末尾结束符'\0',所以 length
		//= n-1-start+1=n-start;
		HC[i] = (char*)malloc(sizeof(char) * (n - start)); //根据长度分配空间
		strcpy(HC[i], &temp_string[start]); //拷贝字符串
	}
	free(temp_string); //释放堆空间
	return HC;
};
#endif
