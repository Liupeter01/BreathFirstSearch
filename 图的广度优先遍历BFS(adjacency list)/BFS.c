#include"BFS.h"

void InitVisitArray(ALGraph G, BOOL** visit)			  //��ʼ��BFS�㷨��������
{
          *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
          memset(*visit, FALSE, sizeof(BOOL) * G.vexnum);
}

void DestroyVisitArray(BOOL* visit)	//BFS�㷨�������������
{
          free(visit);
}

void BFSTraverse(ALGraph G, VertexType V)	  //BFS������ȱ�������
{
          BOOL* visit = NULL;           //��������
          InitVisitArray(G, &visit);               //��ʼ��BFS�㷨��������

          LinkQueue queue;              //����
          InitLinkQueue(&queue);
          BFS(G, queue, visit, V);
            for (int i = 0; i < G.vexnum; ++i)
            {
                    if (!visit[i])       //�ö���û������
                    {
                              BFS(G, queue, visit, G.Vetics[i].data);
                    }
            }
            printf("END\n");
            DestroyVisitArray(visit);             //���ٸ�������
            DestroyLinkQueue(&queue);             //���ٶ���
}

void BFS(ALGraph G, LinkQueue queue, BOOL* visit, VertexType V)	   //BFS����ģ����е�ʵ��
{
          EnQueue(&queue, V);
          visit[LocateVertex(G, V)] = TRUE;       //�Ѿ�������
          while (!IsQueueEmpty(queue))             //���в���
          {
                    VertexType temp;
                    DeQueue(&queue, &temp);       //����
                    printf("%c-->", temp);
                    for (int pos = FindFirstNeighbor(G, temp); pos != -1; pos = FindNextNeighbor(G, temp, pos))
                    {
                              if (!visit[pos])
                              {
                                        visit[pos] = TRUE;
                                        EnQueue(&queue, G.Vetics[pos].data);
                              }
                    }
          }
}