/*
	��ջ
*/

#include "link_stack.h"
#include "lib.h"

int main()
{
	LinkStack *lst;
	InitStack(lst);
	int d;
	char A[8] = { 'I','O','I','I','O','I','O','O' };
	d = example_3_3_9(lst, A, 8);
	printf("%d", d);
	return 0;
}

void InitStack(LinkStack *& lst)
{
	lst = (LinkStack *)malloc(sizeof(LinkStack));
	lst->next = NULL;
}

int StackEmpty(LinkStack *& lst)
{
	return (lst->next == NULL);
}

void Push(LinkStack *& lst, ElemType x)
{
	LinkStack *p;
	p = (LinkStack *)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}

int Pop(LinkStack *& lst, ElemType & x)
{
	LinkStack *p;
	if (lst->next == NULL)	//ջ��
	{
		return 0;
	}
	p = lst->next;
	x = p->data;
	lst->next = p->next;	//ɾ��ջ���ڵ�ָ��
	free(p);
	return 1;
}

int GetTop(LinkStack *& lst, ElemType & x)
{
	LinkStack *p;
	if (lst->next == NULL)	//ջ�� 
	{
		return  0;
	}
	p = lst->next;
	x = p->data;
	return 1;
}

int example_3_3_9(LinkStack *lst, char A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (A[i] == 'I')
		{
			//��ջ
			LinkStack *s;
			s = (LinkStack *)malloc(sizeof(LinkStack));
			s->data = i;
			s->next = lst;
			lst = s;
		}
		else if (A[i] == 'O')
		{
			//��ջ
			LinkStack *s;
			if (lst == NULL)
			{
				return 0;
			}
			s = lst;
			lst = s->next;
			free(s);
		}
		else
		{
			return 0;//����ֵ��Ч
		}
	}
	return (lst->next == NULL);
}


