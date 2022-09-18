# 利用webbrower的mapit.py
import webbrowser
webbrowser.open('http://www.baidu.com')

可以用来打开浏览器

#用request模块从web下载文件
requests 模块很容易从web下载文件，不必担心一些复杂的问题，
比如网络连接问题和数据压缩，requests不是python自带的，可以通过pip install requests

requests.get() 函数接受一个要下载的url字符串
