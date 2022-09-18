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

https://www.cnblogs.com/weshow/p/10492826.html


https://www.cnblogs.com/weshow/p/10492826.html

创建迁移：migrationname为迁移名称	dotnet ef migrations add migrationName	add-migration migrationName
移除迁移(删除最近的一次迁移)	dotnet ef migrations remove	remove-migration
应用所有的迁移(使迁移文件应用到数据库)	dotnet ef database update	update-database
指定版本进行迁移	dotnet ef database update migrationName	update-database migrationName
生成对应版本的脚本	dotnet ef migrations script	Script-Migration
查看迁移列表	dotnet ef migrations list	 
查看数据库上下文信息	dotnet ef dbcontext info	 