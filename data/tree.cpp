/*
	��
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
