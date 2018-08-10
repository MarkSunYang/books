centos docker 
环境就绪
开始：
1. docker pull microsoft/dotnet 
需要使用镜像加速，这里我使用了阿里云的 自行百度

2. 配置镜像加速器
针对Docker客户端版本大于 1.10.0 的用户
https://cr.console.aliyun.com/cn-qingdao/mirrors

您可以通过修改daemon配置文件/etc/docker/daemon.json来使用加速器
sudo mkdir -p /etc/docker
sudo tee c/daemon.json <<-'EOF'
{
  "registry-mirrors": ["https://6pbsl824.mirror.aliyuncs.com"]
}
EOF
sudo systemctl daemon-reload
sudo systemctl restart docker

随便吐槽下，用了加速速度就是不一样，具体什么原因，呵呵

3. 这个时候运行docker images 可以看到我们的 镜像，卧槽dotnet 居然有1.7个G
如何使用这个.net 镜像？
使用docker run -it microsoft/dotnet  启动镜像
linux的主机并没有安装.net core，
我们从镜像仓库中拉去了dotnet的镜像，1.7个G，包含了创建，构建，运行.net core的依赖环境
我们在linux中查找 创建的web项目，也无法找到，这说明我们刚才创建的项目是在容器内的


4. 在宿主机器上创建.net core 项目
 回到根目录使用.net core 命令创建项目

 注意开启端口的时候 yum install iptables-services 
iptables代替防火墙

通过源码挂载的方式将代码共享到容器中
// 命令中的`\`结合`Enter`键构成换行符，允许我们换行输入一个长命令。
$ docker run -it \
-v $HOME/demo/HelloDocker.Web:/app \
microsoft/dotnet:latest

上面的命令就是把 
$HOME/demo/HelloDocker.Web文件夹下的文件挂载到容器的\app目录下。
关于 linux中的挂载，需要了解linux

5. 使用DockerFile
Dockerfile用来定义你将要在容器中执行的系列操作。我们来创建第一个Dockerfile：

//确保进入我们创建的MVC项目目录中去
$ cd $Home/Demo/HelloDocker.Web


6. 上传自定义镜像到dockerhub
z这里会遇到镜像上传被拒绝的情况，具体百度 





docker ps -a 
docker rm -f 

参考：
http://www.cnblogs.com/sheng-jie/p/8107877.html

docker nginx
https://www.cnblogs.com/wwzyy/p/8337965.html

docker netcore
https://www.cnblogs.com/baiyunchen/p/5812110.html