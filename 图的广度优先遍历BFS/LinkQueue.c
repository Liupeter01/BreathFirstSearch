#include"LinkQueue.h"

LinkNode* CreateNode(ElemType data)				  //�������
{
		  LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));		  //����
		  assert(s != NULL);
		  s->data = data;
		  s->next = NULL;
		  return s;
}

void InitLinkQueue(LinkQueue* Q)           //��ʽ���еĳ�ʼ��
{
		  Q->rear = Q->front = (LinkNode*)malloc(sizeof(LinkNode));	//����ͷ���
		  assert(Q->rear != NULL);
		  Q->rear->next = NULL;
}

void ClearLinkQueue(LinkQueue* Q)           //��ʽ���е����
{
		  if (IsQueueEmpty(*Q))
		  {
					Q->rear = Q->front;
		  }
		  else
		  {
					LinkNode* ptr = Q->front->next;		  //����ͷ���
					while (ptr != NULL)
					{
							  LinkNode* ptemp = ptr;
							  ptr = ptr->next;
							  free(ptemp);
					}
					Q->rear = Q->front;
		  }
}

void DestroyLinkQueue(LinkQueue* Q)           //��ʽ���еĴݻ�
{
		  if (IsQueueEmpty(*Q))
		  {
					free(Q->front);
					Q->front = Q->rear = NULL;
		  }
		  else
		  {
					LinkNode* ptr = Q->front;
					while (ptr != NULL)
					{
							  LinkNode* ptemp = ptr;
							  ptr = ptr->next;
							  free(ptemp);
					}
		  }
}

void DisplayLinkQueue(LinkQueue Q)          //��ʽ���е����
{
		  LinkNode* ptr = Q.front->next;		  //����ͷ���
		  printf("<Head:");
		  while (ptr != NULL)
		  {
					printf("%d  ", ptr->data);
					ptr = ptr->next;
		  }
		  printf(">Tail\n");
}

BOOL IsQueueEmpty(LinkQueue Q)              //��ʽ���е��п�
{
		  return Q.front == Q.rear;
}

void EnQueue(LinkQueue* Q, ElemType x)           //��ʽ���е���Ӳ���
{
		  LinkNode* s = CreateNode(x);
		  Q->rear->next = s;
		  Q->rear = s;
}

BOOL DeQueue(LinkQueue* Q, ElemType* e)             //��ʽ���еĳ��Ӳ���
{
		  if (!IsQueueEmpty(*Q))
		  {
					LinkNode* ptr = Q->front->next;	  //����ͷ���
					*e = ptr->data;
					if (ptr->next == NULL)					//ֻ��һ����Ԫ�����
					{
							  Q->rear = Q->front;
					}
					else
					{
							  Q->front->next = ptr->next;
					}
					free(ptr);
					return TRUE;
		  }
		  return FALSE;
}

ElemType GetTop(LinkQueue Q)             //��ʽ���л�ȡ��ͷ��ֵ
{
		  return ((!IsQueueEmpty(Q)) ? Q.front->next->data : ERRORCODE);
}

int length(LinkQueue Q)                 //��ʽ���г���
{
		  LinkNode* ptr = Q.front->next;		  //����ͷ���
		  int counter = 0;	  //������
		  while (ptr != NULL)
		  {
					counter++;
					ptr = ptr->next;
		  }
		  return counter;
}