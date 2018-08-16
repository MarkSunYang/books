
四层架构：
MVC
Application

Domain：


Infrastructure

DTO一般用于远程服务，如果是内部使用的话，一般可以直接使用领域对象。

https://www.jianshu.com/p/a775836c7e25

https://my.oschina.net/hosee/blog/919426

http://paulovich.net/manga/

https://www.cnblogs.com/Leo_wl/p/4343242.html

https://www.jdon.com/ddd.html


1. 分层
UI：MVC(UI 展示)  WEBAPI（提供接口） 
Application： ApplicationService    UnitWork()    PresentationModel
Doamin：Aggregate，Entity，VAlueofObject，DomainService，DomainEvent
Infrastructure： Repository

2. 贫血、失血、充血模型
一般情况我们会分为 
MVC 中我们可能会分为DBModel 和 ViewModel
API 中我们可能会分为DBModel    ViewModel 和 RequestModel
DDD中：
失血模型：仅包含get;set;方法，业务逻辑和应用逻辑都放到服务层中
贫血模型：贫血模型中包含了一些业务逻辑，但不包含依赖持久层的业务逻辑。这部分依赖于持久层的业务逻辑将会放到服务层中。可以看出，贫血模型中的领域对象是不依赖于持久层的。
充血模型：充血模型中包含了所有的业务逻辑，包括依赖于持久层的业务逻辑。所以，使用充血模型的领域层是依赖于持久层，简单表示就是 UI层->服务层->领域层<->持久层。
胀血模型：胀血模型就是把和业务逻辑不想关的其他应用逻辑（如授权、事务等）都放到领域模型中。我感觉胀血模型反而是另外一种的失血模型，因为服务层消失了，领域层干了服务层的事，到头来还是什么都没变。

参考https://kb.cnblogs.com/page/520746/
