#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图
#include"BFS.h"                                  //广度优先遍历

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEFGH" };         //顶点数组集合V(G)
          CreateBatchVertex(&Graph, arr, NORMALGRAPH);//根据数组批量的创建

          VertexType arr1[] = "AABBDECCF";
          VertexType arr2[] = "BCDEHHFGG";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);

          BFSTraverse(Graph, 'A');

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}