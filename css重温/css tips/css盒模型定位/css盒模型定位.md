视觉格式化模型
https://segmentfault.com/a/1190000005116275

页面(文档树)可以想象成是由一个个的Box组合而成的，而视觉格式化模型(Visual formatting model)是一套规则，将这些框布局成访问者看到的样子。

哪些因素控制了这些布局
1).盒的尺寸和类型
2).定位体系 position scheme(常规流，浮动和绝对定位)
3).文档树中元素之间的关系
4).外部信息，比如视窗大小，图片的固有尺寸

下面说说这些影响布局的因素

1.1 元素框
css假设每个元素都会生成一个或者多个Box，称为元素框，元素框中心有内容区，内容区外周围包括了padding，border，margin，盒模型就是用来处理这些内容的一个模型

1.2 包含块
每个元素都是相对于包含块摆放，包含块就是一个元素的“布局上下文”,
<body>
    <div><p>p的包含块是div</p><div>
    //div的包含块是body
</body>

1.3 替换/非替换元素
替换元素就是浏览器根据元素的标签和属性，来决定元素的具体显示内容。
通过 CSS content 属性来插入的对象 被称作 匿名可替换元素
如果元素的内容包含在文档之中，则为非替换元素
非替换元素的所有规则同样适用于替换元素，只有一个例外，width如果是auto,元素的高宽就是内容的固有高宽，比如img就是图片的原始大

HTML中的<img>、<input>、<textarea>、<select>、<object>都是替换元素。这些元素往往没有实际的内容，即是一个空元素,例如：

Css Box(盒模型/框模型)
CSS 框模型 (Box Model) 规定了元素框处理元素内容、内边距、边框 和 外边距 的方式，我们常见的盒模型大致有两种，一种是块级的盒子（Block Box），一种是行级的盒子（Line Box）

Block Box：
display: block list-item ,table会让一个元素成为块级元素

line box
每一行称为一条Line Box，它又是由这一行的许多inline-box组成
display：inline会让一个元素称为行内元素

inline-block
将对象呈现为inline对象，但是对象的内容作为block对象呈现。之后的内联对象会被排列在同一行内。比如我们可以给一个link（a元素）inline-block属性值，使其既具有block的宽度高度特性又具有inline的同行特性。


Formatting context
每个元素，或者说每个box会根据设置的display的值，去选择渲染它的方式，不同的display有不同层级，
block-level box（块级）inline-level box(行级)，run-in box(插入型框 css3)
不同的层级会参与不同的环境（formatting context）去渲染
上文提到的环境就是Formatting context，他是一个有渲染规则的渲染区域，不同的层级有不同的渲染规则

什么是BFC？
块级格式化上下文，规定了 块级盒子 的渲染方式布局方式，他在计算盒子高度，margin值计算等地方有区别于其他环境。

BFC有什么特点
1.内部盒子在垂直方向排列 
2.同一个BFC中的元素可能会发生margin collapse （margin重叠）；
3.BFC就是页面上的一个隔离的独立容器，里外互相不影响 
4.计算BFC的高度时，考虑BFC所包含的所有子元素，连浮动元素也参与计算；
5.当元素不是BFC的子元素的时候，浮动元素高度不参与BFC计算（既是常见的盒子塌陷问题）

什么元素会触发产生一个新的BFC
根元素 <html>
float属性不为none
position为absolute或fixed
display为inline-block, table-cell, table-caption, flex, inline-flex
overflow不为visible

我们用BFC来
清除浮动
阻止边距重叠
用于布局，两栏自适应高度之类的



CSS定位方案
普通流
元素按照其在 HTML 中的位置顺序决定排布的过程。并且这种过程遵循标准的描述
只要不是float和绝对定位方式布局的，都在普通流里面。

浮动
浮动框不在文档的普通流中，浮动的流会漂浮在普通的流上面。
浮动的框可以向左或向右移动，直到它的外边缘碰到包含框或另一个浮动框的边框为止。

定位
相对定位在普通流之中，是相对于它在普通流中的位置中进行移动，元素占据原来位置
绝对定位脱离普通流，不占据空间相对于距离它最近的那个已定位的祖先(相对/绝对)元素决定的。
固定定位，相对于浏览器窗口定位，脱离普通流，不占据空间



https://segmentfault.com/a/1190000005155084