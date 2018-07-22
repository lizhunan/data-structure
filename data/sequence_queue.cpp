/*
	顺序队列（循环队列）
*/


#include "sequence_queue.h"
#include "lib.h"

int main()
{
	SqQueue qu;
	int a = 0, b = -1;
	InitQueue(qu);
	EnQueue(qu, 0);
	EnQueue(qu, 2);
	EnQueue(qu, 4);
	EnQueue(qu, 6);
	EnQueue(qu, 11);
	a = QueueLength(qu);
	printf("%d\n",a);
	DeQueue(qu, b);
	printf("%d\t", b);
	DeQueue(qu, b);
	printf("%d\t", b);
	DeQueue(qu, b);
	printf("%d\n", b);
	a = QueueLength(qu);
	printf("%d\n", a);
	return 0;
}
void InitQueue(SqQueue & qu)
{
	qu.front = qu.rear = 0;
}

int QueueEmpty(SqQueue qu)
{
	return (qu.front == qu.rear);
}

int QueueFull(SqQueue qu)
{
	return ((qu.rear + 1) % MAX_SIZE == qu.front);
}

int QueueLength(SqQueue qu)
{
	return (qu.rear - qu.front + MAX_SIZE) % MAX_SIZE;
}

int EnQueue(SqQueue & qu, ElemType x)
{
	if ((qu.rear + 1) % MAX_SIZE == qu.front) //队满
		return 0;
	qu.rear = (qu.rear + 1) % MAX_SIZE;
	qu.data[qu.rear] = x;
	return 1;
}

int DeQueue(SqQueue & qu, ElemType & x)
{
	if (qu.front == qu.rear)
		return 0;
	qu.front = (qu.front + 1) % MAX_SIZE;
	x = qu.data[qu.front];
	return 1;
}
