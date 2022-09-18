# Task.Run(Action) 方法
将在线程池上运行的指定工作排队，并返回代表该工作的 Task 对象。

Task类的表示单个操作不会返回一个值，通常以异步方式执行。

因为由执行工作Task对象通常以异步方式执行线程池线程上而不是以同步方式在主应用程序线程中，
可以使用Status属性，并将IsCanceled， IsCompleted，和IsFaulted属性，以确定任务的状态。
大多数情况下，lambda 表达式用于指定该任务所执行的工作量。

# 任务实例化

下面的示例创建并执行四个任务。 三个任务执行Action<T>名为的委托action，这样便可以接受类型的自变量Object。 第四个任务执行 lambda 表达式 (Action委托)，它是以内联方式定义的任务创建方法调用中。 每个任务是实例化，并以不同方式运行：

# 创建和执行任务
Task 可能在不同的方式中创建实例。 最常用的方法，从开始提供.NET Framework 4.5，是调用静态Run方法。 Run方法提供了简单的方法来启动任务使用默认值，而无需其他参数。 下面的示例使用Run(Action)方法以启动循环，然后显示循环迭代数的任务：

Task t = Task.Run( () => {
                                  // Just loop.
                                  int ctr = 0;
                                  for (ctr = 0; ctr <= 1000000; ctr++)
                                  {}
                                  Console.WriteLine("Finished {0} loop iterations",
                                                    ctr);
                               } );
      t.Wait();

# 分离任务创建和执行

#等待一个或多个任务完成
使用Wait();

属性和方法：




#对于返回值的操作，您使用Task<TResult>类。
# Task<TResult>.Run(Func<TResult> function)
将在线程池上运行的指定工作排队，并返回 function 所返回的任务的代理项。
