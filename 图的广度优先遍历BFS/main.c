#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"BFS.h"                                  //������ȱ���

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEFGHIJKLM" };         //�������鼯��V(G)
          CreateBatchVertex(&Graph, arr, NORMALGRAPH);//�������������Ĵ���

          VertexType arr1[] = "AAAABLLJDGGGH";
          VertexType arr2[] = "BCFLMJMMEHIKK";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);

          BFSTraverse(Graph, 'D');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}