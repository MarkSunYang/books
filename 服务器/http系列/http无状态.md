https://tools.ietf.org/html/rfc2616

1. http无状态是什么

2. http无状态带来了什么问题

3. 
只有session的身份验证
    Server: session[username] session[userpws]
    Client: request[username]
    验证    if(Request[username]== session[username]){
        //
    }
    因为session

4. cookie 的设置及分发步骤
step1. Client->Request->Server
step2. Server->Response With Set-Cookie Header->Client 
step3. Client->Request With Cookie Header->Server
step4. Server->Http Response->Client

语法：setcookie(name([,value,expire,path,domain])

https://www.cnblogs.com/moyand/p/9047978.html