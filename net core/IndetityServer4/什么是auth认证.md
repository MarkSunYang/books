1. OAuth是什么？
2. OAuth有什么用？为什么要使用OAuth？
3. OAuth原理

4. Auth角色
OAuth中有三方：
一，用户；
二，Consumer（不知杂翻译，类似上面的 twitterfeed 角色）；
twitter申请oauth的话，在 setting - connection - developer 里面申请。 同时给出三个访问网址：
request_token_url = 'http://twitter.com/oauth/request_token'
access_token_url = 'http://twitter.com/oauth/access_token'
authorize_url = 'http://twitter.com/oauth/authorize'
当Consumer接到用户请求想要访问第三方资源（如twitter）的时候
oauth_consumer_key：Consumer Key
oauth_signature_method：签名加密方法
oauth_signature：加密的签名 （这个下面细说）
oauth_timestamp：UNIX时间戳
oauth_nonce：一个随机的混淆字符串，随机生成一个。
oauth_version：OAuth版本，可选，如果设置的话，一定设置为 1.0
oauth_callback：返回网址链接。
及其它服务提供商定义的参数

三，服务提供商（如上例的twitter角色）。