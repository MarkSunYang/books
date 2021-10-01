vs中快速使用ef

1. 实体解决方案
实体与数据库的map
当前项目需要的引用：
1、Microsoft.EntityFrameworkCore
这是ef core的核心包

2、Microsoft.EntityFrameworkCore.SqlServer
sqlserver 数据库驱动包

3、Microsoft.EntityFrameworkCore.Tools
工具扩展包

4、Microsoft.EntityFrameworkCore.Proxies
延迟加载实现包


2. web解决方案
appsetting.json 
"ConnectionStrings": {
    "SqlServerConnection": "Server=192.168.1.;Database=Test_Atuh;uid=;pwd=;MultipleActiveResultSets=true"
  }

依赖注入
    var connection = Configuration.GetConnectionString("SqlServerConnection");
            services.AddDbContext<AuthCenterContext>(o =>
            {
               o.UseSqlServer(connection);
            });