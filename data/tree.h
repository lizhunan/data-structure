char typedef ElemType;
int typedef ElemType_Int;
#define N 50

/* 二叉树（二叉链存储结构）*/
typedef struct BinaryTreeNode
{
	ElemType data; //数据元素
	struct BinaryTreeNode *lchild; //指向左孩子节点
	struct BinaryTreeNode *rchild; //指向右孩子节点
}BTNode;

/* 二叉树的二叉线索书存储结构定义 */
typedef enum { Link, Thread } PointerTag; //Link等于0表示指向左右孩子，Thread等于1表示指向前驱或后继线索
typedef struct BinaryThreadTreeNode
{
	ElemType data;
	struct BinaryThreadTreeNode *lchild; //指向左孩子节点
	struct BinaryThreadTreeNode *rchild; //指向右孩子节点
	PointerTag LTag; //左标志
	PointerTag RTag; //右标志
}BiTTNode, *BiTTNodeP;

/* Huffman Tree 结构定义 */
typedef struct HuffmanTreeNode
{
	ElemType_Int data; //节点值
	float weight; //权重值 
	int parent; //双亲节点
	int lchild; //左孩子节点
	int rchild; //右孩子节点
}HTNode;

/* Huffman编码 */
typedef struct HuffmanCode
{
	char cd[N]; //存放当前节点的Huffman Code
	int start; //起始位置

}HCode;

void CreateBTNode(BTNode *& bt); //二叉树（链式）建立（前序）
void PreOrderTraverse(BTNode *b); //前序遍历（递归算法）
void PreOrderTraverse_(BTNode *b); //前序遍历（非递归算法）
void InOrderTraverse(BTNode *b); //中序遍历（递归算法）
void InOrderTraverse_(BTNode *b); //中序遍历（非递归算法）
void PostOrderTraverse(BTNode *b); //后序遍历（递归算法）
void PostOrderTraverse_(BTNode *b); //后序遍历（非递归算法）
void LeveOrderTraverse(BTNode *b); //层序遍历（队列实现）
int LeafCount(BTNode *b); //统计二叉树叶子节点个数
int TreeDeep(BTNode *b); //二叉树深度（后序遍历）
void InThreading(BiTTNodeP b); //中序遍历进行中序线索化
int InOrderTraverse_Thr(BiTTNodeP b); //遍历线索树，中序遍历二叉线索树T
void CreateHT(HTNode ht[], int n0); // 构造Huffman Tree
void CreateHCode(HTNode ht[], HCode hcd[], int n0); //构造Huffman编码
//////////////////////////////////////////

