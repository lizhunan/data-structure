/*
	链队
*/

#include "link_queue.h"
#include "lib.h"

//int main()
//{
//	LQueue *lqu;
//	ElemType x;
//	InitQueue(lqu);
//	EnQueue(lqu, 0);
//	EnQueue(lqu, 2);
//	EnQueue(lqu, 4);
//	EnQueue(lqu, 5);
//	EnQueue(lqu, 6);
//	EnQueue(lqu, 8);
//	//Traverse(lqu);
//	DeQueue(lqu, x);
//	DeQueue(lqu, x);
//	DeQueue(lqu, x);
//	DeQueue(lqu, x);
//	//Traverse(lqu);
//	DeQueue(lqu, x);
//	DeQueue(lqu, x);
//	DeQueue(lqu, x);
//	DeQueue(lqu, x);
//	DeQueue(lqu, x);
//	Traverse(lqu);
//	//DeQueue(lqu, x);
//	//Traverse(lqu);
//	return 0;
//}

void InitQueue(LQueue *& lqu)
{
	lqu = (LQueue *)malloc(sizeof(LQueue));
	lqu->front = lqu->rear = (QNode *)malloc(sizeof(QNode));
	lqu->front->next = NULL;
}

int QueueEmpty(LQueue *lqu)
{
	return (lqu->rear == lqu->front);
}

void EnQueue(LQueue *& lqu, ElemType x)
{
	QNode *p;
	p = (QNode *)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	//将*p节点链到队尾，rear指向它（链表的尾插法）
	lqu->rear->next = p;
	lqu->rear = p;
}

int DeQueue(LQueue *& lqu, ElemType & x)
{
	QNode *p;
	if (lqu->front == lqu->rear)
	{
		return 0;
	}
	p = lqu->front->next;
	x = p->data;
	lqu->front->next = lqu->front->next->next;
	if (lqu->rear == p)
	{
		lqu->rear = lqu->front;
	}
	free(p);
	return 1;
}

void Traverse(LQueue * lqu)
{

	while (lqu->front->next != NULL)
	{
		printf("%d\t", lqu->front->next->data);
		lqu->front->next = lqu->front->next->next;
	}
	printf("\n");
}
