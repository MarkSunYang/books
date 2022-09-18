算术表达式可能是一个数、或者是由一个左括号、一个算术表达式、一个运算符、另一个算术表达式和一个右括号组成的表达式。为了简化问题，这里定义的是未省略括号的算术表达式，它明确地说明了所有运算符的操作数，形式如下：

（1+（（2+3）*（4*5）））
 表达式由括号，运算符，和操作数构成，我们根据下面四中情况从左到右将这些实体送入栈
1. 将操作数压入栈
2. 将运算符压入运算栈
3. 或略左括号
4. 在遇到右括号时，弹出一个运算符，弹出所需数量的操作数，并将运算后的结果压入操作数栈

Stack<char> operations = new Stack<char>();
            Stack<double> values = new Stack<double>();
            string express = "(1+((2+3)*(4*5)))";
            var expressChars = express.ToArray<char>();
            foreach (var item in expressChars)
            {
                switch (item)
                {
                    case '(':
                        //左括号不做操作
                        break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        operations.Push(item);//运算符做运算符入栈运算
                        break;
                    case ')':
                        //右括号：弹出一个数，弹出一个操作符做运算
                        var operation = operations.Pop();
                        var value = values.Pop();
                        switch (operation)
                        {
                            case '+':
                                value += values.Pop();
                                break;
                            case '-':
                                value -= values.Pop();
                                break;
                            case '*':
                                value *= values.Pop();
                                break;
                            case '/':
                                value = values.Pop()/ value;
                                break;
                        }
                        values.Push(value);
                        break;
                    
                    default:
                        values.Push(double.Parse(item.ToString()));//操作数压入栈
                        break;
                }
                
            }
            Console.WriteLine(values.Pop());   