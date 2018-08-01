char typedef ElemType;

// ���������������洢�ṹ��
typedef struct BinaryTreeNode 
{
	ElemType data; //����Ԫ��
	struct BinaryTreeNode *lchild; //ָ�����ӽڵ�
	struct BinaryTreeNode *rchild; //ָ���Һ��ӽڵ�
}BTNode;

void CreateBTNode(BTNode *& bt); //����������ʽ��������ǰ��
void PreOrderTraverse(BTNode *b); //ǰ��������ݹ��㷨��
void InOrderTraverse(BTNode *b); //����������ݹ��㷨��
void PostOrderTraverse(BTNode *b); //����������ݹ��㷨��
void LeveOrderTraverse(BTNode *b); //�������
int LeafCount(BTNode *b); //ͳ�ƶ�����Ҷ�ӽڵ����
int TreeDeep(BTNode *b); //��������ȣ����������
//////////////////////////////////////////

