/*
	��
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
	scanf_s(" %c", &data); //ע�⣡����%cǰ�пո񣬹���scanf_s��������µĻس�
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
			bt->data = data; //���ɸ��ڵ�
			printf("����%c������:\n", data);
			CreateBTNode(bt->lchild); //����������
			printf("����%c���Һ���:\n", data);
			CreateBTNode(bt->rchild); //����������
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
		top++; //���ڵ��ջ
		St[top] = b;
		while (top > -1) //ջ��Ϊ��ʱѭ��
		{
			p = St[top]; //��ջ�����ʸýڵ�
			top--;
			printf("%c", p->data);
			if (p->rchild != NULL) //�Һ��ӽڵ��ջ
			{
				top++;
				St[top] = p->rchild;
			}
			if (p->lchild != NULL) //���ӽڵ��ջ
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
		while (top > -1 || p != NULL) //ջ���ջ�p����ʱѭ��
		{
			while (p != NULL) //ɨ��*p���������½ڵ㲢��ջ
			{
				top++;
				St[top] = p;
				p = p->lchild;
			}
			if (top > -1)
			{
				p = St[top]; //��ջ*p�ڵ�
				top--;
				printf("%c", p->data);
				p = p->rchild; //ɨ��*p���Һ��ӽڵ�
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
			while (b != NULL) //��*b���������½ڵ��ջ
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
	//ʹ�ö��з�ʽʵ�ֲ�α���
	BTNode *p;
	BTNode *qu[50]; //����ѭ�����У���Žڵ�ָ��
	int front = 0, rear = 0;
	rear++;
	qu[rear] = b; //���ڵ����
	while (front != rear)
	{
		front = (front + 1) % 50;
		p = qu[front]; //��ͷ����
		printf("%c", p->data); //���ʽڵ�
		if (p->lchild != NULL) //������ʱ�������
		{
			rear = (rear + 1) % 50;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL) //���Һ���ʱ�������
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

BiTTNodeP pre;/* ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľڵ� */
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
	p = b->lchild; //pָ����ڵ�
	while (p != b) //�������������ʱ��p==b
	{
		while (p->LTag == Link) //��LTag==0ʱѭ�����������е�һ���ڵ�
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
	for (i = 0; i < 2 * n0 - 1; i++) //���нڵ��������ó�ֵ-1
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = 1;
	}
	for (i = n0; i < 2 * n0 - 1; i++) //����Huffman Tree
	{
		min1 = min2 = 32767; //lnode��rnodeΪ��СȨ�ص������ڵ�
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
