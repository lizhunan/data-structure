/*
	树
*/
#define _CRT_SECURE_NO_DEPRECATE
#include "lib.h"
#include "tree.h"

int main()
{
	BTNode *b;
	CreateBTNode(b);
	int d = LeafCount(b);
	printf("%d", d);
	return 0;
}

void CreateBTNode(BTNode *& bt)
{
	ElemType data;
	scanf_s(" %c", &data); //注意！！！%c前有空格，过滤scanf_s输入后留下的回车
	if (data == '#')
	{
		bt = NULL;
		return;
	}
	else
	{
		bt = (BTNode *)malloc(sizeof(BTNode));
		if (bt == NULL)
		{
			printf("failed!\n");
			return;
		}
		else
		{
			bt->data = data; //生成根节点
			printf("输入%c的左孩子:\n", data);
			CreateBTNode(bt->lchild); //构造左子树
			printf("输入%c的右孩子:\n", data);
			CreateBTNode(bt->rchild); //构造右子树
		}
	}
}

void PreOrderTraverse(BTNode * b)
{
	if (b == NULL)
	{
		return;
	}
	printf("%c", b->data);
	PreOrderTraverse(b->lchild);
	PreOrderTraverse(b->rchild);
}

void InOrderTraverse(BTNode * b)
{
	if (b == NULL)
	{
		return;
	}
	InOrderTraverse(b->lchild);
	printf("%c", b->data);
	InOrderTraverse(b->rchild);
}

void PostOrderTraverse(BTNode * b)
{
	if (b == NULL)
	{
		return;
	}
	PostOrderTraverse(b->lchild);
	PostOrderTraverse(b->rchild);
	printf("%c", b->data);
}

void LeveOrderTraverse(BTNode * b)
{
	//使用队列方式实现层次遍历
	BTNode *p;
	BTNode *qu[50]; //定义循环队列，存放节点指针
	int front = 0, rear = 0;
	rear++;
	qu[rear] = b; //根节点入队
	while (front != rear)
	{
		front = (front + 1) % 50;
		p = qu[front]; //队头出队
		printf("%c", p->data); //访问节点
		if (p->lchild != NULL) //有左孩子时将其入队
		{
			rear = (rear + 1) % 50;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL) //有右孩子时将其入队
		{
			rear = (rear + 1) % 50;
			qu[rear] = p->rchild;
		}
	}
}

int LeafCount(BTNode * b)
{
	static int count;
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
		{
			count++;
		}
		LeafCount(b->lchild);
		LeafCount(b->rchild);
	}
	return count;
}

int TreeDeep(BTNode * b)
{
	int deep = 0;
	if (b != NULL)
	{
		int leftDeep = TreeDeep(b->lchild);
		int rightDeep = TreeDeep(b->rchild);
		deep = leftDeep >= rightDeep ? leftDeep + 1 : rightDeep + 1;
	}
	return deep;
}
