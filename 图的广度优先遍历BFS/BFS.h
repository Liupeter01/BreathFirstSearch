#pragma once
#include"MGraph.h"
#include"LinkQueue.h"

void InitVisitArray(MGraph G, BOOL** visit);			  //��ʼ��BFS�㷨��������
void DestroyVisitArray(BOOL* visit);		//BFS�㷨�������������

void BFSTraverse(MGraph G, VertexType V);		  //BFS������ȱ�������
void BFS(MGraph G, LinkQueue queue, BOOL* visit, VertexType V);		   //BFS����ģ����е�ʵ��
