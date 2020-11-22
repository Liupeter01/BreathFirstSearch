#include"ALGraph.h"
#include"DirectEdge.h"       //有向图
#include"UnDirectEdge.h"    //无向图
#include"BFS.h"                    //广度优先遍历

int main()
{
          ALGraph Graph;
          InitGraph(&Graph);         //初始化

          VertexType arr[] = { "ABCDEFGH" };         //顶点数组集合V(G)
          CreateBatchVertex(&Graph, arr);//根据数组批量的创建

          VertexType arr1[] = "AABBDECCF";
          VertexType arr2[] = "BCDEHHFGG";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);    

          BFSTraverse(Graph, 'D');

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}