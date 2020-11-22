#include"BFS.h"

void InitVisitArray(ALGraph G, BOOL** visit)			  //初始化BFS算法辅助数组
{
          *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
          memset(*visit, FALSE, sizeof(BOOL) * G.vexnum);
}

void DestroyVisitArray(BOOL* visit)	//BFS算法辅助数组的销毁
{
          free(visit);
}

void BFSTraverse(ALGraph G, VertexType V)	  //BFS广度优先遍历函数
{
          BOOL* visit = NULL;           //辅助数组
          InitVisitArray(G, &visit);               //初始化BFS算法辅助数组

          LinkQueue queue;              //队列
          InitLinkQueue(&queue);
          BFS(G, queue, visit, V);
            for (int i = 0; i < G.vexnum; ++i)
            {
                    if (!visit[i])       //该顶点没被访问
                    {
                              BFS(G, queue, visit, G.Vetics[i].data);
                    }
            }
            printf("END\n");
            DestroyVisitArray(visit);             //销毁辅助数组
            DestroyLinkQueue(&queue);             //销毁队列
}

void BFS(ALGraph G, LinkQueue queue, BOOL* visit, VertexType V)	   //BFS基于模拟队列的实现
{
          EnQueue(&queue, V);
          visit[LocateVertex(G, V)] = TRUE;       //已经被访问
          while (!IsQueueEmpty(queue))             //队列不空
          {
                    VertexType temp;
                    DeQueue(&queue, &temp);       //出队
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