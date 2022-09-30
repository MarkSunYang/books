#include <stdio.h>
#include <stdlib.h>
#define InitSize 10

typedef struct
{
    int *data;   //用静态的数组存放数据
    int MaxSzie; //顺序表最大容量
    int length;  //顺序表的长度
} SqList;        //顺序表的类型定义（静态分类方式）

/// @brief 初始化一个顺序表
void InitList(SqList &L)
{
    //使用malloc函数申请一片连续的存储空间
    L.data=(int*)malloc(InitSize*sizeof(int));
    L.length=0;
    L.MaxSzie=InitSize;
    printf("init success");
}



/// @brief 程序入口main函数
/// @return int
int main()
{
    SqList L;
    InitList(L);
    system("pause");
    return 0;
}