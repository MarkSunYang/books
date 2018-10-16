参考：
https://www.cnblogs.com/mouhong-lin/archive/2012/03/28/cqrs-command.html

http://www.infoq.com/cn/articles/from-cqs-to-cqrs

https://www.codeproject.com/Articles/991648/CQRS-A-Cross-Examination-Of-How-It-Works

http://www.bubuko.com/infodetail-1372.html

https://www.cnblogs.com/bugly/p/5475034.html

CQRS 名词

ICommand Command 定义唯一ID
所有的命令都会被发送到 Command Bus
Command Bus 命令总线实际上只是用来获得传入命令的处理程序
Command Handlers 这些处理程序将处理执行命令逻辑。在传入命令和命令处理程序之间应该有一个1:1的映射。
Domian
Services
Repository

Event 
Event Bus 这是用来发布应用到领域模型的事件的。
Event Handlers 事件处理程序的主要目的是接收事件并更新所读取的领域模型
Thin Data Layer
Query Facade


https://www.youtube.com/watch?v=JHGkaShoyNs

https://www.youtube.com/watch?v=icyvKTuZkzE