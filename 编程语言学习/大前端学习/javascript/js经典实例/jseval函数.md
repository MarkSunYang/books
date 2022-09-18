eval() 函数可计算某个字符串，并执行其中的的 JavaScript 代码。

语法 eval(string) 
string 必须，要计算的字符串，其中含有要计算js表达式或者要执行的语句。

返回值：通过计算string得到的值，如果有的话

说明：该方法只接受原始字符串作为参数，如果string参数不是原始字符串，那么该方法将不作任何返回，因此不要为eval（）函数传递string对象来作为参数

如果试图覆盖 eval 属性或把 eval() 方法赋予另一个属性，并通过该属性调用它，则 ECMAScript 实现允许抛出一个 EvalError 异常。

抛出
如果参数中没有合法的表达式和语句，则抛出 SyntaxError 异常。
如果非法调用 eval()，则抛出 EvalError 异常。
如果传递给 eval() 的 Javascript 代码生成了一个异常，eval() 将把该异常传递给调用者。