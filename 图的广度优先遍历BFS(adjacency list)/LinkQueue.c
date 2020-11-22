#include"LinkQueue.h"

LinkNode* CreateNode(ElemType data)				  //创建结点
{
		  LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));		  //创建
		  assert(s != NULL);
		  s->data = data;
		  s->next = NULL;
		  return s;
}

void InitLinkQueue(LinkQueue* Q)           //链式队列的初始化
{
		  Q->rear = Q->front = (LinkNode*)malloc(sizeof(LinkNode));	//创建头结点
		  assert(Q->rear != NULL);
		  Q->rear->next = NULL;
}

void ClearLinkQueue(LinkQueue* Q)           //链式队列的清除
{
		  if (IsQueueEmpty(*Q))
		  {
					Q->rear = Q->front;
		  }
		  else
		  {
					LinkNode* ptr = Q->front->next;		  //跳过头结点
					while (ptr != NULL)
					{
							  LinkNode* ptemp = ptr;
							  ptr = ptr->next;
							  free(ptemp);
					}
					Q->rear = Q->front;
		  }
}

void DestroyLinkQueue(LinkQueue* Q)           //链式队列的摧毁
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

void DisplayLinkQueue(LinkQueue Q)          //链式队列的输出
{
		  LinkNode* ptr = Q.front->next;		  //跳过头结点
		  printf("<Head:");
		  while (ptr != NULL)
		  {
					printf("%d  ", ptr->data);
					ptr = ptr->next;
		  }
		  printf(">Tail\n");
}

BOOL IsQueueEmpty(LinkQueue Q)              //链式队列的判空
{
		  return Q.front == Q.rear;
}

void EnQueue(LinkQueue* Q, ElemType x)           //链式队列的入队操作
{
		  LinkNode* s = CreateNode(x);
		  Q->rear->next = s;
		  Q->rear = s;
}

BOOL DeQueue(LinkQueue* Q, ElemType* e)             //链式队列的出队操作
{
		  if (!IsQueueEmpty(*Q))
		  {
					LinkNode* ptr = Q->front->next;	  //跳过头结点
					*e = ptr->data;
					if (ptr->next == NULL)					//只有一个首元结点了
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

ElemType GetTop(LinkQueue Q)             //链式队列获取队头的值
{
		  return ((!IsQueueEmpty(Q)) ? Q.front->next->data : ERRORCODE);
}

int length(LinkQueue Q)                 //链式队列长度
{
		  LinkNode* ptr = Q.front->next;		  //跳过头结点
		  int counter = 0;	  //计数器
		  while (ptr != NULL)
		  {
					counter++;
					ptr = ptr->next;
		  }
		  return counter;
}