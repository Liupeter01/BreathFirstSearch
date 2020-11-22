#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"BFS.h"                                  //������ȱ���

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEFGH" };         //�������鼯��V(G)
          CreateBatchVertex(&Graph, arr, NORMALGRAPH);//�������������Ĵ���

          VertexType arr1[] = "AABBDECCF";
          VertexType arr2[] = "BCDEHHFGG";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);

          BFSTraverse(Graph, 'A');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}