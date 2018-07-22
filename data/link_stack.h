int typedef ElemType;

//链栈
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkStack;

void  InitStack(LinkStack *&lst);//初始化栈
int StackEmpty(LinkStack *&lst);//判断栈是否为空
void Push(LinkStack *&lst,ElemType x);//进栈
int Pop(LinkStack *&lst,ElemType &x);//出栈
int GetTop(LinkStack *&lst,ElemType &x);//取栈顶元素
//////////////////////////////////////////
int example_3_3_9(LinkStack *lst, char A[],int n);//判断无头结点的链栈出栈入栈是否合法
