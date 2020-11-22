#pragma once
#include"MGraph.h"
#include"LinkQueue.h"

void InitVisitArray(MGraph G, BOOL** visit);			  //初始化BFS算法辅助数组
void DestroyVisitArray(BOOL* visit);		//BFS算法辅助数组的销毁

void BFSTraverse(MGraph G, VertexType V);		  //BFS广度优先遍历函数
void BFS(MGraph G, LinkQueue queue, BOOL* visit, VertexType V);		   //BFS基于模拟队列的实现
