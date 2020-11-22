#include"ALGraph.h"
#include"DirectEdge.h"       //����ͼ
#include"UnDirectEdge.h"    //����ͼ
#include"BFS.h"                    //������ȱ���

int main()
{
          ALGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          VertexType arr[] = { "ABCDEFGH" };         //�������鼯��V(G)
          CreateBatchVertex(&Graph, arr);//�������������Ĵ���

          VertexType arr1[] = "AABBDECCF";
          VertexType arr2[] = "BCDEHHFGG";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);    

          BFSTraverse(Graph, 'D');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}