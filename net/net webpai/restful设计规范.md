1. 版本问题：
https://api.jiuyescm.com/v1/
https://api.jiuyescm.com/v1.2/

2. 资源路径
路径，API的具体地址。在REST中，每个地址都代表一个具体的资源（Resource）约定如下：
.路径仅表示资源的路径（位置），尽量不要有actions操作（一些特殊的actions操作除外）
 路径以 复数（名词） 进行命名资源，不管返回单个或者多个资源。
 使用 小写字母、数字以及下划线（“_”） 。（下划线是为了区分多个单词，如user_name）
 资源的路径从父到子依次如：
 /{resource}/{resource_id}/{sub_resource}/{sub_resource_id}/{sub_resource_property}
 使用 ? 来进行资源的过滤、搜索以及分页等
 使用版本号，且版本号在资源路径之前
 优先使用内容协商来区分表述格式，而不是使用后缀来区分表述格式
 应该放在一个专用的域名下，如：http：//api.jiuyescm.com
 使用SSL

3. 操作
用HTTP动词（方法）表示对资源的具体操作。常用的HTTP动词有：
GET（SELECT）：从服务器取出资源（一项或多项）
POST（CREATE）：在服务器新建一个资源
PUT（UPDATE）：在服务器更新资源（客户端提供改变后的完整资源）  
PATCH（UPDATE）：在服务器更新资源（客户端提供改变的属性） 
DELETE（DELETE）：从服务器删除资源
还有两个不常用的HTTP动词
HEAD：获取资源的元数据
OPTIONS：获取信息，关于资源的哪些属性是客户端可以改变的

4. 数据
数据是对资源的具体描述，分为请求数据和返回数据。约定如下：
查询，过滤条件使用query string，例如user?name=xxx
Content body 仅仅用来传输数据
通过Content-Type指定请求与返回的数据格式。其中请求数据还要指定Accept。（我们暂时只使用Json）
数据应该拿来就能用，不应该还要进行转换操作
使用字符串（YYYY-MM-dd hh:mm:ss）格式表达时间字段，例如: 2017-02-20 16:00:00
数据采用UTF-8编码
返回的数据应该尽量简单，响应状态应该包含在响应头中
使用 小写字母、数字以及下划线（“_”） 描述字段，不使用大写描述字段（这个由于使用了一些开源的jar所以这个不强求，比如说pageinfo我们无法修改属性名称）
建议资源中的唯一标识命名为id（这个不强求，有的唯一标识名称确实比较复杂）
属性和字符串值必须使用双引号””（这个json转换默认规则）
建议对每个字段设置默认值（数组型可设置为[],字符串型可设置为””，数值可设置为0，对象可设置为{}）,这一条是为了方便前端/客户端进行判断字段存不存在操作（这样json转换会自动转成相应的字符）
POST操作应该返回新建的资源；PUT/PATCH操作返回更新后的完整的资源；DELETE返回一个空文档；GET返回资源数组或当个资源
为了方便以后的扩展兼容，如果返回的是数组，强烈建议用一个包含如items属性的对象进行包裹，如：

5. 安全（Security）
为了避免请求泛滥，给API设置速度限制很重要。入速度设置之后，可以在HTTP返回头上对返回的信息进行说明，下面是几个必须的返回头（依照twitter的命名规则）
RESTful API是无状态的也就是说用户请求的鉴权和cookie以及session无关，每一次请求都应该包含鉴权证明。 可以使用http请求头Authorization设置授权码; 必须使用User-Agent设置客户端信息, 无User-Agent请求头的请求应该被拒绝访问。具体的授权可以采用OAuth2，或者自己定义并实现相关的授权验证机制（基于token）


引用
https://ningyu1.github.io/site/post/01-restful-design-specifications/