#pragma once
#include"ALGraph.h"
#include"LinkQueue.h"

void InitVisitArray(ALGraph G, BOOL** visit);			  //��ʼ��BFS�㷨��������
void DestroyVisitArray(BOOL* visit);		//BFS�㷨�������������

void BFSTraverse(ALGraph G, VertexType V);		  //BFS������ȱ�������
void BFS(ALGraph G, LinkQueue queue, BOOL* visit, VertexType V);		   //BFS����ģ����е�ʵ��