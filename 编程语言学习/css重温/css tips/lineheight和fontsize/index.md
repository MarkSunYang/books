font: font-size/line-heingt;
font-size，line-heingt是可以单独出现的，但是如果在设置 font的时候可能出现 font: font-size/line/height;

1. line-height 属性设置行间的距离（行高）。
该属性会影响行框的布局,在应用到一个块级元素时，它定义了该元素中基线之间的最小距离而不是最大距离。
一个重要的特性就是line-height可以被继承。

对于块级元素，line-height指定了元素内部line-boxes的最小高度
对于非替代行内元素，line-height用于计算line-box的高度
对于替代行内元素，例如input、button，line-height没有影响

normal： 取决于用户代理，取决于元素的font-family
line-height: normal;

number：所用的值是无单位数值乘以元素的 font-size。计算出来的值与使用数值指定的一样。大多数情况下，使用这种方法设置line-height是首选方法，在继承情况下不会有异常的值。
line-height: 3.5;

length
指定 用于计算 line box 的高度。
line-height: 3em;

percentage
与元素自身的字体大小有关。计算出的值是给定的百分比值乘以元素计算出的字体大小。
line-height: 34%;

line-height:1.5、line-height:150%、line-height:1.5em的区别
em的效果跟%是一样的

line-height:1.5
所有可继承元素根据font-size重新计算行高。
<div id="father">
    <div id="son">
        我的font-size为60px
    </div>
</div>
#father{
    font-size:12px;
    line-height:1.5;
    width:300px;
}
#son{
    font-size:60px;
    color:white;
}
此时，#son元素的line-height为60*1.5=75px；


line-height:150%/line-height:1.5em
line-height为12px*150=18px; 因为son的文本框高度是60px;所以son元素的半行距（18-60）、2
=-12px所以#son元素内的两行字重合在一起了。


height：表示行高
line-height：表示每行文字所占的高度   



2. font-size 属性可设置字体的尺寸。
浏览器的默认高度?一般为16px.
为什么用62.5%作为body的默认样式? 16px62.5%=10px.
这样如果一个元素为1rem那么，根据html的根元素的font-size=10px;可以推算 1rem=10px；


em是相对于上级元素的font-size
rem是相对根元素的font-size



3. line-height和font-size 有联系吗，什么联系？

4. line-height的继承特性有什么特殊性？

如果一个标签没有定义height属性（包括百分比高度），那么最终的表现的高度一定是line-height起作用


