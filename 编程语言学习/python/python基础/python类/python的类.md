
python是面向对象的语言

#类 class  
用来描述具有相同的属性和方法的对象的集合。它定义了该集合中每个对象所共有的属性和方法。对象是类的实例。

#类变量 
类变量在整个实例化的对象中是公用的。类变量定义在类中且在函数体之外。类变量通常不作为实例变量使用。

#数据成员
类变量或者实例变量, 用于处理类及其实例对象的相关的数据。

# 方法重写
如果从父类继承的方法不能满足子类的需求，可以对其进行改写，这个过程叫方法的覆盖（override），也称为方法的重写。

#实例变量
定义在方法中的变量，只作用于当前实例的类。

#继承
即一个派生类（derived class）继承基类（base class）的字段和方法

#实例化：
创建一个类的实例，类的具体对象。

#方法：
类中定义的函数


# self 
self在定义时需要定义，但是在调用时会自动传入。
self的名字并不是规定死的，但是最好还是按照约定是用self
self总是指调用时的类的实例。

#添加，删除，修改类的属性
#python的内置属性
__dict__ : 类的属性（包含一个字典，由类的数据属性组成）
__doc__ :类的文档字符串
__name__: 类名
__module__: 类定义所在的模块（类的全名是'__main__.className'，如果类位于一个导入模块mymod中，那么className.__module__ 等于 mymod）
__bases__ : 类的所有父类构成元素（包含了一个由所有父类组成的元组）

#类的私有方法
__private_method：两个下划线开头，声明该方法为私有方法，不能在类的外部调用。在类的内部调用 self.__private_methods

Demo：

# 创建一个简单的类

class Employee:
    # 变量名称
    employee_count = 0

    # 构造函数，当创建了这个类的实例时就会调用该方法
    # self 代表类的实例，self 在定义类的方法时是必须有的
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.employee_count += 1

    def displayCount(self):
        print("Total Employee %d" % Employee.employee_count)

    def displayEmployee(self):
        print("Name:", self.name, "Salary:", self.salary)

emp1 = Employee("Zara", 2000)
emp2 = Employee("Manni", 5000)

emp1.displayCount()
emp1.displayEmployee()

#添加属性
emp1.score=90
del  emp1.score
# getattr(obj, name[, default]) : 访问对象的属性。
# hasattr(obj,name) : 检查是否存在一个属性。
# setattr(obj,name,value) : 设置一个属性。如果属性不存在，会创建一个新属性。
# delattr(obj, name) : 删除属性。