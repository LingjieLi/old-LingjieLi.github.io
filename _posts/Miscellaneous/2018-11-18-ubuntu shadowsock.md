---
layout: post
title:  "在ubuntu上使用shadowsock"
date:   2018-11-18 19:28:54
categories: Miscellaneous
tags: ubuntu shadowsock
excerpt: 记录/介绍在ubuntu上使用shadowsock
mathjax:	true
---

#### **安装shadowsocks**
`sudo apt install -y shadowsocks-libev`
#### **配置**
例如我的配置文件`myss.json`,保存在`/home/lydia/`下
```js
{
	"server":"xxxxxx",
	"server_port":443, 
	"local_address": "127.0.0.1", 
	"local_port":1080, 
	"password":"xxxxxx", 
	"timeout":60, 
	"method":"aes-256-cfb"
}
```
#### **启动**
```js
sudo ss-local -c ./myss.json
2018-11-18 19:39:57 INFO: initializing ciphers... aes-256-cfb
 2018-11-18 19:39:58 INFO: listening at 127.0.0.1:1080
 2018-11-18 19:39:58 INFO: running from root user
```
#### **修改浏览器配置**
**firefox**
扩展->搜索FoxyProxy->安装
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/foxyproxysetting.png)
**OK**
**chrome**
扩展->搜索SwitchySharp->安装
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/switchysharpsetting1.png)
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/switchysharpsetting2.png)

#### **参考**
[https://blog.csdn.net/CoolScript/article/details/82284687](https://blog.csdn.net/leewei4939/article/details/78816662)
[https://blog.csdn.net/leewei4939/article/details/78816662](https://blog.csdn.net/leewei4939/article/details/78816662)
