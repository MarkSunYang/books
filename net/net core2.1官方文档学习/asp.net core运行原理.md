核心框架：
#   ASP.NET Core MVC
 ASP.NET Core MVC 提供了开发动态web站点的API，包括了WebPages 和 WebAPI ,最终可运行在IIS 或 自托管(self-hosted)的服务器中。

#   DependencyInjection 
包含了通用的依赖注入接口,用于在ASP.NET Core MVC中使用。

#   Entity Framework Core
与之前版本的EntityFramework版本类似是一个轻量级的ORM框架，包括了Linq,POCO和Codefirst的支持。

#   ASP.NET Core Identity
用于在ASP.NET Core web applications构建用户权限系统的框架，包括了membership、login等功能，同时也可以方便的扩展和自定义。


From handlers and modules to middleware
# MiddleWare 
1. Invoked in principle for every request
2. 可以不传送请求从而中断请求
3. 可创建自己的请求



# startup 和 Middleware
Configure方法用于每次http请求的处理，比如后面要讲的中间件(Middleware)，就是在configure方法中配置。
而ConfigureServices方法在Configure方法前调用，它是一个可选的方法，可在configureServices依赖注入接口或一些全局的框架，比如EntityFramework、MVC等
构造函数->configureServices->configure

1. Startup Constructor（构造函数）

2. ConfigureServices
主要实现了依赖注入(DI)的配置，方法参数如下：
IServiceCollection：整个ASP.NET Core 默认带有依赖注入(DI)，IServiceCollection是依赖注入的容器，

3. Configure方法
IApplicationBuilder: 用于构建应用请求管道。通过IApplicationBuilder下的run方法传入管道处理方法。这是最常用方法，对于一个真实环境的应用基本上都需要比如权限验证、跨域、异常处理等.

4. Middleware
中间件是一个处理http请求和响应的组件，多个中间件构成了处理管道(Handler pipeline)，每个中间件可以决定是否传递至管道中的下一中间件。一旦注册中间件后，每次请求和响应均会被调用。

中间件的注册在startup中的Configure方法完成，在configure方法中使用IApplicationBuilder对象的Run、Map、Use方法传入匿名委托(delegate)。

# Run & Use
添加一个中间件到请求管道