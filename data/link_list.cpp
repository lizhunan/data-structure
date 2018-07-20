/*
	Á´±í
*/

#include "link_list.h"
#include "lib.h"
/*
int main()
{
	LinkList *L1, *L2, *L3;
	int a = 0;
	ElemType e1[] = { 1,2,2,4,6,7,4,9,11 };
	ElemType e2[] = { 1,3,5,7,9,2,1 };
	CreateListR(L1, e1, 9);
	CreateListR(L2, e2, 7);
	//Merge(L1, L2, L3);
	//ListInstert(L1, 10, 3);
	//ListInstert(L1, 11, 0);
	//ListDelete(L1, 3);
	//ListDelete(L1, 0);
	a=FindKth(L1,4);
	printf("\n");
	printf("%d\t",a);
	printf("\n");
	while (L1 != NULL)
	{
		printf("%d\t", L1->data);
		L1 = L1->next;
	}
	return 0;
}
*/
/////////////////////////////////////////////////
void CreateListF(LinkList *& L, ElemType a[], int n)
{
	LinkList *s;
	L = (LinkList *)malloc(sizeof(LinkList));//LinkList *L = new LinkList[n];
	L->data = n;
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreateListR(LinkList *& L, ElemType a[], int n)
{
	LinkList *s, *r;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->data = n;
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

int LocateElem(LinkList *& L, ElemType e)
{
	LinkList *s = L->next;
	int n = 1;
	while (s != NULL && s->data != e)
	{
		s = s->next;
		n++;
	}
	if (s == NULL) return -1;
	else return n;
}

void ListInstert(LinkList *& L, ElemType e, int i)
{
	int k = 0;
	LinkList *s, *p = L;
	s = (LinkList *)malloc(sizeof(LinkList));
	while (p != NULL && k < i)
	{
		p = p->next;
		k++;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void ListDelete(LinkList *& L, int i)
{
	int k = 0;
	LinkList *p = L;
	while (p != NULL && k < i)
	{
		p = p->next;
		k++;
	}
	p->next->data = NULL;
	p->next = p->next->next;
}

void Merge(LinkList * L1, LinkList * L2, LinkList *& L3)
{
	LinkList *p = L1->next, *q = L2->next, *r, *s;
	L3 = (LinkList *)malloc(sizeof(LinkList));
	r = L3;
	r->data = 12;
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			p = p->next;
			r->next = s;
			r = s;
		}
		else
		{
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = q->data;
			q = q->next;
			r->next = s;
			r = s;
		}
	}
	if (p != NULL) q = p;
	while (q != NULL)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = q->data;
		q = q->next;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

int example_2_3_23(LinkList *& L, ElemType e)
{
	LinkList *pre = L, *p = pre->next;
	while (p != NULL)
	{
		if (p->data == e)
		{
			pre->next = p->next;
			free(p);
			return 1;
		}
		p = p->next;
		pre = pre->next;
	}
	return 0;
}

void example_2_3_26(LinkList *& L)
{
	LinkList *pre = L, *p = pre->next, *minp = p, *minpre = pre;
	while (p != NULL)
	{
		if (p->data < minp->data)
		{
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = minp->next;
	free(minp);
}

void example_2_3_28(LinkList *& L)
{
	LinkList *p = L->next, *temp;
	L->next = NULL;
	while (p != NULL)
	{
		temp = p->next;
		p->next = L->next;
		L->next = p;
		p = temp;
	}
}

void example_2_3_29(LinkList *& A, LinkList *& B)
{
	LinkList *ra, *rb, *q, *p;
	p = A;
	B = (LinkList *)malloc(sizeof(LinkList));
	rb = B;
	rb->data = 10;
	while (p != NULL)
	{
		if (p->next->data % 2 != 0)
		{
			q = (LinkList *)malloc(sizeof(LinkList));
			q->data = p->next->data;
			rb->next = q;
			rb = q;
			p->next->data = NULL;
			p->next = p->next->next;
		}
		p = p->next;
	}
	rb->next = NULL;
}

void example_2_3_34(LinkList *& L, ElemType e)
{
	LinkList *p, *q, *pre;
	pre = L;
	p = pre->next;
	q = (LinkList *)malloc(sizeof(LinkList));
	while (p != NULL && p->data <= e)
	{
		p = p->next;
		pre = pre->next;
	}
	q->data = e;
	q->next = pre->next;
	pre->next = q;
}

void example_2_3_36(LinkList *& L, ElemType min, ElemType max)
{
	LinkList *pre, *p, *temp;
	pre = L;
	p = pre->next;
	while (p != NULL)
	{
		if (p->data >= min && p->data <= max)
		{
			temp = p->next;
			pre->next = p->next;
			free(p);
			p = temp;
		}
		else
		{
			pre = p;
			p = p->next;
		}

	}
}

void example_2_3_38(LinkList *& L)
{
	LinkList *pre = L, *p = pre->next, *pretemp, *temp, *r;
	while (p != NULL)
	{
		pretemp = p, temp = p->next;
		while (temp != NULL) {
			if (p->data == temp->data)
			{
				pretemp->next = pretemp->next->next;
			}
			pretemp = temp;
			temp = temp->next;
		}
		pre = p;
		p = p->next;
	}
}

void example_2_3_40(LinkList *& L1, LinkList *& L2, LinkList *&L3)
{
	LinkList *l1 = L1->next, *l2 = L2->next, *l3 = L3, *s;
	L3 = (LinkList *)malloc(sizeof(LinkList));
	L3->data = -1;
	l3 = L3;
	while (l1 != NULL)
	{
		l2 = L2->next;
		while (l2 != NULL)
		{
			if (l1->data == l2->data)
			{
				s = (LinkList *)malloc(sizeof(LinkList));
				s->data = l1->data;
				l3->next = s;
				l3 = s;
			}
			l2 = l2->next;
		}
		l1 = l1->next;
	}
	l3->next = NULL;
}

void example_2_3_42(LinkList *& L1, LinkList *& L2, LinkList *& L3)
{
	LinkList *l1 = L1->next, *l2 = L2->next, *l3;
	L3 = (LinkList *)malloc(sizeof(LinkList));
	L3->data = -1;
	l3 = L3;
	while (l1 != NULL)
	{
		int k = 0;
		l2 = L2->next;
		while (l2 != NULL && k == 0)
		{
			if (l1->data == l2->data) 
			{
				k++;
			}
			l2 = l2->next;
		}
		if (k == 0) 
		{
			printf("%d\t",l1->data);
		}
		l1 = l1->next;
	}
	l3->next = NULL;
}
