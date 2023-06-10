#pragma once
#include "define.h"
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include "class_queue.h"

#define MAXWEIGHT 99999 //最大权值
#define MAXVERTEX 20 //最大顶点数
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
	//无向有权图
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

	//无向无权图
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

	//有向有权图，有向图矩阵不对称
	//有向图的行表示出度边（尾），列表示入度边（头）
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

	//有向无权图
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
	//深度优先遍历
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
	

	//广度优先遍历
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
		bool* visit = (bool*)malloc(sizeof(bool) * vexnum); //为visit分配空间
		memset(visit, FALSE, sizeof(bool) * vexnum); //初始化为false
		int index = LocateVex(v); //找到下标
		BFS(index, visit); //以此下标为顶点出发，遍历
		free(visit);
	}
};

//template <typename T, typename M, typename W>  类外写法
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

//template <typename T, typename M, typename W>    类外写法
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
class ALGraph //无向图空间复杂度O（n+2e） 有向图 n+e，找出度容易，入度难，逆邻接表
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
			//无向表两链表都要
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
			//有向表只需要单边
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
			//无向表两链表都要
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
