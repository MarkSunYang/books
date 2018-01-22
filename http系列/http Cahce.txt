两个将改善网站速度的因素：
1.减少Request/Response 的次数
2.减少 client/server传输的字节数

缓存是减少请求 请求/响应，传输字节的最好的方式之一，
它提供了  一种 存储 客户/代理 缓存 http响应 ，这样就不要通过网络去请求

奥，带宽其实是要钱的。。。我们其实每天都是交钱上网的。。。

Cache-Related Request Headers
为了保证性能，
Microsoft Internet Explorer and other Web clients maintain a local cache of resources downloaded from remote Web servers.
客户端发请求的时候可能会发生如下动作：
1.访问远程服务器
2.Send a conditional HTTP request to the origin server asking for the resource only if it differs from the locally cached version
3.用一个本地的缓存版本

当客户端发送请求，请求头可能使用如下的请求头
1.Client Cache Headers
Pragma: no-cache 不接受缓存
If-Modified-Since: datetime 只有当资源在客户端提供的日期之后被修改时，服务器才应该返回所请求的资源。
If-None-Match: etagvalue 如果资源的ETAG与客户机提供的值不同，则服务器应该返回所请求的资源。ETAG是表示文件特定版本的唯一标识符

A client indicates that it has a cached response available for use by sending a "Conditional request" containing the headers If-Modified-Since or If-None-Match.
如果服务器对未修改的HTTP/304的条件请求进行了响应，那么客户机将被指示重用它的缓存响应，
否则服务器应该返回一个新的响应，客户端应该丢弃过期的缓存项。

HTTP 304: Not Modified
If-Modified-Since/Last-Modified

cache-control：
no-chache 说明强制每次请求直接发送给源服务器，而不经过本地缓存版本的校验。
max-age>0/max-age<=0  max-age>0 时 直接从游览器缓存中 提取 /max-age<=0 时 向server 发送http 请求确认 ,该资源是否有修改有的话 返回200 ,无的话 返回304. 

Expires：



Demo 一张图片，+helloworld webserver：IIS

第一次请求
status code 200
Request Headers:
method：get   url:/index.html  protocol HTTP/1.1
Cache-Control: no-cache
Pragma: no-cache
Client:
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8
Accept-Encoding: gzip, deflate, br
Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7
User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36
Cookies

第二次请求
statecode:304
Cache-Control: max-age=0
If-Modified-Since: Fri, 19 Jan 2018 07:58:02 GMT
If-None-Match: "f61a423bfb90d31:0"
Client部分没有改变











