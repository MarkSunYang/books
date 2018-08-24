参考
https://www.cnblogs.com/yanweidie/p/autofac.html

https://autofac.readthedocs.io/en/latest/getting-started/index.html



使用autofac 代替.net core中的默认依赖注入容器

1.mvc 中集成 autofac
注册当前程序集中所有的接口及实现，
这样就不需要使用 RegisterType 一个个去注册了
builder.RegisterAssemblyTypes(typeof(Startup).Assembly).AsImplementedInterfaces();

public IServiceProvider ConfigureServices(IServiceCollection services)
{
    services.AddMvc();

    var builder = new ContainerBuilder();
    builder.Populate(services);
    builder.RegisterAssemblyTypes(typeof(Startup).Assembly).AsImplementedInterfaces();
    var Container = builder.Build();
    return new AutofacServiceProvider(Container);
}
参考
 http://www.cnblogs.com/maxzhang1985/p/5919936.html