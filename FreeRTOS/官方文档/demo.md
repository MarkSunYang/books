
get 源码
https://github.com/FreeRTOS/FreeRTOS/releases/download/202212.01/FreeRTOSv202212.01.zip

## 至少要包含源文件
FreeRTOS/Source/tasks.c
FreeRTOS/Source/queue.c
FreeRTOS/Source/list.c
FreeRTOS/Source/portable/[compiler]/[architecture]/port.c.
FreeRTOS/Source/portable/MemMang/heap_x.c where 'x' is 1, 2, 3, 4 or 5.


## 可选的文件
If you need software timer functionality, then add FreeRTOS/Source/timers.c to your project.
If you need event group functionality, then add FreeRTOS/Source/event_groups.c to your project.
If you need stream buffer or message buffer functionality, then add FreeRTOS/Source/stream_buffer.c to your project.
If you need co-routine functionality, then add FreeRTOS/Source/croutine.c to your project (note co-routines are deprecated and not recommended for new designs).


## 头文件


## 配置文件
