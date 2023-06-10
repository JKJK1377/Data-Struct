#pragma once
#include "define.h"
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include "class_queue.h"

#define MAXWEIGHT 99999 //���Ȩֵ
#define MAXVERTEX 20 //��󶥵���
#ifndef __Graph
#define __Graph

template <typename T,typename M,typename W>
class AMGraph
{
private:
	T vertex[MAXVERTEX];
	M arcs[MAXVERTEX][MAXVERTEX];
	int vexnum, arcnum;
public:
	AMGraph(){};
	~AMGraph(){};

	int LocateVex(T v) {
		if (!vertex)
			return -1;
		for (int i = 0; i < vexnum; ++i)
		{
			if (v == vertex[i])
				return i;
		}
		return -1;
	};
	//������Ȩͼ
	Status Create_unAMG_weight() {
		std::cin >> vexnum >> arcnum;
		for (int i = 0; i < vexnum; ++i)
			std::cin >> vertex[i];
		for (int i = 0; i < vexnum; ++i)
			for (int j = 0; j < vexnum; ++j)
				arcs[i][j] = MAXWEIGHT;

		T v1, v2;
		W w;
		for (int k = 0; k < arcnum; ++k)
		{
			std::cin >> v1 >> v2 >> w;
			int i = LocateVex(v1);
			int j = LocateVex(v2);
			arcs[i][j] = w;
			arcs[j][i] = w;
		}
		return OK;
	};

	//������Ȩͼ
	Status Create_unAMG_unweight() {
		std::cin >> vexnum >> arcnum;
		for (int i = 0; i < vexnum; ++i)
			std::cin >> vertex[i];
		for (int i = 0; i < vexnum; ++i)
			for (int j = 0; j < vexnum; ++j)
				arcs[i][j] = 0;

		T v1, v2;
		for (int k = 0; k < arcnum; ++k)
		{
			std::cin >> v1 >> v2;
			int i = LocateVex(v1);
			int j = LocateVex(v2);
			arcs[i][j] = 1;
			arcs[j][i] = 1;
		}
		return OK;
	}

	//������Ȩͼ������ͼ���󲻶Գ�
	//����ͼ���б�ʾ���ȱߣ�β�����б�ʾ��ȱߣ�ͷ��
	Status Create_AMG_weight() {
		std::cin >> vexnum >> arcnum;
		for (int i = 0; i < vexnum; ++i)
			std::cin >> vertex[i];
		for (int i = 0; i < vexnum; ++i)
			for (int j = 0; j < vexnum; ++j)
				arcs[i][j] = MAXWEIGHT;

		T v1, v2;
		W w;
		for (int k = 0; k < arcnum; ++k)
		{
			std::cin >> v1 >> v2 >> w;
			int i = LocateVex(v1);
			int j = LocateVex(v2);
			arcs[i][j] = w;
		}
		return OK;
	};

	//������Ȩͼ
	Status Create_AMG_unweight() {
		std::cin >> vexnum >> arcnum;
		for (int i = 0; i < vexnum; ++i)
			std::cin >> vertex[i];
		for (int i = 0; i < vexnum; ++i)
			for (int j = 0; j < vexnum; ++j)
				arcs[i][j] = 0;

		T v1, v2;
		for (int k = 0; k < arcnum; ++k)
		{
			std::cin >> v1 >> v2;
			int i = LocateVex(v1);
			int j = LocateVex(v2);
			arcs[i][j] = 1;
		}
		return OK;
	}
	//������ȱ���
	void DFS(int v, bool* visited) {
		std::cout << vertex[v];
		visited[v] = TRUE;
		for (int i = 0; i < vexnum; ++i)
		{
			if ((arcs[v][i] != 0) && (!visited[i])) //
				DFS(i, visited);
		}
	}
	void DFS_G() {
		T v;
		std::cin >> v;
		bool* visited = (bool*)malloc(sizeof(bool) * vexnum);
		memset(visited, FALSE, sizeof(bool) * vexnum);
		int index = LocateVex(v);
		DFS(index, visited);
	}
	

	//������ȱ���
	void BFS(int v, bool* visited) {
		classqueue::SqQueue<int> Q;
		Q.IN(v);
		visited[v] = TRUE;
		int pop;
		while (!Q.IsEmpty())
		{
			Q.OUT(&pop);
			std::cout << vertex[pop];
		}
		for (int k = 0; k < vexnum; ++k) {
			if (arcs[pop][k] && !visited[k]) {
				Q.IN(k);
				visited[k] = true;
			}
		}
	}
	void BFS_AMGraph() {
		T v;
		std::cin >> v;
		bool* visit = (bool*)malloc(sizeof(bool) * vexnum); //Ϊvisit����ռ�
		memset(visit, FALSE, sizeof(bool) * vexnum); //��ʼ��Ϊfalse
		int index = LocateVex(v); //�ҵ��±�
		BFS(index, visit); //�Դ��±�Ϊ�������������
		free(visit);
	}
};

