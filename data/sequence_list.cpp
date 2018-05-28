/*
	顺序表
*/

#include "sequence_list.h"
#include "lib.h"


//int main()
//{
//	SqList L1;
//	SqList L2;
//	SqList L3;
//	InitList(L1);
//	InitList(L2);
//	InitList(L3);
//	ListInstert(L1, 1, 0);
//	ListInstert(L1, -2, 1);
//	ListInstert(L1, 4, 2);
//	ListInstert(L1, 4, 3);
//	ListInstert(L1, -5, 4);
//	ListInstert(L1, 4, 5);
//	ListInstert(L1, -7, 6);
//	ListInstert(L2, 2, 0);
//	ListInstert(L2, 4, 1);
//	ListInstert(L2, 6, 2);
//	ListInstert(L2, 8, 3);
//	ListInstert(L2, 10, 4);
//	ListInstert(L2, 12, 5);
//
//	for (int i = 0; i < L1.length; i++)
//	{
//		printf("%d\t", L1.data[i]);
//	}
//	return 0;
//}
///////////////////////////////////////
void InitList(SqList & L)
{
	L.length = 0;
}

int GetElem(SqList L, int i)
{
	if (i<1 || i>L.length)
		return 0;
	return L.data[i];
}

int LocateElem(SqList L, ElemType & e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i;
		}
	}
	return -1;
}

int ListInstert(SqList & L, ElemType e, int i)
{
	if (i<0 || i>L.length)
		return 0;
	int index = L.length;
	for (int j = 0; j < L.length - i; j++) //从0开始计数，一共执行Length-i次
	{
		L.data[index] = L.data[index - 1];
		index--;
	}
	L.data[i] = e;
	L.length++;
	return 1;
}

int ListDelete(SqList & L, ElemType e, int i)
{
	if (i<0 || i>L.length)
		return 0;
	int index = i;
	for (int j = 0; j < L.length - i; j++)
	{
		L.data[index] = L.data[index + 1];
		index++;
	}
	L.length--;
	return 0;
}

void Merge(SqList L1, SqList L2, SqList &L3)
{
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length)
	{
		if (L1.data[i] < L2.data[j])
		{
			L3.data[k] = L1.data[i];
			k++;
			i++;
		}
		else
		{
			L3.data[k] = L2.data[j];
			k++;
			j++;
		}
	}
	while (i < L1.length)
	{
		L3.data[k] = L1.data[i];
		k++;
		i++;
	}
	while (j < L2.length)
	{
		L3.data[k] = L2.data[j];
		k++;
		j++;
	}
	L3.length = k;
}
//////////////////////////////////////////
void example_2_2_11(SqList & L, ElemType e)
{
	int i = 0;
	while (i < L.length && L.data[i] <= e)
	{
		i++;
	}
	int index = L.length;
	for (int j = 0; j < L.length - i; j++)
	{
		L.data[index] = L.data[index - 1];
		index--;
	}
	L.data[i] = e;
	L.length++;
}

void example_2_2_12(SqList & L)
{
	int index = 0;
	int temp;
	for (int i = 0; i < L.length / 2; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

void example_2_2_13(SqList & L, int p)
{

}

void example_2_2_14(SqList & L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			int index = i;
			for (int j = 0; j < L.length - i; j++)
			{
				L.data[index] = L.data[index + 1];
				index++;
			}
			L.length--;
		}
	}
}

void example_2_2_15(SqList & L, ElemType e1, ElemType e2)
{
	int k = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] < e1 || L.data[i] > e2)
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}

void example_2_2_16(SqList & L)
{
	int temp = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] > 0)
		{
			temp = L.data[i];
			L.data[i] = L.data[L.length - i - 1];
			L.data[L.length - i] = temp;
		}
	}
}

void example_2_2_17(SqList & L)
{
	int k = 0;
	ElemType e;
	for (int i = 0; i < L.length; i++)
	{
		int flag = 0;
		e = L.data[i];
		for (int j = 0; j < L.length; j++)
		{
			if (e == L.data[j])
			{
				flag++;
			}
		}
		if (flag <= 1)
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}
