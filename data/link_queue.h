int typedef ElemType;

//���������ݽڵ�����
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
} QNode;
//���ӽڵ�����
typedef struct LQueue
{
	QNode *front;
	QNode *rear;
}LinkQueue;

void InitQueue(LQueue *& lqu); //��ʼ�����ӣ���ͷ��㣩
int QueueEmpty(LQueue *lqu); //�����Ƿ�Ϊ�գ���ͷ��㣩
void EnQueue(LQueue *& lqu, ElemType x); //������ӣ���ͷ��㣩
int DeQueue(LQueue *& lqu, ElemType &x); //���ӳ��ӣ���ͷ��㣩
void Traverse(LQueue * lqu); //�������У���ͷ��㣩
//////////////////////////////////////////