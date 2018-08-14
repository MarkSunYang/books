如果每次写ef查询条件的时候都是用如些
_dbcontext.Person.FirstorDefault(o=>o.Name="Malik"&&o.Age=22&& o.Status=1);
每次这么写都感觉有这么点丑陋

基本操作应该和linq lambda相似了 

Expression<Func<int, bool>> lambda = num => num < 5; 

通过Expression可以动态构造代码，并编译执行。
创建参数表达式 ：ParameterExpression numParam = Expression.Parameter(typeof(int), "num");
创建常量表达式：ConstantExpression five = Expression.Constant(5, typeof(int));
创建比较表达式：BinaryExpression numLessThanFive = Expression.LessThan(numParam, five);

手动加星：
创建表达式树：Expression<Func<int, bool>> exprTree = num => num < 5;
这应该使我们查询中用到比较多的；

如果我们要查询一个Person类
 Expression<Func<Person,bool>> predicate = (t=>t.Name== "在路上" && t.Status== "EBL");

 _dbcontext.Person.Where(predicate).FirstorDefault;
 这样我们就可以只在放到linq的表达式中了,
 这样写显然，会比 _dbcontext.Person.Where(o=>t=>t.Name== "在路上" && t.Status== "EBL").FirstorDefault;
 好，因为表达式可以动态构建，而且，这样抽出来，可以提高重用性。
 我们可以在查询的时候将表达式作为参数传入
 