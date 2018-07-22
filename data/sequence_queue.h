int typedef ElemType;
#define MAX_SIZE 50 //Ĭ�ϳ���Ϊ50

//˳����У�ѭ�����У�
typedef struct SqQueue
{
	ElemType data[MAX_SIZE];
	int front, rear;	//���׺Ͷ�βָ��
}SqQueue;

void InitQueue(SqQueue &qu); //��ʼ������
int QueueEmpty(SqQueue qu);	//�ж϶����Ƿ�Ϊ��
int QueueFull(SqQueue qu); //�ж϶����Ƿ���
int QueueLength(SqQueue qu); //������г���
int EnQueue(SqQueue &qu,ElemType x); //����
int DeQueue(SqQueue &qu,ElemType &x); //����
//////////////////////////////////////////
