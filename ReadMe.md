# 项目介绍
该项目为gms083客户端项目，配套服务端HeavenMS-Nap的2.5.x分支  
服务端项目地址：https://gitee.com/sleepnap/heaven-ms-nap/tree/2.5.x  
客户端项目地址：https://gitee.com/sleepnap/gms083-src  
客户端原文件下载地址：(原版083cn)https://pan.baidu.com/s/17z3pBKu3jz5AOJmB9eFzqQ 提取码：f5zc

# 目录介绍
- gms083-starter 客户端启动器相关
- gms083-libs 客户端动态库相关
- ~~gms083-client 客户端原文件~~

# gms083-starter介绍
~~~cpp
D:.
├───community 	    外部三方C++开源库
└───config		    VS配置文件
├───MapleStory      新的启动器
└───MapleStoryEx    用于后续注入和修改功能的注入插件
└───Skills          功能插件，自动定时释放技能
~~~

## VS开发环境介绍
1. 使用VS2022初始提交，避免混乱，编译工具请统一安装 VS2017 - XP(141_XP)编译，调试，和分发。
2. 为了避免开发环境混乱请关闭下面选项


## MapleStory
新的启动器程序，功能为拉起原始MapleStory.exe启动游戏后将MapleStoryEx.dll注入到MapleStory游戏本体。

需要将083cn冒险岛游戏本地中的MapleStory.exe重命名为MapleStory_.exe后再将编译后的MapleStory.exe和MapleStoryEx.dll放入083cn文件夹中。

## MapleStoryEx
注入插件，由上面的工程把当前插件注入到MapleStory.exe中。插件目的，调试，框架，支持插件，

> 以支持下列功能：   
> 简单的插件管理器    
> 人物部分属性获取    
> 键盘按键回调        
> 监控玩家HP/MP/EXP     
> 释放技能接口   
> 自动喊话聊天接口   
> 命令与回显接口

## Skills插件
自动释放技能插件。目的是为了减少玩家操作。专注野外打怪，不必在意是否需要手动释放职业增益技能.

Skills插件依赖MapleStoryEx.dll。使用请参考MapleStoryEx::CPlugins.h文件

### 使用方法:
聊天消息窗口输入命令:
~~~cpp
/**
!skills.auto.start:            开启定时自动技能释放
!skills.auto.stop:             停止定时自动技能释放
!skills.auto:                  配置自动技能释放
!skills.auto.show:             显示自动技能配置
!skills.auto.delete:[index]:   删除指定索引配置
!skills.auto:按键,秒数,[可选项的消息]
    按键: 需要自动释放技能的键盘按键.
    秒数: 需要多少秒自动触发一次技能释放.
    可选项的消息: 当自动触发技能时可以选择向世界发送一条消息.
例子: !skills.auto:a,120,魔法盾
设置自动释放技能，每120秒触发一次按键a上面的技能，并且向世界发送消息 \"魔法盾\"
备注: 请使用英文输入法状态下的 逗号, 冒号
特殊按键以对应的数字ID替换字符
特殊按键: F1~F12 使用数字ID(112~123)
特殊按键: ~      使用数字ID 192
特殊按键: ATL    使用数字ID 18
特殊按键: CTRL   使用数字ID 17
特殊按键: Ins    使用数字ID 45
特殊按键: Hm     使用数字ID 36
特殊按键: Pup    使用数字ID 33
特殊按键: Del    使用数字ID 46
特殊按键: End    使用数字ID 35
特殊按键: Pdn    使用数字ID 34
**/
~~~


# gms083-libs介绍
### VS开发环境介绍
1. 使用VS2019社区版进行编译：
- 平台工具集：Visual Studio 2019 (v142)

- C++语言标准：默认(ISO C++14 标准)

- C语言标准：默认(旧 MSVC)
SDK：10.0，當前環境還安装了10.0.19041.0。
2. 为了方便维护和提取所生成的dll文件，请将专案的文件输出路径统一修改为如下路径：
- 右键->配置属性->常规->输出目录：    ..\..\Build\pdb\$(platform)\     (这里生成的文件为编译产生可删可不删，统一放在此处，也无需上传)
- 右键->配置属性->链接器->常规->输出文件：  ..\..\Client\$(TargetName)$(TargetExt)   (这是生成DLL的路径)
- 右键->配置属性->链接器->高级->导入库：  ..\..\Build\lib\$(platform)\$(Configuration)\$(TargetName).lib   (这里生成相关lib依赖，由于此项目采用dll注入,因此也可以不需要，可删可不删)
3. 本专案生成的dll用于在原版083cn中进行，其余端未尝试。

### 编译以及调试方式
1. 指定Release x86进行编译
2. 如果想调试，请将GMS083客户端放入Client文件夹内，然后配置如下信息：
- 右键->配置属性->调试->命令： 选择exe文件路径
- 右键->配置属性->调试->工作目录： 选择build路径
- 右键->配置属性->C/C++->优化->优化： 将最大优化(优选速度) (/O2)改为禁用
- 配置完毕后即可编译调试生成的ijl15.dll。

### ijl15目前开发出的功能
1. 自定义客户端IP。
2. 自定义右下角拾取，获得道具，经验等的消息提示数量。
3. 破功。
4. 指定移速上限。
5. 是否多开。
6. 加载客户端的方式是否为img。
7. 现金商店是否移动到中心位置。
8. 完美修复长键盘(感谢大仙,Datas,MagicLing等大佬们的支援~！)

### ijl15修复的功能
1. 角色框&升级特效微调。
2. 键盘位置移动。
3. 顶部滚动消息横向全屏。
4. BOSS血条显示在中心。(不会紧贴边缘了)
5. 修复全图特效消息显示在屏幕中间。
6. 获取道具，经验等的消息位置显示在紧贴右下角的菜单栏上方。
7. 相机视角微调。

### 待修正的BUG
1. 原版083cn启动游戏的几率闪退。(有点高，截至目前还未有方案)

### 如何使用
将原本的ijl15.dll改名为2ijl15.dll,将生成的ijl15.dll和config.ini一起放入GMS083客户端中，启动即可。