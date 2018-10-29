使用codefirst初始化数据库
https://docs.microsoft.com/zh-cn/ef/core/miscellaneous/configuring-dbcontext#onconfiguring

ef
工具
https://www.cnblogs.com/bubugao/p/ef1.html



1.新建库
Enable-Migrations -EnableAutomaticMigrations
Add-Migration InitialCreate
Update-Database -Verbose

2.如果添加新的实体
则Add-Migration 注明这次添加的信息比如
比如添加一个Post类，
Add-Migration add-Post
然后执行
Update-Database -Verbose


注意1：如果使用List<>关系作为外键可能会发生问题，具体问题具体分析