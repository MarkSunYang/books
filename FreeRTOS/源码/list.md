FreeRTOS 的 List 设计采用了双向链表 （LinkedList）结构

## 1.链表结构
FreeRTOS 的链表由两个核心结构组成
(1) 链表节点(ListItem_t)
```
struct xLIST_ITEM{
    TickType_t xItemValue;// 辅助排序 如 任务阻塞时间
    struct xLIST_ITEM *pxNext;      // 指向下一个节点
    struct xLIST_ITEM *pxPrevious;  // 指向前一个节点
    void *pvOwner;                  // 指向拥有该节点的对象（如TCB）
    void *pvContainer;              // 指向该节点所属的链表
}
```

双向链接:通过pxNext和pxPrevious实现双向遍历
排序依据:xItemValue用于节点在链表中的排序(例如在延时链表中按时间排序)
归属标记：pvOwner 和 pvContainer 用于快速定位节点的所有者和所属链表。

* 链表头
typedef struct xLIST {
    UBaseType_t uxNumberOfItems;    // 链表当前节点数
    ListItem_t *pxIndex;            // 遍历链表的指针（用于快速遍历）
    ListItem_t xListEnd;            // 链表的尾节点（哨兵节点）
} List_t;
哨兵节点（xListEnd）：链表的头和尾均指向此节点，构成环形结构，简化插入/删除操作。
快速遍历：pxIndex 用于记录遍历位置

## 2. 关键设计特点

1. 环形双向链表
链表首尾通过 xListEnd 连接成环，插入/删除节点时无需检查边界条件。
```
void vListInitialise(List_t *pxList){
    pxList->pxIndex= &(pxList->xListEnd);
    pxList->xListEnd.pxNext = &(pxList->xListEnd);
    pxList->xListEnd.pxPrevious = &(pxList->xListEnd);
}

```
2. 按值插入排序
节点按 xItemValue 升序排列（如延时链表中按任务唤醒时间排序）。
插入时从 xListEnd 开始遍历，找到合适位置：


3. 高效删除与遍历


###  实际应用场景




### 性能优化点