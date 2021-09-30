1. 安装 cnpm install -g typescript
2. vscode 开发配置（自动编译设置）
https://blog.csdn.net/weixin_44523860/article/details/104119488

3. ts的数据类型（和后端语言类似）

//布尔
var flag:boolean=true

//number 类型
var a:number=123

//字符串类型
var str:string ="this is str"

// 数组类型
let arr:number[]=[1,2,3]
let arr:Array<number>=[,123,]

//元组 类型

//枚举类型
enum Flag{
    success=1,
    error=2
}


Any 任意类型


// null 和 undefined
var num:number;undefined  //正确

var num:null
num=null 报错


// void 类型 定义方法用到

function run(): void {

}



// 函数的定义

function run(){}

var run2=function(){}  匿名函数

// ts 中定义函数的方法 
function run():string(){
    return '123';
}

var fun= function():number(){

}

// 方法传参

function run(name:string,age:number):string{
    return '123';
}
