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
int EnQueue(SqQueue &qu,ElemType x); //进队
int DeQueue(SqQueue &qu,ElemType &x); //出队
//////////////////////////////////////////
