int typedef ElemType;
#define MAX_SIZE 50 //默认长度为50

//顺序队列（循环队列）
typedef struct SqQueue
{
	ElemType data[MAX_SIZE];
	int front, rear;	//队首和队尾指针
}SqQueue;

void InitQueue(SqQueue &qu); //初始化队列
int QueueEmpty(SqQueue qu);	//判断队列是否为空
int QueueFull(SqQueue qu); //判断队列是否满
int QueueLength(SqQueue qu); //计算队列长度
int EnQueue(SqQueue &qu, ElemType x); //进队
int DeQueue(SqQueue &qu, ElemType &x); //出队
void Traverse(SqQueue qu); //遍历队列
//////////////////////////////////////////
void example_4_2_19(SqQueue &qu); //对队列进行逆置
int example_4_2_22(SqQueue &qu, int k); //删除第K个元素，使用临时队列的方法
int example_4_2_22(SqQueue &qu, int k, int item, int count); //在第K个元素后插入item，不使用临时队列的方法，就地添加
