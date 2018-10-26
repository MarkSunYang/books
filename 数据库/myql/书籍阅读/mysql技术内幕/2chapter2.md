类型属性：
Unsigned 和 zerofill 是否使用这两个属性对选择数据类型

# Unsigned 属性
将数字类型无符号化

# ZEROFILL

# SQL_MODE 

# 时间和类型分类
Mysql 数据库中有五种 和 日期和时间有关系的数据类型，各种日期类型所占的空间如下
datetime    8字节
date        3字节
timestamp   4字节
year        1字节
time        3字节

1.datetime和date
datetime 占用8个字节，是占用空间最多的一种日期类型，它显示了日期，同时也显示了时间，可以表达的日期范围 1000-01-01 00:00:00 - 9999-12-31 23:59:59

date只占用3个字节，可以显示的范围 1000-01-01 - 9999-12-31

mysql中的时间格式输入比较宽松
如果没有什么特殊的条件和系统要求，还是在输入时按照标准的YYYY-MM-DD:MM:SS格式来进行，

# 微秒  sqlserver的datetimeoffset ？？？

# Timestamp
timestamp 和 datetime 显示的结果是一样的，都是固定的yyyy-MM-dd HH:MM:SS
的形式，不同的是，timestamp占用四个字节，显示的范围，1970-01-01 00:00:00 UTC 到 2038-01-19 03：14：07 UTC，其中市级存储内容为 1970-01-01 到当前的毫秒数，

timestamp类型和datetime类型除了在显示时间范围有所不同还有如下不同：
1. 在create table的时候，timestamp的日期可以设置一个默认值，而datetime不行
2. 在update 表的时候，可以设置timestamp 类型的自动类更新时间为当前时间

日期和时间相关的函数：
时间格式化常用的dateformat

# 关于日期的经典 SQL 编程 问题

# 星期几的问题

# 数字类型
1. 整形 tinint,mallint,mediumint,int,bigint
2. 浮点型 数据库支持两种浮点类型，单精度的float类型以及双精度的 double percision类型，

# 高精度类型
decimal numberic 类型在mysql中被视为相同的类型，

# 字符类型
字符集