1.实例 
2.组件 
3.指令 
4.选项 
5.模板渲染 
6.事件绑定 
7.计算属性 
8.内置动画 
9.组件交互 

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

