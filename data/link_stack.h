int typedef ElemType;

//��ջ
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkStack;

void  InitStack(LinkStack *&lst);//��ʼ��ջ
int StackEmpty(LinkStack *&lst);//�ж�ջ�Ƿ�Ϊ��
void Push(LinkStack *&lst,ElemType x);//��ջ
int Pop(LinkStack *&lst,ElemType &x);//��ջ
int GetTop(LinkStack *&lst,ElemType &x);//ȡջ��Ԫ��
//////////////////////////////////////////
int example_3_3_9(LinkStack *lst, char A[],int n);//�ж���ͷ������ջ��ջ��ջ�Ƿ�Ϸ�
