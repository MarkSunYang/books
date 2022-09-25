#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义最大长度

typedef struct
{
    int data[MaxSize]; //用静态的数组存放数据
    int length;        //顺序表的长度
} SqList;              //顺序表的类型定义（静态分类方式）

/// @brief 初始化一个顺序表
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0; //初始化元素并默认为0,防止被分配到内存有脏数据，所以设置默认值
    }
    L.length = 0; //顺序表初始长度为0
    printf("init success");
}

#pragma region 插入及删除实现

/// @brief 插入
/// @param L
/// @param i 在位置i
/// @param e 插入元素e
bool ListInsert(SqList &L, int i, int e)
{
    //插入位置有效性验证
    if (i < 1 || i > L.length + 1)
        return false;

    //顺序表是否已满验证
    if (L.length >= MaxSize)
        return false;

    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1]; // i个元素及之后的元素后移
    }
    L.data[i - 1] = e; // i位置存放e
    L.length++;        //长度+1
    return true;
}

/// @brief 删除
/// @param L
/// @param i 在位置i
/// @param e 删除元素e
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length + 1)
        return false;

    if (L.length == 0)
        return false;

    e = L.data[i] - 1;
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

#pragma endregion

#pragma region 顺序表的按位查找

/// @brief 按位查找
void LocateElem()
{
}

int GetElem(SqList &L, int i)
{
    return L.data[i - 1];
}

#pragma endregion

/// @brief 程序入口main函数
/// @return int
int main()
{
    SqList L;
    InitList(L);
    system("pause");
    return 0;
}