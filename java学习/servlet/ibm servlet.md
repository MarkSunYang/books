
Tomcat
    Container
        Engine
            Host
                Servlet容器
                    Context
                        Wrapper  

Tomcat的容器分为四个等级，真正管理Servlet的容器是Context容器，一个Context对应一个web工程

<Context path="/projectOne " docBase="D:\projects\projectOne" reloadable="true" />


# Servlet容器启动的过程
