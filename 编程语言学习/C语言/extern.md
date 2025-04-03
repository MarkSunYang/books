
extern 是 C 语言中的一个存储类说明符，用于声明变量或函数的外部链接性。

### 1.声明外部变量

当在一个源文件中使用另一个源文件中定义的全局变量时，需要使用 extern 进行声明：

```
// file1.c
int globalVar = 10;  // 定义全局变量
-----------------------------------

// file2.c
extern int globalVar;  // 声明外部变量

void func() {
    printf("%d\n", globalVar);  // 使用其他文件中定义的全局变量
}

```

### 2. 声明外部函数

对于在其他源文件中定义的函数，使用 extern 可以明确表示这是外部函数（实际上函数声明默认就是 extern 的，所以通常可以省略）：
```
// file1.c
void func() {
    // 函数实现
}

// file2.c
extern void func();  // 声明外部函数（extern可省略）

```

### 3. 与头文件配合使用
```
// header.h
extern int globalVar;  // 声明
extern void func();    // 声明

// file1.c
#include "header.h"
int globalVar = 10;    // 定义
void func() { ... }    // 定义

// file2.c
#include "header.h"
// 可以直接使用 globalVar 和 func()

```
1. extern 只是声明不是定义，它不会分配存储空间
2. 一个变量可以有多个 extern 声明，但只能有一个定义
3. 对于函数，extern 可以省略，因为函数默认就是外部链接的
4. 在 C++ 中，extern "C" 有特殊含义，用于 C 链接约定