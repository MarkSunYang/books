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




###  关于页面模块

## 1. 菜单
const menus = [
  {
    text: "服务管理", // 父菜单名字
    icon: "el-icon-setting", // 父菜单图标
    subMenus: [{ text: "服务信息" }, { text: "新增" }] // 子菜单列表
  },
  {
    text: "产品管理",
    icon: "el-icon-menu",
    subMenus: [{ text: "产品信息" }]
  },
  {
    text: "日志信息",
    icon: "el-icon-message"
  }
];

## 2.列表
const tableItem = {
  date: "2019-05-20", // 日期
  name: "被删", // 姓名
  phone: "13888888888", // 电话
  address: "深圳市南山区滨海大道 888 号" // 地址
};

## 3.方法
export default {
  data() {
    // 绑定数据
    return {
      menus: menus, // 菜单数据
      tableData: tableData // 列表数据
    };
  },
  methods: {
    // 新增一个数据
    addTableItem(item = {}) {
      // 添加到列表中，同时自增 id
      this.tableData.push({ ...item, id: this.tableData.length + 1 });
    },
    // 删除一个数据
    deleteTableItem(id) {
      // 查找到对应的索引，然后删除
      const index = this.tableData.findIndex(x => x.id === id);
      this.tableData.splice(index, 1);
    },
    // 移动一个数据
    moveTableItem(id, direction) {
      const dataLength = this.tableData.length;
      // 查找到对应的索引，然后取出，再插入
      const index = this.tableData.findIndex(x => x.id === id);
      switch (direction) {
        // 上移
        case "up":
          if (index > 0) {
            // 第一个不进行上移
            const item = this.tableData.splice(index, 1)[0];
            this.tableData.splice(index - 1, 0, item);
          }
          break;
        // 下移
        case "down":
          if (index < dataLength - 1) {
            // 最后一个不进行下移
            const item = this.tableData.splice(index, 1)[0];
            this.tableData.splice(index + 1, 0, item);
          }
          break;
      }
    }
  }
};

# 组件
### 组件内维护自身的数据和状态

### 组件内维护自身的事件
### 通过初始化事件（event、绑定的 scope 事件，传入数据），来初始化组件状态，激活组件

对外提供配置项，来控制展示以及具体功能
### 通过对外提供查询接口，可获取组件状态
像 Vue 中，便可以通过vm.$refs来获取子组件的实例。

## 组件的通信
当我们层层封装组件后，或许就会带来组件间通信的问题。
从最简单的父子组件、到同胞组件、到几乎毫无关系的组件的通信，我们可以有不同的解决方法。

1. 事件监听。
简单的，我们可以直接通过事件监听来通信，全局或是局部的监听和触发。
但是使用频繁之后，我们会发现不好维护。
为什么呢？因为你在追踪事件的触发和监听时，只能通过全局搜索对应的事件名称，这样数据流会有种到处乱窜、无法管理的感觉。

2. 对象数据
我们也可以通过共享同一个对象的方式来管理。
通过注入对象的引用，来在不同组件中获取相同的数据源。

3. 状态流管理。
这是通过流的方式管理状态，常见的状态管理工具 Vuex、Redux 等，都是这样的方式去管理。

即使是使用这样的流管理，也是通过对象数据的方式来管理。当然，加入了单向流动的方式，这样提高了维护性，因为你知道所有数据都从哪里流入、从哪里流出。

## 组件化程度







# 单页应用
