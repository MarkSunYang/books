# 1. servlet的生命周期
初始化： web容器加载servlet 调用init()方法
处理请求: 当请求到达时，运行其service()方法,service()自动派遣运行与请求相对应的doXXX（doGet或者doPost）方法。
销毁：服务结束，web容器会调用servlet的distroy()方法销毁servlet。

# 2、get提交和post提交有何区别
get一般用于从服务器上获取数据，post一般用于向服务器传送数据
get 是在参数后面拼接，而post是放在http包含的包含体中。
能提交的数据区别，get提交的数据只能是文本，而post可以提交二进制文件

# 3. JSP 和 Servlet的区别
servlet 是服务器端的程序，动态生成html页面发送到客户端，但是这样程序里面会有很多的out.print()，java和html语言混在一起，很乱，后来sun公司推出了jsp，
jsp其实是servlet，每次运行的时候jsp会被编译成servlet文件，然后被编译成.class文件，有了jsp，在mvc项目中servlet不再负责动态生成页面，转而负责控制器逻辑的作用，控制jsp和javaben的流转

# 4. doget 和dopost的两个参数
HttpServletRequest：封装了与请求相关的信息
HttpServletResponse：封装了与响应相关的信息

# 5. request.getAttribute()和request.getParameter

# 6. jsp的内置对象，作用是什么
request         包含用户端请求的信息
response        包含服务器传回客户端的响应信息
session         与请求有关的会话期
pageContext     管理网页属性
application     服务器启动时创建，服务器关闭时停止，为多个应用程序保存信息
out             向客户端输出数据
config          servlet的架构部件
page            指网页本身
exception       针对错误页面才可使用

# 7. 四种跟踪技术作用域
（1）page：一个页面
（2）request：：一次请求
（3）session：一次会话
（4）application：服务器从启动到停止。

# 8. JSP中动态INCLUDE和静态INCLUDE有什么区别

include指令用于把另一个页面包含到当前页面中，在什么时候包含的？再转换成servlet的时候包含进去的。
动态INCLUDE用jsp:include动作实现 <jsp:include page="included.jsp" flush="true" />它总是会检查所含文件中的变化,适合用于包含动态页面,
并且可以带参数.

