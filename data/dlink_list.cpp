/*
Ë«Á´±í
*/
#include "lib.h"
#include "dlink_list.h"

int main()
{
	DLinkList *L;
	ElemType a[] = { 1,2,3,4,10,6,7,8,9 };
	CreateDListR(L, a, 9);
	//example_2_4_12(L,10,11);
	while (L)
	{
		printf("%d\t", L->data);
		L = L->next;
	}
	printf("\n");
}

void CreateDListF(DLinkList *& L, ElemType a[], int n)
{
	DLinkList *s;
	int i;
	L = (DLinkList *)malloc(sizeof(DLinkList));
	L->data = n;
	L->next = NULL;
	L->prior = NULL;
	for (i = 0; i < n; i++)
	{
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
		{
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}

void CreateDListR(DLinkList *& L, ElemType a[], int n)
{
	DLinkList *s, *r;
	int i;
	L = (DLinkList *)malloc(sizeof(DLinkList));
	L->data = n;
	L->next = NULL;
	L->prior = NULL;
	r = L;
	for (i = 0; i < n; i++)
	{
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

int FindNode(DLinkList *& L, ElemType e)
{
	DLinkList *p = L->next;
	int i = 0;
	while (p != NULL && p->data != e)
	{
		i++;
		p = p->next;
	}
	if (p == NULL)
		return -1;
	else
		return i;
}

int ListInsert(DLinkList *& L, int i, ElemType e)
{
	int j = 0;
	DLinkList *p = L, *s;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL)
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return 1;
	}
}

int ListDelete(DLinkList *& L, int i)
{
	int j = 0;
	DLinkList *p = L, *q;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		q = p->next;
		if (q == NULL)
			return 0;
		p->next = q->next;
		if (p->next != NULL)
			p->next->prior = p;
		free(q);
		return 1;
	}
}

void example_2_4_12(DLinkList *& L, int x, int y)
{
	DLinkList *p = L->next, *s;
	s = (DLinkList *)malloc(sizeof(DLinkList));
	s->data = y;
	while (p != NULL && p->data != x)
	{
		p = p->next;
	}
	s->next = p->prior->next;
	s->prior = p->prior;
	p->prior->next = s;
	p->prior = s;

	s->prior = p->next->prior;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
}

void example_2_4_14(DLinkList *& L)
{
	DLinkList *p = L->next, *maxp = p;
	while (p != NULL)
	{
		if (p->data > maxp->data)
		{
			maxp = p;
		}
		p = p->next;
	}
	maxp->prior->next = maxp->next;
	maxp->next->prior = maxp->prior;
	free(maxp);
}

void example_2_4_15(DLinkList *& L)
{
	DLinkList *p = L->next,*s;
	L->next = NULL;
	while (p != NULL)
	{
		s = p->next;
		p->next = L->next;
		if (L->next != NULL) 
		{
			L->next->prior = p;
		}
		L->next = p;
		p->prior = L;
		p = s;
	}
}
