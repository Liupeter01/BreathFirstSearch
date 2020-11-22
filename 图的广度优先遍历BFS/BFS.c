#include"BFS.h"

void InitVisitArray(MGraph G, BOOL** visit)			  //初始化BFS算法辅助数组
{
          *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
          memset(*visit, FALSE, sizeof(BOOL) * G.vexnum);
}

void DestroyVisitArray(BOOL* visit)	//BFS算法辅助数组的销毁
{
          free(visit);
}

void BFSTraverse(MGraph G, VertexType V)		  //BFS广度优先遍历函数
{
          BOOL* visit = NULL;            //辅助数组
          InitVisitArray(G, &visit);              //初始化DFS算法辅助数组

          LinkQueue queue;              //队列
          InitLinkQueue(&queue);        //初始化队列
          BFS(G, queue, visit, V);                //执行一次BFS
          for (int i = 0; i < G.vexnum; ++i)
          {
                    if (!visit[i])       //该顶点没被访问
                    {
                              BFS(G, queue, visit, G.Vex[i]);
                    }
          }
          printf("END\n");
          DestroyLinkQueue(&queue);               //摧毁队列
          DestroyVisitArray(visit);               //bFS算法辅助数组的销毁
}

void BFS(MGraph G, LinkQueue queue, BOOL* visit, VertexType V)		   //BFS基于模拟队列的实现
{
          visit[LocateVertex(G,V)] = TRUE;        //顶点V的位置已经被访问
          EnQueue(&queue, V);           //入队
          while (!IsQueueEmpty(queue))
          {
                    VertexType temp;
                    DeQueue(&queue, &temp);  //出队
                    printf("%c-->", temp);
                    for (int pos = FindFirstNeighbor(G, temp); pos != -1; pos = FindNextNeighbor(G, temp, G.Vex[pos]))      //查找邻接点
                    {
                              if (!visit[pos])            //visit数组中还没有被访问过
                              {
                                        visit[pos] = TRUE;        //已经访问过
                                        EnQueue(&queue, G.Vex[pos]);       //将其入队
                              }
                    }
          }
}