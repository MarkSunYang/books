官方文档
https://ocelot.readthedocs.io/en/latest/

# 什么是API网关
类似门面模式，由于移动端设备的多样性，对于请求进行管理
在网关层进行非业务的业务功能处理

# ocelot
微软自家的

# ocelot 的流程
实际上Ocelot就是一系列按特定顺序排列的中间件。
Ocelot首先通过配置将HttpRequest对象保存到一个指定的状态直到它到达用来创建HttpRequestMessage对象并将创建的HttpRequestMessage对象发送到下游服务中的请求构造中间件。通过中间件来发出请求是Ocelot管道中做的最后一件事。它不会再调用下一个中间件。下游服务的响应会存储在每个请求 scoped repository中，并作为一个请求返回到Ocelot管道中。有一个中间件将HttpResponseMessage映射到HttpResponse对象并返回给客户端。
接下来是你使用Ocelot是可能会使用的配置。

# ocelot 的基本集成

目前环境 .net core 2.2
安装命令 install-package Ocelot   （具体需要看对应版本）
因为最新版本不支持.net core 2.2 所以需要自己匹配版本

# 手动安装
.net core 2.0
Ocelot 13.5.2


# 路由
Ocelot的主要功能是接收传入的http请求并将它们转发到下游服务。Ocelot当前仅以另一个http请求的形式支持此功能（将来可能是任何传输机制）。

"ReRoutes": []

DownstreamPathTemplate，DownstreamScheme和DownstreamHostAndPorts定义了将请求转发到的URL。

DownstreamHostAndPorts 是一个集合，用于定义您希望将请求转发到的任何下游服务的主机和端口。

默认的ReRouting配置不区分大小写！