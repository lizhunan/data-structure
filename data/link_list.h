
int typedef ElemType;

//单链表
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkList;

void CreateListF(LinkList *&L, ElemType a[], int n);//采用头插法建立单链表
void CreateListR(LinkList *&L, ElemType a[], int n);//采用尾插法建立单链表
int LocateElem(LinkList *&L, ElemType e);//按元素值查找
void ListInstert(LinkList *&L, ElemType e, int i);//插入数据
void ListDelete(LinkList *&L, int i);//删除数据
void Merge(LinkList *L1, LinkList *L2, LinkList *&L3);//归并有序单链表
//////////////////////////////////////////////////////
int example_2_3_23(LinkList *&L, ElemType e);//例2_3_23
void example_2_3_26(LinkList *&L);//例2_3_26
void example_2_3_28(LinkList *&L);//例2_3_28
void example_2_3_29(LinkList *&A,LinkList *&B);//例2_3_29
void example_2_3_34(LinkList *&L,ElemType e);//例2_3_34
void example_2_3_36(LinkList *&L, ElemType min,ElemType max);//例2_3_36
void example_2_3_38(LinkList *&L);//例2_3_38
void example_2_3_40(LinkList *&L1 ,LinkList *&L2,LinkList *&L3);//例2_3_40
void example_2_3_42(LinkList *&L1, LinkList *&L2, LinkList *&L3);//例2_3_42