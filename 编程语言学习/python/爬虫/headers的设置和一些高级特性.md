# 对付“反盗链”(服务器会识别headers中的referer是不是它自己,如果不是则不响应),构建以下headers  
headers = {"User-Agent": "Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)",  
           "Referer": "http://www.zhihu.com/articles"}  


headers的一些其他属性：  
# User-Agent : 有些服务器或 Proxy 会通过该值来判断是否是浏览器发出的请求  
# Content-Type : 在使用 REST 接口时，服务器会检查该值，用来确定 HTTP Body 中的内容该怎样解析。 
# application/xml ： 在 XML RPC，如 RESTful/SOAP 调用时使用 
# application/json ： 在 JSON RPC 调用时使用  
# application/x-www-form-urlencoded ： 浏览器提交 Web 表单时使用  
# 在使用服务器提供的 RESTful 或 SOAP 服务时， Content-Type 设置错误会导致服务器拒绝服务  

# Timeout设置  
# 为了解决一些网站实在响应过慢而造成的影响  
# 如果第二个参数data为空那么要特别指定是timeout是多少，写明形参，如果data已经传入，则不必声明  
response = urllib2.urlopen('http://www.baidu.com', timeout=10)  
response = urllib2.urlopen('http://www.baidu.com', data, 10)  