/*
	顺序栈
*/

#include "sequence_stack.h"
#include "lib.h"

//int main()
//{
//	int i;
//	float f;
//	SqStack st;
//	OpStack op;
//	PostExpStack pst;
//	char exp[] = { '(','5','6','-','2','0',')','/','(','4','+','2',')','\0' };
//	char postexp[50];
//	char *p = postexp;
//	Trans(op, exp, p);
//	int k = 0;
//	char c = postexp[k];
//	while (c != '\0')
//	{
//		c = postexp[k];
//		printf("%c", c);
//		k++;
//	}
//	printf("\n");
//	f = CompValue(pst, postexp);
//	printf("%f", f);
//	return 0;
//}

void InitStack(SqStack & st)
{
	st.top = -1;
}

int StackEmpty(SqStack st)
{
	return (st.top == -1);
}

int Push(SqStack & st, ElemType x)
{
	if (st.top == MAX_SIZE - 1)
		return 0;
	st.top++;
	st.data[st.top] = x;
	return 1;
}

int Pop(SqStack & st, ElemType & x)
{
	if (st.top == -1)
		return 0;
	x = st.data[st.top];
	st.top--;
	return 1;
}

int GetTop(SqStack & st, ElemType & x)
{
	if (st.top == -1)
		return 0;
	x = st.data[st.top];
	return 1;
}

int example_3_2_14(SqStack st, ElemType & x)
{
	SqStack tempSt;
	InitStack(tempSt);
	int temp;
	while (!StackEmpty(st))
	{
		temp = st.data[st.top];
		st.top--;
		tempSt.top++;
		tempSt.data[tempSt.top] = temp;
	}
	x = tempSt.data[tempSt.top];
	//恢复st栈中原来的内容
	while (!StackEmpty(tempSt))
	{
		temp = tempSt.data[tempSt.top];
		tempSt.top--;
		st.top++;
		st.data[st.top] = temp;
	}
	return 0;
}

void example_3_2_15(SqStack st, LinkList * L)
{
	ElemType x;
	st.top = -1;
	LinkList *p = L->next;
	while (p != NULL)
	{
		st.top++;
		st.data[st.top] = p->data;
		p = p->next;
	}
	while (st.top != -1)
	{
		x = st.data[st.top];
		st.top--;
		printf("%d\t", x);
	}
}

void Trans(OpStack &op, char exp[], char *&postexp)
{
	op.top = -1;//初始化栈
	char ch;
	int i = 0, j = 0;//i作为exp下标，j作为postexp下标
	ch = exp[i];
	i++;
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
			op.top++;
			op.data[op.top] = ch;
			break;
		case ')':
			while (op.data[op.top] != '(')
			{
				postexp[j] = op.data[op.top];
				j++;
				op.top--;
			}
			op.top--;
			break;
		case '+':
			while (op.top != -1 && op.data[op.top] != '(')
			{
				postexp[j] = op.data[op.top];
				j++;
				op.top--;
			}
			op.top++;
			op.data[op.top] = ch;
			break;
		case '-':
			while (op.top != -1 && op.data[op.top] != '(')
			{
				postexp[j] = op.data[op.top];
				j++;
				op.top--;
			}
			op.top++;
			op.data[op.top] = ch;
			break;
		case '*':
			while (op.top != -1 && op.data[op.top] != '('
				&& (op.data[op.top] == '*' || op.data[op.top] == '/'))
			{
				postexp[j] = op.data[op.top];
				j++;
				op.top--;
			}
			op.top++;
			op.data[op.top] = ch;
			break;
		case '/':
			while (op.top != -1 && op.data[op.top] != '('
				&& (op.data[op.top] == '*' || op.data[op.top] == '/'))
			{
				postexp[j] = op.data[op.top];
				j++;
				op.top--;
			}
			op.top++;
			op.data[op.top] = ch;
			break;
		case ' ':	//过滤空格
			break;
		default:	//判定为数字
			while (ch >= '0' && ch <= '9')
			{
				postexp[j] = ch;
				j++;
				ch = exp[i];
				i++;
			}
			i--;
			postexp[j] = '#';
			j++;
			break;
		}
		ch = exp[i];
		i++;
	}
	while (op.top != -1)
	{
		postexp[j] = op.data[op.top];
		j++;
		op.top--;
	}
	postexp[j] = '\0';
}

float CompValue(PostExpStack & pst, char postexp[])
{
	float d;
	pst.top = -1;
	int i = 0;
	char ch;
	ch = postexp[i];
	i++;
	while (ch != '\0')
	{
		switch (ch)
		{
		case '+':
			pst.data[pst.top - 1] = pst.data[pst.top - 1] + pst.data[pst.top];
			pst.top--;
			break;
		case '-':
			pst.data[pst.top - 1] = pst.data[pst.top - 1] - pst.data[pst.top];
			pst.top--;
			break;
		case '*':
			pst.data[pst.top - 1] = pst.data[pst.top - 1] * pst.data[pst.top];
			pst.top--;
			break;
		case '/':
			pst.data[pst.top - 1] = pst.data[pst.top - 1] / pst.data[pst.top];
			pst.top--;
			break;
		default:	//数字和#
			d = 0;
			while (ch >= '0' && ch <= '9')
			{
				d = 10 * d + ch - '0';
				ch = postexp[i];
				i++;
			}
			pst.top++;
			pst.data[pst.top] = d;
			break;
		}
		ch = postexp[i];
		i++;
	}
	return pst.data[pst.top];
}
