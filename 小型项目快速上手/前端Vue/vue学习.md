# 1.实例 
# 2.组件 

## 2.1 父组件向子组件传递值

props / $emit
eg.
在子组件 Users中获取父组件App  users:['mark','matt','malik']的值
* 1 定义父组件，定义父组件的数据，在父组件中使用子组件
* 2 在子组件中定义pops,用于接收父组件传过来的值

父组件通过props向下传递数据给子组件。注：组件中的数据共有三种形式：data、props、computed

如果是多层，这样传递会比较麻烦
这样适合父组件向子组件传递，反之不行

## 2.2 子组件向父组件传值 （通过事件形式）
会使用 $emit
参数 {}eventName
     [...args]

vm.$emit( event, arg ) //触发当前实例上的事件

### 2.2.2 $emit/$on
这种方法通过一个空的Vue实例作为中央事件总线（事件中心），用它来触发事件和监听事件,巧妙而轻量地实现了任何组件间的通信，包括父子、兄弟、跨级。当我们的项目比较大时，可以选择更好的状态管理解决方案vuex。

1.具体实现方式：
    var Event=new Vue();
    Event.$emit(事件名,数据);
    Event.$on(事件名,data => {});


* 1 子组件绑定事件，子组件的事件使用  this.$emit("父组件事件名称", "子向父组件传值"); 
* 2 定义 父组件事件名称 方法

子组件通过events给父组件发送消息，实际上就是子组件把自己的数据发送到父组件。


## 2.3 vuex

 ## 2.4 $attrs/$listensers
 


# 3.指令 
# 4.选项 
# 5.模板渲染 
# 6.事件绑定 
# 7.计算属性 
# 8.内置动画 
# 9.组件交互 

10.内置路由
 router-link

  不带参数
 // 注意：router-link中链接如果是'/'开始就是从根路由开始，如果开始不带'/'，则从当前路由开始。
 <router-link :to="{name:'home'}"> 
<router-link :to="{path:'/home'}"> //name,path都行, 建议用name  
    带参数
    <router-link :to="{name:'home', params: {id:1}}"> 
// params传参数 (类似post)
// 路由配置 path: "/home/:id" 或者 path: "/home:id" 
// 不配置path ,第一次可请求,刷新页面id会消失
// 配置path,刷新页面id会保留


 this.$router.push() 函数里面调用
    this.$router.push('/home') 
    this.$router.push({name:'home'}) 
    this.$router.push({path:'/home'})


 this.$router.replace() (用法同push)
 this.$router.go(n)

vue router的路由是不包含在框架里面的，需要单独安装

step1. 安装 cnpm install vue-router
<router-link> 是一个组件，该组件用于设置一个导航链接，切换不同 HTML 内容。 to 属性为目标地址， 即要显示的内容。


11. vue 脚手架

12. iview 的使用
cnpm install view-design --save

