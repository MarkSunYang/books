node 是单线程运行的，但是它使用的是事件驱动来处理并发，这样有助于我们在多核cpu中创建多个子进程
从而提高性能
每个子进程总是有三个对象流：child.stdin, child.stdout, child.stderr, 他们可能会共享父进程的stdio流
或者也是独立被导流的对象
Node提供了child_process模块来创建子进程，方法有
exec - child_process.exec 使用子进程执行命令，缓存子进程的输出，并将子进程的输出以回调函数参数的形式返回。
spawn - child_process.spawn 使用指定的命令行参数创建新进程。
fork - child_process.fork 是 spawn()的特殊形式，用于在子进程中运行的模块，如 fork('./son.js') 相当于 spawn('node', ['./son.js']) 。与spawn方法不同的是，fork会在父进程与子进程之间，建立一个通信管道，用于进程之间的通信。

