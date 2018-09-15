<<<<<<< HEAD
对象的种类
Tag , 
NavigableString ,
 BeautifulSoup ,
  Comment
=======
1. 安装
 pip install beautifulsoup4

2. 安装解析器

3. 对象的种类
Beautiful Soup将复杂HTML文档转换成一个复杂的树形结构,每个节点都是Python对象,所有对象可以归纳为4种: Tag , NavigableString , BeautifulSoup , Comment .

#Tag 对象与XML或HTML原生文档中的tag相同:
tag是一个html标签

tag有很多方法和属性，
每个tag都要自己的名字，通过tag来获取
一个tag可能有很多个属性. tag <b class="boldest"> 有一个 “class” 的属性,值为 “boldest” . tag的属性的操作方法与字典相同:
tag['class']

4. 可以遍历的字符串
字符串常被包含在tag内.Beautiful Soup用 NavigableString 类来包装tag中的字符串:





# 遍历文档树
    
>>>>>>> 9e24e3452d8e4456674bdfd8640abe5e4a348b0e
