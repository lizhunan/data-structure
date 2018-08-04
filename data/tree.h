char typedef ElemType;
int typedef ElemType_Int;
#define N 50

/* ���������������洢�ṹ��*/
typedef struct BinaryTreeNode
{
	ElemType data; //����Ԫ��
	struct BinaryTreeNode *lchild; //ָ�����ӽڵ�
	struct BinaryTreeNode *rchild; //ָ���Һ��ӽڵ�
}BTNode;

/* �������Ķ���������洢�ṹ���� */
typedef enum { Link, Thread } PointerTag; //Link����0��ʾָ�����Һ��ӣ�Thread����1��ʾָ��ǰ����������
typedef struct BinaryThreadTreeNode
{
	ElemType data;
	struct BinaryThreadTreeNode *lchild; //ָ�����ӽڵ�
	struct BinaryThreadTreeNode *rchild; //ָ���Һ��ӽڵ�
	PointerTag LTag; //���־
	PointerTag RTag; //�ұ�־
}BiTTNode, *BiTTNodeP;

/* Huffman Tree �ṹ���� */
typedef struct HuffmanTreeNode
{
	ElemType_Int data; //�ڵ�ֵ
	float weight; //Ȩ��ֵ 
	int parent; //˫�׽ڵ�
	int lchild; //���ӽڵ�
	int rchild; //�Һ��ӽڵ�
}HTNode;

/* Huffman���� */
typedef struct HuffmanCode
{
	char cd[N]; //��ŵ�ǰ�ڵ��Huffman Code
	int start; //��ʼλ��

}HCode;

void CreateBTNode(BTNode *& bt); //����������ʽ��������ǰ��
void PreOrderTraverse(BTNode *b); //ǰ��������ݹ��㷨��
void PreOrderTraverse_(BTNode *b); //ǰ��������ǵݹ��㷨��
void InOrderTraverse(BTNode *b); //����������ݹ��㷨��
void InOrderTraverse_(BTNode *b); //����������ǵݹ��㷨��
void PostOrderTraverse(BTNode *b); //����������ݹ��㷨��
void PostOrderTraverse_(BTNode *b); //����������ǵݹ��㷨��
void LeveOrderTraverse(BTNode *b); //�������������ʵ�֣�
int LeafCount(BTNode *b); //ͳ�ƶ�����Ҷ�ӽڵ����
int TreeDeep(BTNode *b); //��������ȣ����������
void InThreading(BiTTNodeP b); //���������������������
int InOrderTraverse_Thr(BiTTNodeP b); //�����������������������������T
void CreateHT(HTNode ht[], int n0); // ����Huffman Tree
void CreateHCode(HTNode ht[], HCode hcd[], int n0); //����Huffman����
//////////////////////////////////////////

