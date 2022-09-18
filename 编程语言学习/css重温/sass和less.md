1. 什么是Sass和Less
CSS 预处理器定义了一种新的语言，其基本思想是，用一种专门的编程语言，为 CSS 增加了一些编程的特性，将 CSS 作为目标生成文件，然后开发者就只要使用这种语言进行CSS的编码工作。

2. 为什么要用CSS与处理器
css的缺点
语法不够强大，无法写嵌套，导致模块化开发中需要写许多重复的选择器
没有变量和合理的样式复用机制，使得逻辑上的属性值必须以字面量的形式重复输出


3. Sass和Less的比较
1、Less环境较Sass简单
Cass的安装需要安装Ruby环境，Less基于JavaScript，是需要引入Less.js来处理代码输出css到浏览器，也可以在开发环节使用Less，然后编译成css文件，直接放在项目中，有less.app、SimpleLess、CodeKit.app这样的工具，也有在线编辑地址。
2、Less使用较Sass简单
LESS 并没有裁剪 CSS 原有的特性，而是在现有 CSS 语法的基础上，为 CSS 加入程序式语言的特性。只要你了解 CSS 基础就可以很容易上手。
3、从功能出发，Sass较Less略强大一些
①sass有变量和作用域。
- $variable，like php；
- #｛$variable｝like ruby；
- 变量有全局和局部之分，并且有优先级。
3、从功能出发，Sass较Less略强大一些
①sass有变量和作用域。
- $variable，like php；
- #｛$variable｝like ruby；
- 变量有全局和局部之分，并且有优先级。


②sass有函数的概念；
- @function和@return以及函数参数（还有不定参）可以让你像js开发那样封装你想要的逻辑。
-@mixin类似function但缺少像function的编程逻辑，更多的是提高css代码段的复用性和模块化，这个用的人也是最多的。
-ruby提供了非常丰富的内置原生api。

③进程控制：
-条件：@if @else；
-循环遍历：@for @each @while
-继承：@extend
-引用：@import

④数据结构：
-$list类型=数组；
-$map类型=object；
其余的也有string、number、function等类型

4、Less与Sass处理机制不一样
前者是通过客户端处理的，后者是通过服务端处理，相比较之下前者解析会比后者慢一点

Less和Sass在语法上有些共性，比如下面这些：

1、混入(Mixins)——class中的class；
2、参数混入——可以传递参数的class，就像函数一样；
3、嵌套规则——Class中嵌套class，从而减少重复的代码；
4、运算——CSS中用上数学；
5、颜色功能——可以编辑颜色；
6、名字空间(namespace)——分组样式，从而可以被调用；
7、作用域——局部修改样式；
8、JavaScript 赋值——在CSS中使用JavaScript表达式赋值。


4. 为什么选择使用Sass而不是Less



Sass 教程
https://www.sass.hk/guide/


1. 使用变量
sass让人们受益的一个重要特性就是它为css引入了变量，你可以把反复使用的css属性值 定义成变量，然后通过变量名来引用它们，而无需重复书写这一属性值。
1.1  变量声明
sass 使用 $ 符号来表示变量，
eg:$highlight-color: #F90;
和css不同，变量可以在css规则定义之外存在，当变量定义在css规则块内，那么改变辆只能在此规则块内使用，如果它们出现在任何形式的{...}块中（如@media或者@font-face块），情况也是如此：

$nav-color: #F90;
nav {
  $width: 100px;
  width: $width;
  color: $nav-color;
}

//编译后
nav {
  width: 100px;
  color: #F90;
}

1.2 变量的引用
凡是css属性的标准值（比如说1px或者bold）可存在的地方，变量就可以使用。css生成时，变量会被它们的值所替代。之后，如果你需要一个不同的值，只需要改变这个变量的值，则所有引用此变量的地方生成的值都会随之改变。
$hightlight-clolr:#f90;
.selected{
    border: 1px solid $highlight-color;
}

//编译后
.selected {
  border: 1px solid #F90;
}

1.3 变量名用中划线还是下划线分隔;
css中重复写选择器是非常恼人的。如果要写一大串指向页面中同一块的样式时，往往需要 一遍又一遍地写同一个ID：
#content article h1 { color: #333 }
#content article p { margin-bottom: 1.4em }
#content aside { background-color: #EEE }

像这种情况，sass可以让你只写一遍，且使样式可读性更高。在Sass中，你可以像俄罗斯套娃那样在规则块中嵌套规则块。sass在输出css时会帮你把这些嵌套规则处理好，避免你的重复书写。

#content{
    article{
        h1 { color: #333 }
        p { margin-bottom: 1.4em }
    }
    aside { background-color: #EEE }
}

然后 #content article 里边还有嵌套的规则，sass重复一遍以上的步骤，把新的选择器添加到内嵌的选择器前边
#content {
  background-color: #f5f5f5;
  aside { background-color: #eee }
}
一般情况下，sass在解开一个嵌套规则时就会把父选择器（#content）通过一个空格连接到子选择器的前边（article和aside）形成（#content article和#content aside）。


2.1 父选择器的标识符&
最常见的一种情况是当你为链接之类的元素写：hover这种伪类时，你并不希望以后代选择器的方式连接。比如说，下面这种情况sass就无法正常工作：
article a {
  color: blue;
  :hover { color: red }
}
这意味着color: red这条规则将会被应用到选择器article a :hover，article元素内链接的所有子元素在被hover时都会变成红色。这是不正确的！你想把这条规则应用到超链接自身，而后代选择器的方式无法帮你实现。

解决之道为使用一个特殊的sass选择器，即父选择器。在使用嵌套规则时，父选择器能对于嵌套规则如何解开提供更好的控制。它就是一个简单的&符号，且可以放在任何一个选择器可出现的地方，比如h1放在哪，它就可以放在哪。
article a {
  color: blue;
  &:hover { color: red }
}

2-2. 群组选择器的嵌套;




2. 嵌套css规则

3. 导入Sass文件c
css有一个特别不常用的特性，即@import规则，它允许在一个css文件中导入其他css文件。然而，后果是只有执行到@import时，浏览器才会去下载其他css文件，这导致页面加载起来特别慢。
sass也有一个@import规则，但不同的是，sass的@import规则在生成css文件时就把相关文件导入进来。这意味着所有相关的样式被归纳到了同一个css文件中，而无需发起额外的下载请求。

4.混合器
如果你的整个网站中有几处小小的样式类似（例如一致的颜色和字体），那么使用变量来统一处理这种情况是非常不错的选择。但是当你的样式变得越来越复杂，你需要大段大段的重用样式的代码，独立的变量就没办法应付这种情况了。你可以通过sass的混合器实现大段样式的重用。




sass 命令：

监听变化：node-sass  -w -r scss -o  static/css

node-sass 
@import _buttons.scss 和 button.scss 文件的时候 
@import 'buttons.scss' 和 @import '_buttons.scss' 效果一样