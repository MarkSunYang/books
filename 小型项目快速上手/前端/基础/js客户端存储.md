

### Web Storage
1. 提供在 cookie 之外的存储会话数据的途径
2. 提供跨会话持久化存储大量数据的机制。

Storage 类型用于保存名/值对数据，直至存储空间上限（由浏览器决定）。Storage 的实例与其他
对象一样，但增加了以下方法

clear()：删除所有值；
getItem(name)：取得给定 name 的值
 key(index)：取得给定数值位置的名称。
removeItem(name)：删除给定 name 的名/值对。
 setItem(name, value)：设置给定 name 的值。
Storage 类型只能存储字符串。非字符串数据在存储之前会自动转换为字符串。
注意，这种转换不能在获取数据时撤销。


#### sessionStorage


#### localStorage 对象
两种存储方法的区别在于，存储在 localStorage 中的数据会保留到通过 JavaScript 删除或者用户
清除浏览器缓存。localStorage 数据不受页面刷新影响，也不会因关闭窗口、标签页或重新启动浏览
器而丢失。
