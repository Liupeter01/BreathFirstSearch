#include"BFS.h"

void InitVisitArray(MGraph G, BOOL** visit)			  //��ʼ��BFS�㷨��������
{
          *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
          memset(*visit, FALSE, sizeof(BOOL) * G.vexnum);
}

void DestroyVisitArray(BOOL* visit)	//BFS�㷨�������������
{
          free(visit);
}

void BFSTraverse(MGraph G, VertexType V)		  //BFS������ȱ�������
{
          BOOL* visit = NULL;            //��������
          InitVisitArray(G, &visit);              //��ʼ��DFS�㷨��������

          LinkQueue queue;              //����
          InitLinkQueue(&queue);        //��ʼ������
          BFS(G, queue, visit, V);                //ִ��һ��BFS
          for (int i = 0; i < G.vexnum; ++i)
          {
                    if (!visit[i])       //�ö���û������
                    {
                              BFS(G, queue, visit, G.Vex[i]);
                    }
          }
          printf("END\n");
          DestroyLinkQueue(&queue);               //�ݻٶ���
          DestroyVisitArray(visit);               //bFS�㷨�������������
}

void BFS(MGraph G, LinkQueue queue, BOOL* visit, VertexType V)		   //BFS����ģ����е�ʵ��
{
          visit[LocateVertex(G,V)] = TRUE;        //����V��λ���Ѿ�������
          EnQueue(&queue, V);           //���
          while (!IsQueueEmpty(queue))
          {
                    VertexType temp;
                    DeQueue(&queue, &temp);  //����
                    printf("%c-->", temp);
                    for (int pos = FindFirstNeighbor(G, temp); pos != -1; pos = FindNextNeighbor(G, temp, G.Vex[pos]))      //�����ڽӵ�
                    {
                              if (!visit[pos])            //visit�����л�û�б����ʹ�
                              {
                                        visit[pos] = TRUE;        //�Ѿ����ʹ�
                                        EnQueue(&queue, G.Vex[pos]);       //�������
                              }
                    }
          }
}