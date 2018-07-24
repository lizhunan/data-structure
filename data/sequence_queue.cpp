/*
	顺序队列（循环队列）
*/


#include "sequence_queue.h"
#include "sequence_stack.h"
#include "lib.h"

//int main()
//{
//	SqQueue qu;
//	int a = 0, b = -1;
//	InitQueue(qu);
//	EnQueue(qu, 0);
//	EnQueue(qu, 2);
//	EnQueue(qu, 4);
//	EnQueue(qu, 6);
//	EnQueue(qu, 11);
//	Traverse(qu);
//	example_4_2_22(qu, 3,9,5);
//	Traverse(qu);
//	example_4_2_22(qu, 1, 7, 6);
//	Traverse(qu);
//	return 0;
//}
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
	if (qu.front == qu.rear) //队空
		return 0;
	qu.front = (qu.front + 1) % MAX_SIZE;
	x = qu.data[qu.front];
	return 1;
}

void Traverse(SqQueue qu)
{
	ElemType x;
	while (!(qu.front == qu.rear))
	{
		qu.front = (qu.front + 1) % MAX_SIZE;
		x = qu.data[qu.front];
		printf("%d\t", x);
	}
	printf("\n");
}

void example_4_2_19(SqQueue & qu)
{
	ElemType x;
	SqStack st;
	InitStack(st);
	while (!(qu.front == qu.rear))
	{
		qu.front = (qu.front + 1) % MAX_SIZE;
		x = qu.data[qu.front];
		st.top++;
		st.data[st.top] = x;
	}
	while (!(st.top == -1))
	{
		x = st.data[st.top];
		st.top--;
		qu.rear = (qu.rear + 1) % MAX_SIZE;
		qu.data[qu.rear] = x;
	}
}

int example_4_2_22(SqQueue & qu, int k)
{
	ElemType x;
	int i = 0;
	SqQueue temp;
	InitQueue(temp);
	while (!(qu.front == qu.rear))
	{
		i++;
		qu.front = (qu.front + 1) % MAX_SIZE;
		x = qu.data[qu.front];
		if (i != k)
		{
			temp.rear = (temp.rear + 1) % MAX_SIZE;
			temp.data[temp.rear] = x;
		}
	}
	while (!(temp.front == temp.rear))
	{
		temp.front = (temp.front + 1) % MAX_SIZE;
		x = temp.data[temp.front];
		qu.rear = (qu.rear + 1) % MAX_SIZE;
		qu.data[qu.rear] = x;
	}
	return 0;
}

int example_4_2_22(SqQueue & qu, int k, int item,int count)
{
	int i = 0;
	ElemType x;
	while (count)
	{
		count--;
		qu.front = (qu.front + 1) % MAX_SIZE;
		x = qu.data[qu.front];
		if (i == k)
		{
			qu.rear = (qu.rear + 1) % MAX_SIZE;
			qu.data[qu.rear] = item;
		}
		qu.rear = (qu.rear + 1) % MAX_SIZE;
		qu.data[qu.rear] = x;
		i++;
	}
	return 0;
}
