/*
	树
*/
#define _CRT_SECURE_NO_DEPRECATE
#include "lib.h"
#include "tree.h"

//int main()
//{
//	BTNode *b;
//	CreateBTNode(b);
//	PreOrderTraverse_(b);
//	return 0;
//}

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

void PreOrderTraverse_(BTNode * b)
{
	BTNode *St[50], *p;
	int top = -1;
	if (b != NULL)
	{
		top++; //根节点进栈
		St[top] = b;
		while (top > -1) //栈不为空时循环
		{
			p = St[top]; //退栈并访问该节点
			top--;
			printf("%c", p->data);
			if (p->rchild != NULL) //右孩子节点进栈
			{
				top++;
				St[top] = p->rchild;
			}
			if (p->lchild != NULL) //左孩子节点进栈
			{
				top++;
				St[top] = p->lchild;
			}
		}
	}
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

void InOrderTraverse_(BTNode * b)
{
	BTNode *St[50], *p;
	int top = -1;
	if (b != NULL)
	{
		p = b;
		while (top > -1 || p != NULL) //栈不空或p不空时循环
		{
			while (p != NULL) //扫描*p的所有左下节点并进栈
			{
				top++;
				St[top] = p;
				p = p->lchild;
			}
			if (top > -1)
			{
				p = St[top]; //出栈*p节点
				top--;
				printf("%c", p->data);
				p = p->rchild; //扫描*p的右孩子节点
			}
		}
	}
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

void PostOrderTraverse_(BTNode * b)
{
	BTNode *St[50], *p;
	int flag, top = -1;
	if (b != NULL)
	{
		do
		{
			while (b != NULL) //将*b的所有左下节点进栈
			{
				top++;
				St[top] = b;
				b = b->lchild;
			}
			p = NULL;
			flag = 1;
			while (top != -1 && flag)
			{
				b = St[top];
				if (b->rchild == p)
				{
					printf("%c", b->data);
					top--;
					p = b;
				}
				else
				{
					b = b->rchild;
					flag = 0;
				}
			}
		} while (top != -1);
	}
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

BiTTNodeP pre;/* 全局变量，始终指向刚刚访问过的节点 */
void InThreading(BiTTNodeP b)
{
	if (b)
	{
		InThreading(b->lchild);
		if (!b->lchild)
		{
			b->LTag = Thread;
			b->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = b;
		}
		pre = b;
		InThreading(b->rchild);
	}
}

int InOrderTraverse_Thr(BiTTNodeP b)
{
	BiTTNodeP p;
	p = b->lchild; //p指向根节点
	while (p != b) //空树或遍历结束时，p==b
	{
		while (p->LTag == Link) //当LTag==0时循环到中序序列第一个节点
		{
			p = p->lchild;
			printf("%c", p->data);
			while (p->RTag == Thread && p->rchild != b)
			{
				p = p->rchild;
				printf("%c", p->data);
			}
			p = p->rchild;
		}
	}
	return 1;
}

void CreateHT(HTNode ht[], int n0)
{
	int i, j, k, lnode, rnode;
	float min1, min2;
	for (i = 0; i < 2 * n0 - 1; i++) //所有节点的相关域置初值-1
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = 1;
	}
	for (i = n0; i < 2 * n0 - 1; i++) //构造Huffman Tree
	{
		min1 = min2 = 32767; //lnode和rnode为最小权重的两个节点
		lnode = rnode = -1;
		for (k = 0; k < i - 1; k++)
		{
			if (ht[k].parent == -1)
			{
				if (ht[k].weight < min1)
				{
					min2 = min1; rnode = lnode;
					min1 = ht[k].weight; lnode = k;
				}
				else if (ht[k].weight < min2)
				{
					min2 = ht[k].weight; rnode = k;
				}
			}
			ht[lnode].parent = i; ht[rnode].parent = i;
			ht[i].weight = ht[lnode].weight + ht[rnode].weight;
			ht[i].lchild = lnode; ht[i].rchild = rnode;
		}
	}
}

void CreateHCode(HTNode ht[], HCode hcd[], int n0)
{
	int i, f, c;
	HCode hc;
	for (i = 0; i < n0; i++)
	{
		hc.start = n0;
		c = i;
		f = ht[i].parent;
		while (f != -1)
		{
			if (ht[f].lchild == c)
			{
				hc.cd[hc.start--] = '0';
			}
			else
			{
				hc.cd[hc.start--] = '1';
			}
			c = f; f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}
