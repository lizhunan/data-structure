char typedef ElemType;

// 二叉树（二叉链存储结构）
typedef struct BinaryTreeNode 
{
	ElemType data; //数据元素
	struct BinaryTreeNode *lchild; //指向左孩子节点
	struct BinaryTreeNode *rchild; //指向右孩子节点
}BTNode;

void CreateBTNode(BTNode *& bt); //二叉树（链式）建立（前序）
void PreOrderTraverse(BTNode *b); //前序遍历（递归算法）
void InOrderTraverse(BTNode *b); //中序遍历（递归算法）
void PostOrderTraverse(BTNode *b); //后序遍历（递归算法）
void LeveOrderTraverse(BTNode *b); //层序遍历
int LeafCount(BTNode *b); //统计二叉树叶子节点个数
int TreeDeep(BTNode *b); //二叉树深度（后序遍历）
//////////////////////////////////////////

