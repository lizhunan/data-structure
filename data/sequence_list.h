
#define MAX_SIZE 50 //默认长度为50

int typedef ElemType;

typedef struct
{
	ElemType data[MAX_SIZE];
	int length;
}SqList;

void InitList(SqList &L);//构造空的顺序表L
int GetElem(SqList L, int i);//查询指定位置元素e
int LocateElem(SqList L, ElemType &e);//按元素查找指定元素e
int ListInstert(SqList & L, ElemType e, int i);//插入元素e
int ListDelete(SqList & L, ElemType e, int i);//删除元素e
void Merge(SqList L1, SqList L2, SqList &L3);//有序表的归并算法
//////////////////////////////////////////
void example_2_2_11(SqList &L, ElemType e);//例2-2-11
void example_2_2_12(SqList &L);//例2-2-12
void example_2_2_13(SqList &L, int p);//例2-2-13
void example_2_2_14(SqList &L, ElemType e);//例2-2-14
void example_2_2_15(SqList &L, ElemType e1, ElemType e2);//例2-2-15
void example_2_2_16(SqList &L);//例2-2-16
void example_2_2_17(SqList &L);//例2-2-17