更新数据库

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