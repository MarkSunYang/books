# 1.实例 
# 2.组件 

## 组件名
Vue.component('my-component-name', { /* ... */ }) //字母全小写且必须包含一个连字符


## 全局注册
## 局部注册

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



## 生命周期
在 Vue 中要渲染一块页面内容的时候，会有这么几个过程：

1). 解析语法生成 AST。 
2). 根据 AST 结果，完成 data 数据初始化。 
3). 根据 AST 结果和 data 数据绑定情况，生成虚拟 DOM。 
4). 将虚拟 DOM 生成真正的 DOM 插入到页面中，此时页面会被渲染。
5). 框架接收到数据变更的事件，根据数据生成新的虚拟 DOM 树。 
6). 比较新旧两棵虚拟 DOM 树，
7). 把差异应用到真正的 DOM 树上，即根据差异来更新页面内容。
8). 注销实例，清空页面内容，移除绑定事件、监听器等。

生命周期钩子

1 之后，2 之前  beforeCreate：  初始化实例前，data 属性等不可获取
2 之后，3 之前  created：       实例初始化完成，此时可获取 data 里数据，无法获取 DOM	
3 之后，4 之前  beforeMount：   虚拟 DOM 创建完成，此时未挂载到页面中
4 之后          mounted：       数据绑定完成，真实 DOM 已挂载到页面
6 之后，7 之前  beforeUpdate：  数据更新，DOM Diff 得到差异，未更新到页面
7 之后          updated：       数据更新，页面也已更新
8 之前          beforeDestroy： 实例销毁前
8 之后          destroyed：     实例销毁完成

我们可以在某些生命周期中做一些事情，例如created事件中，可以拿到基础的数据，并根据这些数据可以开始进行后台请求了。

#数据