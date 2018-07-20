int typedef ElemType;
#define MAX_SIZE 50 //默认长度为50
#include "link_list.h"

//顺序栈
typedef struct SqStack
{
	ElemType data[MAX_SIZE];
	int top;
}SqStack;

void InitStack(SqStack &st);//初始化栈
int StackEmpty(SqStack st);//判断栈是否为空
int Push(SqStack &st, ElemType x);//进栈
int Pop(SqStack &st, ElemType &x);//出栈
int GetTop(SqStack &st, ElemType &x);//取栈顶元素
//////////////////////////////////////////
int example_3_2_14(SqStack st, ElemType &x);//利用栈的基本运算返回指定栈中的栈底元素，要求保持栈中元素不变
void example_3_2_15(SqStack st, LinkList *L);//采用一个顺序栈逆向输出单链表L中的所有元素。
//////////////////求算数表达式的值（后缀表达式）////////////////////////
//运算符栈
typedef struct OpStack
{
	char data[MAX_SIZE];
	int top;
}OpStack;
//后缀表达式栈
typedef struct PostExpStack
{
	float data[MAX_SIZE];
	int top;
}PostExpStack;
void Trans(OpStack &op, char exp[], char *&postexp);//转换表达式为后缀表达式
float CompValue(PostExpStack & pst,char postexp[]);//计算后缀表达式的值
///////////////////////////////////////////////////////////////////////