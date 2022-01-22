# 对象 、 类、 面向对象编程

##  理解对象
创建自定义对象的通常方式是创建 Object 的一个新实例，然后再给它添加属性和方法
let person = new Object();
person.name = "Nicholas";
person.age = 29;
person.job = "Software Engineer";
person.sayName = function() {
 console.log(this.name);
};


### 数据属性
数据属性包含一个保存数据值的位置。值会从这位置读取，也会写入到这个位置，数据属性有4个特性
[[Configurable]] 表示属性是否可以通过delete删除并且重新定义
[[Enumerable]] 属性是否可以for-in循环
[[Writable]]
[[Value]] 

let person={
    name:"mark"
}
要修改属性的默认特性就要使用Object.defineProperty()方法，这个方法接受三个参数，
let person={}
Object.defineProperty(person, "name", {
 writable: false,
 value: "Nicholas"
});
console.log(person.name); // "Nicholas"
person.name = "Greg";
console.log(person.name); // "Nicholas" 

### 访问器属性
访问器属性不包含数据值。他们只包含getter和setter函数，不过这两个函数不是必须的

* 理解对象创建过程
* 理解继承
* 理解类


对象的创建

#### 函数创建对象(工厂模式)

function createPerson(name,age){
    let p={}
    p.name=name
    p.age=age
    return p
}



#### 构造函数创建对象
作用和工厂函数一致，代码更加简洁
function Person(name,age){
    this.name=name
    this.age=age
}
使用条件

let person1=new Person("mark","30");


function fn(){

}
let res1= fn()  undefined 没有返回值
let res2=new fn() 返回fn 对象

new
创建空对象
将this指向当前对象
给对象赋值
返回对象


#### 原型对象
什么是原型对象
原型对象的作用（解决什么问题）

（1）介绍构造函数中方法的性能问题
（2）使用全局函数解决构造函数性能问题，但是产生变量污染
（3）使用对象解决 变量污染 + 性能问题
（4）引入原型对象

function Person(name,age){
    this.name=name
    this.age=age

    //对象方法
    this.eat=function(){
        console.log('eat')
    }
}

 