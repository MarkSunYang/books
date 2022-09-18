#  http cache 优化



参考：
https://developers.google.com/web/fundamentals/performance/optimizing-content-efficiency/http-caching?hl=zh-cn
https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Caching_FAQ



ajax 请求的cache 

1. Cache-Control: private, s-maxage=0
2. Cache-Control: public, max-age=3452, s-maxage=0

通过网络获取内容，速度缓慢开销巨大，较大的响应需要在客户端和服务器之间进行多次的往返通信，
这会延迟浏览器获得和处理内容的时间，还会增加访问者的流量费用，
因此缓存，并重复利用之前获取的资源的能力成为性能优化的一个关键方面，

每个浏览器都自带了http缓存实现功能，我们只要保证每个服务器响应都提供正确的http标头指令，以表示浏览器何时可以缓存响应及缓存多久。

https://developers.google.com/web/fundamentals/performance/optimizing-content-efficiency/images/http-request.png?hl=zh-cn
Brower
    200 ok
    content-length:2024
    cache-Control:max-age=120
    E-tag:"x23refg"
    data:
Server

# 通过 ETag 验证缓存的响应

服务器使用 ETag Http标头传递验证令牌
验证令牌可以实现高效的资源更新和检查；资源未发生变化时不会传递任何数据

假定在首次获取资源 120 秒后，浏览器又对该资源发起了新的请求。
首先，浏览器会检查本地缓存并找到之前的响应。
遗憾的是，该响应现已过期，浏览器无法使用。
此时，浏览器可以直接发出新的请求并获取新的完整响应。
过，这样做效率较低，因为如果资源未发生变化，那么下载与缓存中已有的完全相同的信息就毫无道理可言！
这正是验证令牌（在 ETag 标头中指定）旨在解决的问题。



# Cache-Control
每个资源都可通过 Cache-Control HTTP 标头定义其缓存策略
Cache-Control 指令控制谁在什么条件下可以缓存响应以及可以缓存多久。

“no-cache” 必须先与服务器确认返回的响应是否发生了变化，然后才能使用该响应来满足后续对同一网址的请求
“no-store” 它直接禁止浏览器以及所有中间缓存存储任何版本的返回响应


“public”与“private”
Public：设置Cache-Control：public来指定响应可由客户端和共享（代理）缓存缓存。
Private:来指定响应只能在客户端缓存，而不能由共享（代理服务器）缓存缓存。

“max-age” 指令指定从请求的时间开始，允许获取的响应被重用的最长时间（单位：秒）



# Cache-Control 说明
max-age=86400	浏览器以及任何中间缓存均可将响应（如果是“public”响应）缓存长达 1 天（60 秒 x 60 分钟 x 24 小时）。
private, max-age=600	客户端的浏览器只能将响应缓存最长 10 分钟（60 秒 x 10 分钟）。
no-store	不允许缓存响应，每次请求都必须完整获取。



https://codeday.me/bug/20181027/323495.html


# asp.net 如何实现 304 no

使用Response 实现缓存