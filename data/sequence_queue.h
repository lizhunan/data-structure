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
int EnQueue(SqQueue &qu, ElemType x); //����
int DeQueue(SqQueue &qu, ElemType &x); //����
void Traverse(SqQueue qu); //��������
//////////////////////////////////////////
void example_4_2_19(SqQueue &qu); //�Զ��н�������
int example_4_2_22(SqQueue &qu, int k); //ɾ����K��Ԫ�أ�ʹ����ʱ���еķ���
int example_4_2_22(SqQueue &qu, int k, int item, int count); //�ڵ�K��Ԫ�غ����item����ʹ����ʱ���еķ������͵����
