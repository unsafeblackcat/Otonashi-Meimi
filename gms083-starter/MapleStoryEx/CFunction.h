#pragma once
#include "community.h"

typedef void(__stdcall* pfun_role_hp_mp_monitor)(size_t hp, size_t hp_max, size_t mp, size_t mp_max);
typedef int(__stdcall* pfun_keyboard_callback)(int wparam, int lparam);
typedef void(__stdcall* pfun_command_input)(const char* psz);


/**
    一个接口拿能够拿到的，没必要搞那么多类
**/

class EXPORT CFunction
{
public:
    static CFunction* m_this;
    static CFunction* pins();

private:
    CFunction();
    virtual ~CFunction();

public:
    /**
        需要释放技能的

        lparam: 技能ID/按键ID
        
        bkey:true:   lparam为按键ID
             false:  lparam为技能ID
    **/
    void skills(int lparam, bool bkey = true);
     
    /**
        发送聊天消息
    **/
    void sendmsg(const char* psz);

public://人物信息相关
    const char* role_name();

    int role_get_hp();

    int role_get_hp_max();

    int role_get_mp();

    int role_get_mp_max();

    int role_get_exp();

    int role_get_exp_max();

public:  //注册回调
    //人物受伤HP MP EXP 变化时会触发此回调
    void reg_hp_mp_monitor(pfun_role_hp_mp_monitor cb);

    //当产生键盘按键时触发此回调
    void reg_keyboard_callback(pfun_keyboard_callback cb);

    //通过聊天窗口玩家输入命令时触发此回调
    void reg_commandinput_callback(pfun_command_input cb);
};