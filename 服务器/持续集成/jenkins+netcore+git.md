场景
程序员 push代码到 git服务器
触发 jenkins 
jenkins 构建 发布到 指定目录（也可以使用docker）

1. centos 环境搭建
jdk  git jenkins 

2. jenkins 全局工具配置 的 git 和 jdk
可以使用 which java 和 which git 查看路径

3. 配置好了之后新增一个自由风格的软件项目，添加git地址即可

4. 实现自动构建
这里需要在git中配置jenkins的webhook
并且该地址是需要在外网的
https://blog.csdn.net/boling_cavalry/article/details/78943061

5. 将项目发布到指定目录
默认是发布到jenkins的 workspace下的
https://blog.csdn.net/russ44/article/details/51694074

6. 无法添加webhook
https://blog.csdn.net/xukangkang1hao/article/details/80756085

# Start all GitLab components
sudo gitlab-ctl start


# Stop all GitLab components
sudo gitlab-ctl stop


# Restart all GitLab components
sudo gitlab-ctl restart
