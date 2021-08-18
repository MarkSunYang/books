#Startup 类
可选择性地包括 ConfigureServices 方法以配置应用的服务。
必须包括 Configure 方法以创建应用的请求处理管道。

通过 WebHostBuilderExtensions、UseStartup<TStartup> 方法指定 Startup 类：

Configure 方法用于指定应用响应 HTTP 请求的方式。 可通过将中间件组件添加到 IApplicationBuilder 实例来配置请求管道。 Configure 方法可使用 IApplicationBuilder，但未在服务容器中注册。 托管创建 IApplicationBuilder 并将其直接传递到 Configure。

每个 Use 扩展方法将中间件组件添加到请求管道。 例如，UseMvc 扩展方法将路由中间件添加到请求管道，并将 MVC 配置为默认处理程序。