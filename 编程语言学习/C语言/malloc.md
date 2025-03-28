malloc 是 C 语言中用于动态分配内存的标准库函数。它从堆（heap）中分配一块指定大小的内存，并返回指向该内存的指针。malloc 是编写动态内存管理代码的基础工具。

## 1. 函数原型
malloc 的函数原型定义在 <stdlib.h> 头文件中：
void* malloc(size_t size);
参数： size：需要分配的内存大小（以字节为单位）。

返回值：
成功时，返回指向分配内存的指针。
失败时，返回 NULL。

## 2. 基本用法
分配内存
malloc 可能会分配失败（例如内存不足），返回 NULL。
使用 malloc 后，必须检查返回值是否为 NULL。

释放内存
使用 malloc 分配的内存必须手动释放，否则会导致内存泄漏。

使用 free 函数释放内存
释放后，将指针设置为 NULL，以避免悬空指针
不能对同一块内存多次调用 free，否则会导致未定义行为。

5. 常见问题
（1）内存泄漏
如果忘记调用 free，会导致内存泄漏。

确保每次 malloc 都有对应的 free。

（2）悬空指针
释放内存后，指针仍然指向原来的地址，称为悬空指针。

释放后应将指针设置为 NULL：