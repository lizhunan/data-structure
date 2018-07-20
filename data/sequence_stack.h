int typedef ElemType;
#define MAX_SIZE 50 //Ĭ�ϳ���Ϊ50
#include "link_list.h"

//˳��ջ
typedef struct SqStack
{
	ElemType data[MAX_SIZE];
	int top;
}SqStack;

void InitStack(SqStack &st);//��ʼ��ջ
int StackEmpty(SqStack st);//�ж�ջ�Ƿ�Ϊ��
int Push(SqStack &st, ElemType x);//��ջ
int Pop(SqStack &st, ElemType &x);//��ջ
int GetTop(SqStack &st, ElemType &x);//ȡջ��Ԫ��
//////////////////////////////////////////
int example_3_2_14(SqStack st, ElemType &x);//����ջ�Ļ������㷵��ָ��ջ�е�ջ��Ԫ�أ�Ҫ�󱣳�ջ��Ԫ�ز���
void example_3_2_15(SqStack st, LinkList *L);//����һ��˳��ջ�������������L�е�����Ԫ�ء�
//////////////////���������ʽ��ֵ����׺���ʽ��////////////////////////
//�����ջ
typedef struct OpStack
{
	char data[MAX_SIZE];
	int top;
}OpStack;
//��׺���ʽջ
typedef struct PostExpStack
{
	float data[MAX_SIZE];
	int top;
}PostExpStack;
void Trans(OpStack &op, char exp[], char *&postexp);//ת�����ʽΪ��׺���ʽ
float CompValue(PostExpStack & pst,char postexp[]);//�����׺���ʽ��ֵ
///////////////////////////////////////////////////////////////////////