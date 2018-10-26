查询处理
查询操作是关系数据库中使用最为频繁的操作，也是构成其他sql语句的基础，当然要删除或者更新记录时，首先要查询出这些记录，然后进行相应的sql操作，
因此基于select 的查询操作显得非常重要，对于查询处理，可以将逻辑查询分为
逻辑查询及物理查询处理，逻辑查询处理表示查询该产生什么样的结果，而物理查询代表mysql数据库是如何得到该结果的，两种查询的方法可能完全不同，但是得到的结果必定是相同的。

# 逻辑查询处理
sql 语言不同于其他编程语言， 最明显的不同体现在处理代码的顺序上，大多数语言中，代码按顺序被处理，而在sql语言中，第一个被处理的句子是from子句，

(8) select (9) distinct <select_list> 
(1) from <left_table>
(3) <join_type> join <right_table>
(2) on<join_condition>
(5) group by<group_by_list>
(6) with {cube|rollup}
(7) having<having_condition>
(10) order by <order_by_list>
(11) Limit <limit_number>

1. FROM 对from子句中的<left_tbale> 和 <right_table> 执行笛卡尔积，产生虚拟表 VT1
2. ON 对虚拟表VT1应用 ON 筛选，只有符合<join_conditon>的才被插入虚拟VT2中
3. JOIN 如果制定了OUTER JOIN (left outer join, right outer join)那么保留表中未匹配的行作为外部添加到虚拟表VT2，产生虚拟表VT3，如果FROM子句包含两个以上的表，则对上一个连接产生的结构VT3和下一个表重复执行步骤，直到处理完所有的表位置
4. WHERE 对虚拟VT3应用where条件过滤，只有符合<where_condition>的记录才会被插入到VT4中
5. GROUP BY 根据 group by子句中的列，对 vt4中的记录进行分组操作，产生vt5
6. cube|rollup 对vt5进行cube或rollup操作产生vt6
7. having 对虚拟表 vt6应用having 进行过滤，只有符合<having_condition>的记录才能被插入到虚拟表vt7中
8. 第二次执行select操作，选择指定的列，插入到虚拟表vt8