//template <typename T, typename M, typename W>  ����д��
//int AMGraph<T,M,W>::LocateVex(T v) {
//	if (!vertex)
//		return -1;
//	for (int i = 0; i < vexnum; ++i)
//	{
//		if (v == vertex[i])
//			return i;
//	}
//	return -1;
//}

//template <typename T, typename M, typename W>    ����д��
//Status AMGraph<T, M, W>::CreateAMG_weight() {
//	std::cin >> vexnum >> arcnum;
//	for (int i = 0; i < vexnum; ++i)
//		std::cin >> vertex[i];
//	for (int i = 0; i < vexnum; ++i)
//		for (int j = 0; j < vexnum; ++j)
//			arcs[i][j] = MAXWEIGHT;
//
//	T v1, v2;
//	W w;
//	for (int k = 0; k < arcnum; ++k)
//	{
//		std::cin >> v1 >> v2 >> w;
//		int i = LocateVex(v1);
//		int j = LocateVex(v2);
//		arcs[i][j] = w;
//		arcs[j][i] = w;
//	}
//	return OK;
//}


struct ArcNode {
	int adjvertex;
	ArcNode* next;
	int weight;
} ;
template <typename T>
struct ALGNode {
	T data;
	ArcNode* first;
};
template <typename T>
class ALGraph //����ͼ�ռ临�Ӷ�O��n+2e�� ����ͼ n+e���ҳ������ף�����ѣ����ڽӱ�
{
private:
	ALGNode<T> vertex[MAXVERTEX];
	int edges, vertices;
public:
	ALGraph(){};
	~ALGraph(){};
	int Locate_vertex(T v) {
		for (int i = 0; i < vertices; ++i)
		{
			if (v == vertex[i])
				return i;
		}
		return -1;
	};
	void print_ALG_unweighted(){};
	void print_ALG_weighted(){};
	void Creat_unALGraph_unweighted() {
		std::cin >> edges >> vertices;
		for (int i = 0; i < vertices; ++i)
		{
			std::cin >> vertex[i].data;
			vertex[i].first = NULL;
		}
		T v1, v2;
		for (int k = 0; k < edges; ++k)
		{
			std::cin >> v1 >> v2;
			int i = Locate_vertex(v1);
			int j = Locate_vertex(v2);
			ArcNode* N = new ArcNode;
			N->adjvertex = j;
			N->next = vertex[i].first;
			N->weight = NULL;
			vertex[i].first = N;
			//�����������Ҫ
			ArcNode* Np = new ArcNode;
			Np->adjvertex = i;
			Np->next = vertex[j].first;
			Np->weight = NULL;
			vertex[j].first = Np;
		}
	};
	void Creat_ALGraph_unweighted() {
		std::cin >> edges >> vertices;
		for (int i = 0; i < vertices; ++i)
		{
			std::cin >> vertex[i].data;
			vertex[i].first = NULL;
		}
		T v1, v2;
		for (int k = 0; k < edges; ++k)
		{
			std::cin >> v1 >> v2;
			int i = Locate_vertex(v1);
			int j = Locate_vertex(v2);
			ArcNode* N = new ArcNode;
			N->adjvertex = j;
			N->next = vertex[i].first;
			N->weight = NULL;
			vertex[i].first = N;
			//�����ֻ��Ҫ����
		}
	};
	void Creat_unALGraph_weighted() {
		std::cin >> edges >> vertices;
		for (int i = 0; i < vertices; ++i)
		{
			std::cin >> vertex[i].data;
			vertex[i].first = NULL;
		}
		T v1, v2;
		int w;
		for (int k = 0; k < edges; ++k)
		{
			std::cin >> v1 >> v2 >> w;
			int i = Locate_vertex(v1);
			int j = Locate_vertex(v2);
			ArcNode* N = new ArcNode;
			N->adjvertex = j;
			N->next = vertex[i].first;
			N->weight = w;
			vertex[i].first = N;
			//�����������Ҫ
			ArcNode* Np = new ArcNode;
			Np->adjvertex = i;
			Np->next = vertex[j].first;
			Np->weight = w;
			vertex[j].first = Np;
		}
	};
	void Creat_ALGraph_weighted() {
		std::cin >> edges >> vertices;
		for (int i = 0; i < vertices; ++i)
		{
			std::cin >> vertex[i].data;
			vertex[i].first = NULL;
		}
		T v1, v2;
		int w;
		for (int k = 0; k < edges; ++k)
		{
			std::cin >> v1 >> v2 >> w;
			int i = Locate_vertex(v1);
			int j = Locate_vertex(v2);
			ArcNode* N = new ArcNode;
			N->adjvertex = j;
			N->next = vertex[i].first;
			N->weight = w;
			vertex[i].first = N;
		}
	};

};


#endif // !__Graph
