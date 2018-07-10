nodejs restful api

1. 了解什么是restful

2. 常用的http方法
GET - 用于获取数据。
PUT - 用于更新或添加数据。
DELETE - 用于删除数据。
POST - 用于添加数据。

3. RESTful Web Services
Web service是一个平台独立的，低耦合的，自包含的、基于可编程的web的应用程序，可使用开放的XML（标准通用标记语言下的一个子集）标准来描述、发布、发现、协调和配置这些应用程序，用于开发分布式的互操作的应用程序。
基于 REST 架构的 Web Services 即是 RESTful。
由于轻量级以及通过 HTTP 直接传输数据的特性，Web 服务的 RESTful 方法已经成为最常见的替代方法。

4. 创建 restful api

URI        Http方法     发送内容        结果 
listUsers   Get          空             显示所有用户列表
addUser     POST         Json字符串     添加新用户
deleteUser  Delete       Json字符串     删除用户
:id         Get          空             显示用户详情


