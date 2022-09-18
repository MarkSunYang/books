# 搜索引擎组件介绍
# ElastaticSearch工作原理及常见的同类工具
# 日志工具 Logstash及常见的同类工具
# 可视化工具 Kibanan

ELAstaticsearch权威指南
https://www.elastic.co/guide/cn/elasticsearch/guide/current/running-elasticsearch.html

Elastaticsearch sense控制台：
http://localhost:5601/app/kibana#/dev_tools/console?_g=()


文档管理（CRUD）

# 创建索引
们对REST API创建一个PUT请求到一个由索引名称，类型名称和ID组成的URL。 也就是：http://localhost:9200/<index>/<type>/[<id>]。

索引和类型是必需的，而id部分是可选的。如果不指定ID，ElasticSearch会为我们生成一个ID
如果不指定id，应该使用HTTP的POST而不是PUT请求。

每种类型都有自己的ID空间。
不同类型具有不同的映射(“模式”，定义属性/字段应如何编制索引)。
搜索多种类型是可以的，并且也很常见，但很容易搜索一种或多种指定类型。