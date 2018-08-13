参考：
http://www.cnblogs.com/yangecnu/p/Introduction-CQRS.html

CQRS 
命令查询分离    command query Responsibility Segregation 

最简单的方式:
读写代码分离，在查询的时候我们直接去读DB，在写数据的时候我们通过另一个项目进行写操作，
进一步优:
a.我们可以在写操作中加入MQ
b.在读写库分离，定时同步

关键思路：
a.Comamnd和Query采用完全不同的组织思路
b.Command执行后如果希望返回数据给UI，同步的使用Query进行查询。
c.Command和Query采用一个数据库。

    -> command->commandservice->commandhadler -DDD
系统                                                        ->DB
    ->Query->QueryService

CQRS是一种很简单清晰的设计模式：
他通过在业务上分离操作和查询来使得系统具有更好的可扩展性及性能，使得能够对系统的不同部分进行扩展和优化。
在CQRS中，所有的涉及到对DB的操作都是通过发送Command，

CQRS的实现有些复杂，很多地方比如 AggregationRoot、Domain Object都涉及到DDD中的相关概念


----------------------
不管是以前的Ado.net 还是现在的EntityFarmework
我们都是通过直接通过 DataAccess或者DbContext 更新获取查询数据

命令和查询责任隔离（CQRS）是一种模式，它通过使用单独的接口将读取数据（查询）的操作与更新数据（命令）的操作隔离开来。这意味着用于查询和更新的数据模型是不同的。然后可以隔离模型

Validataion
Commands           Read Model ->Query generate DTOs         
Domian logic 
Data Persistence ->Write Mode


先操一个简单的demo，我们需要
a.命令 b.事件 c.命令处理 d.事件处理
实现最小单元的CQRS