#pragma once

typedef int (__fastcall* pfun_skills)(void* pthis, int dummy, int id, int param1, int param2);

class CFunctionEx
{
public:
    CFunctionEx();
    virtual ~CFunctionEx();

public:
    int skills(int lparam, bool bskill = true);

    void send_msg(const char* msg);

    void block_keyboard_input(bool status);

private:
    pfun_skills m_skills;
};

