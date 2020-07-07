* ts 的优点：静态类型检查
* 类型注解

TypeScript 里的类型注解是一种轻量级的为函数或变量添加约束的方式。变量定义时也要定义他的类型

// 布尔值
let isDone: boolean = false; // 相当于 js 的 let isDone = false; // 变量定义之后不可以随便变更它的类型

isDone = true // 不报错
isDone = "我要变为字符串" // 报错

// 数字
let decLiteral: number = 6; // 相当于 js 的 let decLiteral = 6;

// 字符串
let name: string = "bob";  // 相当于 js 的 let name = "bob";


// 数组
// 第一种，可以在元素类型后面接上 []，表示由此类型元素组成的一个数组：
let list: number[] = [1, 2, 3]; // 相当于 js 的let list = [1, 2, 3];
// 第二种方式是使用数组泛型，Array<元素类型>：
let list: Array<number> = [1, 2, 3]; // 相当于 js 的let list = [1, 2, 3];

// 在 TypeScript 中，我们使用接口（Interfaces）来定义 对象 的类型。
interface Person {
    name: string;
    age: number;
}
let tom: Person = {
    name: 'Tom',
    age: 25
};
// 以上 对象 的代码相当于 
let tom = {
    name: 'Tom',
    age: 25
};

// Any 可以随便变更类型 (当这个值可能来自于动态的内容，比如来自用户输入或第三方代码库)
let notSure: any = 4;
notSure = "我可以随便变更类型" // 不报错
notSure = false;  // 不报错

// Void 当一个函数没有返回值时，你通常会见到其返回值类型是 void
function warnUser(): void {
    console.log("This is my warning message");
}

// 方法的参数也要定义类型，不知道就定义为 any
function fetch(url: string, id : number, params: any): void {
    console.log("fetch");
}
