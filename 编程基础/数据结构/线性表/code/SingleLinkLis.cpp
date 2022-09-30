#include <stdio.h>
#include <stdlib.h>

/// @brief 定义单链表结构体
typedef struct LNode
{
    int data;           //存放数据
    struct LNode *next; //存放下一个节点
} LNode, SingleLinkList;

/// @brief 头插法建立单链表
/// @param L
/// @return
SingleLinkList List_HeadInsert(SingleLinkList &L)
{
    LNode *s;
    int x;
    L = (SingleLinkList)malloc(sizeof(LNode)); //创建头结点
    L->next = null;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (SingleLinkList *)malloc(sizeof(LNode)); //创建新节点
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

/// @brief 尾插法
/// @param L
/// @return
SingleLinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (SingleLinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
}

/// @brief 按顺序查找结点值
/// @param L
/// @param i
/// @return
LNode *GetElem(SingleLinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return null;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
}

LNode *LocateElem(SingleLinkList L, int e)
{
    LNode *p =->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}


/// @brief 头插法建立单链表
/// @param L
/// @return
SingleLinkList ListHeadInsert(SingleLinkList &L)
{
    LNode *s, intx;
}