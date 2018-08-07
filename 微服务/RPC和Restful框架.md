接口的调用通常分为两个部分，系列化和通信协议
常见的序列化协议包括json、xml、hession、protobuf、thrift、text、bytes等；
通信比较流行的是http、soap、websockect，RPC通常基于TCP实现，

接口调用：
Rest：严格意义上说接口很规范，操作对象即为资源，对资源的四种操作（post、get、put、delete），并且参数都放在URL上,但是不严格的说Http+json、Http+xml，常见的http api都可以称为Rest接口。
Rpc:我们常说的远程方法调用，就是像调用本地方法一样调用远程方法，通信协议大多采用二进制方式

http vs 高性能二进制协议：
http相对更规范，更标准，更通用，无论哪种语言都支持http协议。如果你是对外开放API，例如开放平台，外部的编程语言多种多样，你无法拒绝对每种语言的支持，相应的，如果采用http，无疑在你实现SDK之前，支持了所有语言，所以，现在开源中间件，基本最先支持的几个协议都包含RESTful。
RPC协议性能要高的多，例如Protobuf、Thrift、Kyro等，（如果算上序列化）吞吐量大概能达到http的二倍。响应时间也更为出色。千万不要小看这点性能损耗，公认的，微服务做的比较好的，例如，netflix、阿里，曾经都传出过为了提升性能而合并服务。如果是交付型的项目，性能更为重要，因为你卖给客户往往靠的就是性能上微弱的优势。


Rpc在微服务中的利用
1、 RPC 框架是架构微服务化的首要基础组件 ，它能大大降低架构微服务化的成本，提高调用方与服务提供方的研发效率，屏蔽跨进程调用函数（服务）的各类复杂细节
2、 RPC 框架的 职责 是： 让调用方感觉就像调用本地函数一样调用远端函数、让服务提供方感觉就像实现一个本地函数一样来实现服务


Rest 调用及测试都很方便，Rpc就显得有点麻烦，但是Rpc的效率是毋庸置疑的，所以建议在多系统之间采用Rpc，对外提供服务，Rest是很适合的


RPC  Remote Promote Call 一种进程间通信方式，允许像调用本地服务一样调用远程服务。






a. RPC框架的主要目标就是让远程服务调用更简单、透明。
b. RPC框架负责屏蔽底层的传输方式（TCP或者UDP）、序列化方式（XML/JSON/二进制）和通信细节。


分布式框架可能具备的功能：
1.分布式（服务治理）
2.多序列化框架支持
3.多注册中心
4.管理中心
5.跨编程语言
因为RPC框架经常用在服务的大并发调用的环境中，性能的好坏决定服务的质量以及公司在硬件部署上的花费。


restful是基于http协议的，而rpc是可以使用多传输协议,
http协议的端口一般采用80端口，
而rpc支持多种协议，如果不是基于http那么可能就会被防火墙挡住



参考：
微软：https://docs.microsoft.com/en-us/windows/desktop/rpc/rpc-start-page
IBM: https://www.ibm.com/support/knowledgecenter/en/ssw_aix_72/com.ibm.aix.progcomc/ch8_rpc.htm
博客园：https://blog.csdn.net/king866/article/details/54174665