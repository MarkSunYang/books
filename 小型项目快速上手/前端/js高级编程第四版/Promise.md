Promise 是一个对象，从它可以获取异步操作的消息。Promise 提供统一的 API，各种异步操作都可以用同样的方法进行处理

Promise对象有以下两个特点。
（1）对象的状态不受外界影响。Promise对象代表一个异步操作，有三种状态：pending（进行中）、fulfilled（已成功）和rejected（已失败）。

（2）一旦状态改变，就不会再变，任何时候都可以得到这个结果。Promise对象的状态改变，只有两种可能：从pending变为fulfilled和从pending变为rejected。

Promise也有一些缺点。首先，无法取消Promise，一旦新建它就会立即执行，无法中途取消。
其次，如果不设置回调函数，Promise内部抛出的错误，不会反应到外部。
第三，当处于pending状态时，无法得知目前进展到哪一个阶段（刚刚开始还是即将完成）。

### 同步
同步模式，即上述所说的单线程模式，一次只能执行一个任务，函数调用后需等到函数执行结束，返回执行的结果，才能进行下一个任务。如果这个任务执行的时间较长，就会导致「线程阻塞」。

### 异步
下面就来看看异步模式。 
异步模式，即与同步模式相反，可以一起执行多个任务，函数调用后不会立即返回执行的结果，如果任务A需要等待，可先执行任务B，等到任务A结果返回后再继续回调。 
最常见的异步模式就数定时器了


/* 例2.2 */
setTimeout(function() {
    console.log('taskA, asynchronous');
}, 0);
console.log('taskB, synchronize');
//while(true);

-------ouput-------
taskB, synchronize
taskA, asynchronous



### 回调函数
提起异步，就不得不谈谈回调函数了。上例中，setTimeout里的function便是回调函数。可以简单理解为：（执行完）回（来）调（用）的函数。


/******************同步回调******************/
var fun1 = function(callback) {
    //do something
    console.log("before callback");
    (callback && typeof(callback) === 'function') && callback();
    console.log("after callback");
}

var fun2 = function(param) {
    //do something
    var start = new Date();
    while((new Date() - start) < 3000) { //delay 3s
    }
    console.log("I'm callback");
}
fun1(fun2);



### 为什么使用Promise

/* 例2.7 */
sendRequest('test1.html', '').then(function(data1) {
    console.log('第一次请求成功, 这是返回的数据:', data1);
}).then(function(data2) {
    console.log('第二次请求成功, 这是返回的数据:', data2);
}).then(function(data3) {
    console.log('第三次请求成功, 这是返回的数据:', data3);
}).catch(function(error) {
    //用catch捕捉前面的错误
    console.log('sorry, 请求失败了, 这是失败信息:', error);
});


### 基础用法
上一小节我们认识了promise长什么样，但对它用到的resolve、reject、then、catch想必还不理解。下面我们一步步学习。

Promise对象代表一个未完成、但预计将来会完成的操作。
它有以下三种状态：

pending：初始值，不是fulfilled，也不是rejected
fulfilled：代表操作成功
rejected：代表操作失败

/* 例3.1 */
//构建Promise
var promise = new Promise(function (resolve, reject) {
    if (/* 异步操作成功 */) {
        resolve(data);
    } else {
        /* 异步操作失败 */
        reject(error);
    }
});


#### .then()
