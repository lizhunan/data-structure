#pragma once

typedef int Elemtype;
typedef int Status;
Status ListInsert(LinkList *L, int i, Elemtype e);
Status GetElem(LinkList L, int i, Elemtype *e);