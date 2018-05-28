int typedef ElemType;

//双链表
typedef struct DLinkList
{
	ElemType data;
	struct DLinkList *prior;
	struct DLinkList *next;
}DLinkList;

void CreateDListF(DLinkList *&L, ElemType a[], int n);//头插法建立双链表
void CreateDListR(DLinkList *&L, ElemType a[], int n);//尾插法建立双链表
int FindNode(DLinkList *&L, ElemType e);//查找指定元素值的节点
int ListInsert(DLinkList *&L, int i, ElemType e);//插入元素
int ListDelete(DLinkList *&L, int i);//删除元素
void example_2_4_12(DLinkList *&L, int x,int y);//例2-4-12
void example_2_4_14(DLinkList *&L);//例2-4-14
void example_2_4_15(DLinkList *&L);//例2-4-15