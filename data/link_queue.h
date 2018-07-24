int typedef ElemType;

//链队中数据节点类型
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
} QNode;
//链队节点类型
typedef struct LQueue
{
	QNode *front;
	QNode *rear;
}LinkQueue;

void InitQueue(LQueue *& lqu); //初始化链队（带头结点）
int QueueEmpty(LQueue *lqu); //链队是否为空（带头结点）
void EnQueue(LQueue *& lqu, ElemType x); //链队入队（带头结点）
int DeQueue(LQueue *& lqu, ElemType &x); //链队出队（带头结点）
void Traverse(LQueue * lqu); //遍历队列（带头结点）
//////////////////////////////////////////