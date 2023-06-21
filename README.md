# 2023暑假控制组单片机方向线上测试

## 第一周测试题

### 1.git基本操作

#### 任务简介

> Git是一个开源的分布式版本控制系统，用于敏捷高效地处理任何或小或大的项目,可以帮助你进行自动的版本管理。控制组单片机端**之后的线上测试都是通过`gitee`发布**,在多人协作的情况下，使用`git`就会相当的方便，能够有效地协调多位开发者对不同地方的改动。

#### 任务要求

- 安装git，并且注册好`gitee`账户与`git`绑定，并且点击[**邀请链接**](https://gitee.com/buaarobot_admin/ControlGroupOnlineTest2023/invite_link?invite=a52b4b8233cdc27b4908272c9dc1ff6e99e49af97d700d63b7993663152babc580fd2afce6134a2c03eac9232b9ccfc5)加入本远程仓库
- 注意邀请链接的有效期为3天
- 在想要克隆本仓库的地方，右键菜单点击“**`Git Bash Here`**”，输入以下代码，即可实现将远程仓库克隆到本地的操作，注意**之后的任务会放置在任务文件夹中**

```c
>>> git clone https://gitee.com/buaarobot_admin/ControlGroupOnlineTest2023.git
```

- 创建一个markdown文件，命名格式为**{你的名字}.md**，如`李明.md`  撰写你对本周题目的难度的看法，创建一个简述自己对**git组成以及常见命令使用原理的理解**的markdown文件，命名格式为 **{你的名字ToMarkDown}.md** ，如`李明ToMarkDown.md`。  
  两个文件统一放到`ControlGroupSCMOnlineTest2023/第一周测试题/task1`下面  
- `git commit -m {改动的内容}` 在这里写清这次提交改动的内容:**{你的名字}提交task1**   
- 本任务结果提交方式为<font color='red'>**git提交**</font>   

##### 提示信息

- 可以使用`git push` 将本地所有未上传的提交推送到远程仓库
- 此时有可能会提示推送失败，这是因为远程仓库里面有本地未获取的提交
- 此时需要先`git pull`获取当前远程仓库的最新版本， 将远程仓库的最新版本和本地最新版本合并(`merge`)后，才能够推送 
- 第一次进行提交操作时需要登记提交者信息，提交时`git`会有相关的操作说明
- 更多详细的`git`用法请查询参考资料或借助网络搜索  

##### 注意

<font color="red" size=3>**不是**所有任务都需要利用git进行提交，第一周以及以后的其它任务提交方式**请以对应的任务说明为准**</font>

#### 参考资料

- [<u>git入门教程</u>](https://www.cnblogs.com/imyalost/p/8762522.html)
- [菜鸟教程yyds](https://www.runoob.com/git/git-tutorial.html)
- 一个可以打开md文件的软件：[Typora](https://bhpan.buaa.edu.cn:443/link/5D15F20C387C3E8D482B1A2AF01EC387)



