1. 创建  nodejs项目
创建目录，npm install
创建 server.js文件

1.1 使用node http创建web服务器
nodejs提供了http模块，http模块主要用户搭建HTTP服务端口和客户端，使用HTTP服务器或客户端功能必须调用http模块
http代码如下：
var http= require("http");
function process_request(req,res){
    var body='thanks for calling me~';
    var content_length=body.length;
    res.writeHead(200,{
        'Content-Length':content_length,
        'Content-Type':'text/plain'
    });
    res.end(body);
}
var s=http.createServer(process_request);
s.listen(3000);

1.2 使用Express 框架
Express是一个简洁灵活的nodejs web应用框架，提供了一些列强大特性帮助我们创建各种web应用
Express框架核心特性：
1).可以设置中间件来响应http请求
2).定义了路由用于执行不同的HTTP请求动作
3).可以通过模板传递参数来渲染HTML页面

nodejs 安装 express
cnpm install express -g

Express使用回调函数的参数：request和response对象来处理请求和响应数据
app.get('/'function(req,res){

})
Request 对象 - request 对象表示 HTTP 请求，包含了请求查询字符串，参数，内容，HTTP 头部等属性。
req.app：当callback为外部文件时，用req.app访问express的实例


Response 对象 - response 对象表示 HTTP 响应，即在接收到请求时向客户端发送的 HTTP 响应数据。

路由：
路由决定了谁去响应客户端的请求，在http请求中，

静态文件：
Express 提供了内置的中间件 express.static 来设置静态文件如：图片， CSS, JavaScript 等。
你可以使用 express.static 中间件来设置静态文件路径。例如，如果你将图片， CSS, JavaScript 文件放在 public 目录下，你可以这么写：
app.use(express.static('public'));



2. 使用 node-sass  cnpm install -g node-sass
目录结构 css/main.scss 



引入 required 模块：
创建服务器：服务器可以监听客户端的请求，类似于 Apache 、Nginx 等 HTTP 服务器。
接收请求与响应请求 服务器很容易创建，客户端可以使用浏览器或终端发送 HTTP 请求，服务器接收请求后返回响应数据。

