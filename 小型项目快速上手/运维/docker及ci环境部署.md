
docker 安装

sudo chmod 666 docker.sock

13. docker ngxin 的部署
需要新建一个 config文件
先启动一个              nginx  docker run --name nginx -p 8080:80 -d nginx，然后把配置文件拷出来
进入nginx 容器          docker exec -it nginx bash
然后把配置文件拷出来     docker cp nginx:/etc/nginx/nginx.conf /data/docker/nginx/   docker cp nginx:/etc/nginx/conf.d/default.conf /data/docker/nginx/conf.d/
给nginx mod 777
然后再删除nginx重新启动
:不开443端口
docker run --privileged --cap-add SYS_ADMIN --name nginx-dev -d -p 8080:80 --restart=always\
           -v /etc/localtime:/etc/localtime:ro -e TZ="Asia/Shanghai"\
           -v /data/docker/nginx/nginx.conf:/etc/nginx/nginx.conf\
           -v /data/docker/nginx/logs:/var/log/nginx nginx

14. docker jenkins 的部署
无
docker run  --privileged --cap-add SYS_ADMIN --name jenkins -p 8001:8080 --restart=always \
    -v /etc/localtime:/etc/localtime:ro -e TZ="Asia/Shanghai"\
    -v /var/run/docker.sock:/var/run/docker.sock -v $(which docker):/usr/bin/docker \
    -v /data/docker/jenkins:/var/jenkins_home \
    -d auto-jenkins

15.  gitlab 的部署
新建 gitlab-logs、gitlab-data、gitlab-config文件

端口要注意下，443可以不要，但是git拉代码走的是22端口，
docker run -it -p 8042:443 -p 8002:80 -p 8022:22  --name gitlab --restart=always -v /data/docker/gitlab/gitlab-config/:/etc/gitlab:z -v /data/docker/gitlab/gitlab-logs/:/var/log/gitlab:z -v /data/docker/gitlab/gitlab-data/:/var/opt/gitlab:z -d gitlab/gitlab-ce

默认的情况下第一次登陆可以设置用户名密码，但是可能需要设置（登陆容器）具体操作：
进入容器 docker exec -it gitlab bash
打开目录 cd /opt/gitlab/bin
执行控制台 gitlab-rails console
执行数据库代码，密码最少长度8位
1.u=User.where(id:1).first
2.u.password='12345678'
3.u.password_confirmation='12345678' 
4.u.save!

16. docker mysql

# 配置http协议所使用的访问地址,不加端口号默认为80
external_url 'http://120.48.254.79:8002/' （http拉代码是走8002端口）
# 配置ssh协议所使用的访问地址和端口
gitlab_rails['gitlab_ssh_host'] = 'http://120.48.254.79'
gitlab_rails['gitlab_shell_ssh_port'] = 8022 # 此端口是run时22端口映射的222端口  （ssh拉取代码走的是22端口）
:wq #保存配置文件并退出

# 邮箱的配置
# 是否启用
gitlab_rails['smtp_enable'] = true
# SMTP服务的地址
gitlab_rails['smtp_address'] = "smtp.qq.com"
# 端口
gitlab_rails['smtp_port'] = 465
# 你的QQ邮箱（发送账号）
gitlab_rails['smtp_user_name'] = "872456877@qq.com"
# 授权码
gitlab_rails['smtp_password'] = "teaueujycvpzbbbf"
# 域名
gitlab_rails['smtp_domain'] = "smtp.qq.com"
# 登录验证
gitlab_rails['smtp_authentication'] = "login"

# 使用了465端口，就需要配置下面三项
gitlab_rails['smtp_enable_starttls_auto'] = true
gitlab_rails['smtp_tls'] = true
gitlab_rails['smtp_openssl_verify_mode'] = 'none'

# 你的QQ邮箱（发送账号）
gitlab_rails['gitlab_email_from'] = '872456877@qq.com'

16. redis
docker run -d --restart=always --name redis -p 6379:6379 redis


17. nuget 的部署
docker run -d -p 8003:80 -e NUGET_API_KEY=oy2f6q7vwjwkuujt5e6axzivsgo3leiuzeiu2ncw4nluby -v /data/nuget/database:/var/www/db -v /data/nuget/packages:/var/www/packagefiles --name nuget-server sunside/simple-nuget-server:latest


docker run -d --name nuget-server00 --restart=always -p 8003:80 --env-file baget.env -v "/data/docker/nuget-data:/var/baget" loicsharma/baget:latest



docker的基本命令：
1. 
docker images 
命令：
docker run --name nginx -p 8080:80 -v /data/docker/nginx/nginx.conf:/etc/nginx/nginx.conf -v /data/docker/nginx/log:/var/log/nginx -v /data/docker/nginx/conf.d/default.conf:/etc/nginx/conf.d/default.conf -d nginx

运行的时候需要把配置文件挂载出来，ngxin比较特殊，需要自己拷贝出来
具体拷贝方式： https://blog.csdn.net/dongdong9223/article/details/71425077



TODO
nuget的使用

docker logs  查看对应的容器名称



1. docker的安装
https://blog.csdn.net/qq_39992399/article/details/115466043
2.用户名密码的修改
https://blog.csdn.net/qq_41922608/article/details/114405905


自己机器
8080 nginx
8001 jenkins
8002 gitlab
8003 nuget
8006 禅道



# 禅道的搭建
https://www.zentao.net/book/zentaopmshelp/405.html

sudo docker run --name zentao -p 8006:80 --ip 120.48.254.79 -v /data/docker/zentao/zentaopms:/www/zentaopms -v /data/docker/zentao/mysqldata:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=123456 -d easysoft/zentao:12.3.3



# mongodb

docker run --name mongodb -p 27017:27017 -v /data/docker/mongodb:/data/db -v /data/docker/mongodb:/data/backup -d mongo 
添加 docker exec -it mongodb mongo admin

db.createUser({user:'root',roles:[{'role':'root','db':'test'}]})

添加用户
https://www.cnblogs.com/stardust233/p/12193850.html



# 限制 docker 日志增长
https://docs.docker.com/config/containers/logging/json-file/