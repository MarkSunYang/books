# vue 项目实战

1. 各种组件的安装
 axios  cnpm install axios --save-dev
 安装less 指定版本
 less安装可能因为版本问题出现不能使用
 原因： less-loader安装的版本过高
解决方案： 1.npm uninstall less-loader
2.npm install less-loader@6.0.0 --save-dev
在 webpack.base.conf.js
{
    test: /\.less$/,
    loader: "style-loader!css-loader!less-loader"
 }
清除之前package.json中的关于less的配置

2.全局样式表 gobal.css 和 iconfont的引用

 element ui
    element-form
    el-form-item
    el-input
    el-button

3. element ui的按需引用

4. 表单的数据绑定

5. 验证与预验证
表单的函数

6. 全局 Message的使用

7. Promis await 和 async

8. 路由导航守卫
没有权限的页面直接跳到登录页面
to:去哪个页面
from:从哪个页面来
next:放行
router.beforeEach((to,from,next)=>{

})

9. 退出功能实现原理
基于token，销毁本地token，后续请求就没有token，需要重新登录
window.sessionStorage.clear()
this.$router.push('/login')

10. Eslint语法警告

. local storage 和 session storage

11.主页布局

12. 清除npm缓存
npm cache clear --force