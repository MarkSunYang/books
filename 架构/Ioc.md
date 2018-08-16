Ioc 是现在web开发中不可缺少的一部分，
他解耦了对象和对象之间的依赖，帮助我们去管理并去创建对象，
如果我们需要熟练使用，掌握某个框架就可以了，但是他的工作原理是什么？

首先我们要了解下对象的创建方式，
为什么我们要去了解对象的创建？因为Ioc容器的部分功能就是去帮助我们创建对象。
如果您了解过java，您可能知道java中创建对象的方式花样百出

1.new 方式去创建
2.反射创建对象，这里的方式就有多种了，我们去过一下：
首先我么需要了解下一个对象包含了什么信息：
比如我们创建控制台程序，创建一个Person类，并且实例化他，我们看下这个Person
namespace Client
{
    public class Person{
        public string Name{get;set}
    }
}
Person p = new Person();
我们并没有看见对象的过程，并且我们看到了
Client.Person
Name，
也就是说，在这个程序集内，我们创建这个Perso的时候，只需要知道他的命名空间和一个class对象就好了

然后我们再看下反射：
参考：
https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/reflection
https://docs.microsoft.com/zh-cn/dotnet/framework/reflection-and-codedom/reflection

反射提供描述程序集Assembly、模块Module和类型Type的对象class
以使用反射动态地创建类型的实例，将类型绑定到现有对象，或从现有对象中获取类型，然后调用其方法或访问器字段和属性。 如果代码中使用了特性，可以利用反射来访问它们。 有关更多信息，请参阅特性。

System.Reflection命名空间中的类与 System.Type 使你能够获取有关加载的程序集和其中定义的类型的信息，如类、接口和值类型。
程序集包含模块，模块包含类型，类型包含成员
反射提供封装程序集、模块和类型的对象。 可以使用反射动态地创建类型的实例，将类型绑定到现有对象，或从现有对象中获取类型。 然后，可以调用类型的方法或访问其字段和属性。 反射的典型用法如下所示：

a.使用Assembly 来定义和加载程序集，加载程序集清单中列出的模块，以及在此程序集中定位一个类型并创建一个它的实例。
Assembly是我们在使用反射的时候用了比较多的比如Load dll;

b.使用Module 发现信息,如包含模块的程序集和模块中的类。 还可以获取所有全局方法或模块上定义的其它特定的非全局方法。
这就啪啪打脸了Person p = new Person();创建完毕后，他的信息远远不止这么多
比如隐藏的构造函数；
  Person p = new Person();
  Module m = p.GetType().Module;//Gets the module (the DLL) in which the current System.Type is defined.
我们去列出这个Assembly中所有的模块

c.使用 ConstructorInfo 发现信息
如名称、参数、访问修饰符（如 public 或 private）和构造函数的实现详细信息（如 abstract 或 virtual） 
使用 Type 的 GetConstructors 或 GetConstructor 方法来调用特定构造函数。

在了解 ConstructorInfo的时候我们需要了解下BindingFlags 枚举：
Specifies flags that control binding and the way in which the search for members and types is conducted by reflection.
指定控制绑定和由反射执行的成员和类型搜索方法的标志。
然后下面的就是常的
MethodInfo
FieldInfo 
EventInfo
PropertyInfo 

下面回归主题,.net 中创建对象的几种方式
a. Activator 包含特定的方法，用以在本地或从远程创建对象类型，或获取对现有远程对象的引用。 此类不能被继承
a.1. Activator.CreateInstance (Type)
a.2. Activator.CreateInstance (Type, Object[])
两种方法区别仅为：创建无参数的构造方法和创建有参数的构造函数。
https://msdn.microsoft.com/zh-cn/library/system.activator(v=vs.110).aspx

b. var obj=Type.GetConstructor() 
obj.invoke(obj)


现在我们掌握了使用反射创建对象的实例，这样我们只要写一个泛型方法，只要需要实例化的是一个class
我们就能去创建他的实例；

试想，现在我们程序里面有100个类，如果每次使用你都去new，
但是现在我们只需要一个配置文件，然后就可以帮我们初始化所有的类了，


 public static T GetInstance<T>(Type instance)
        {
            Type typeImplement=null ;
            foreach (var item in container.Keys)
            {
                if (item.Equals(instance))
                {
                    typeImplement = container[item];
                }
            }
            if (typeImplement == null)
            {
                throw new Exception("未绑定数据类型");
            }
            var constructor = typeImplement.GetConstructors()[0];
            return (T)constructor.Invoke(null);
        }


参考：http://www.cnblogs.com/xishuai/p/3670292.html