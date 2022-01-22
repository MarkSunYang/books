# 集合引用类型

## 对象 


## 数组与定型数组


## Map WeakMap、Set、WeakSet


### 6.1 Object对象
创建方式
方法1
let person=new Object();
person.name="mark"
person.age=29

方法2
let person={
    name:"",
    age:
}

#### tips
let person = {}; // 与 new Object()相同
在使用对象字面量表示法定义对象时，并不会实际调用 Object 构造函数。

虽然使用哪种方式创建 Object 实例都可以，但实际上开发者更倾向于使用对象字面量表示法。这
是因为对象字面量代码更少，看起来也更有封装所有相关数据的感觉

function displayInfo(args) {
 let output = "";
 if (typeof args.name == "string"){
 output += "Name: " + args.name + "\n";
 }
 if (typeof args.age == "number") {
 output += "Age: " + args.age + "\n";
 }
 alert(output);
}
displayInfo({
 name: "Nicholas",
 age: 29
});
displayInfo({
 name: "Greg"
}); 


### Array
#### 创建数组
let colors=new Array();


#### 迭代方法
every() 
filter()
forEach()
map()
some()

every 用法
let numbers = [1, 2, 3, 4, 5, 4, 3, 2, 1];
let everyResult = numbers.every((item, index, array) => item > 2);
alert(everyResult); // false

some 用法
let someResult = numbers.some((item, index, array) => item > 2);
alert(someResult); // true 

Filter 用法
let numbers = [1, 2, 3, 4, 5, 4, 3, 2, 1];
let filterResult = numbers.filter((item, index, array) => item > 2);
alert(filterResult); // 3,4,5,4,3 

forEach 用法
let numbers = [1, 2, 3, 4, 5, 4, 3, 2, 1];
numbers.forEach((item, index, array) => {
 // 执行某些操作
}); 



const m = new Map();
const m1 = new Map([
 ["key1", "val1"],
 ["key2", "val2"],
 ["key3", "val3"]
]);
alert(m1.size); // 3