#include<easyx.h>
#include"frame.h"
#include<windowsx.h>
#include<iostream>
using namespace std;
CGameFrame* P_G = nullptr;

/* -----------回调函数的声明------------ */
LRESULT Wndproc(HWND hwnd, UINT msgid, WPARAM wparam, LPARAM lparam)
{				/* 第一个参数是窗口句柄，第二个是消息ID,后两个是消息ID携带的参数 */
	/* ------上面这些又被优化了，改为下面的------ */
	if (P_G->m_msgmap.count(msgid)) // 如果消息列表中有 msgid 对应的消息类型
	{
		switch (P_G->m_msgmap[msgid].msg_type)
		{
		case EM_MOUSE: // 如果是鼠标类型的 msgid 
		{
			POINT po = { 0 };// 这是一个结构体，有long x ,long y
			po.x = GET_X_LPARAM(lparam); // windowsx.h  帮助文档看WM_LBUTTONDOWN
			po.y = GET_Y_LPARAM(lparam); // windowsx.h
			(P_G->*(P_G->m_msgmap[msgid].p_fun_EM_MOUSE))(po); // 调用类成员函数指针
		}
		break;
		case EM_WINDOW:
		{
			(P_G->*(P_G->m_msgmap[msgid].p_fun_EM_WINDOW))(wparam, lparam);
		}
		break;
		case EM_KEY:
		{
			(P_G->*(P_G->m_msgmap[msgid].p_fun_EM_KEY))(wparam);
		}
		break;
		case EM_CHAR:
		{
			(P_G->*(P_G->m_msgmap[msgid].p_fun_EM_CHAR))(wparam);
		}
		break;
		}

		if (!P_G->IfEndGame())
		{
			// 消息处理完刷新窗口
			P_G->On_Paint();
		}
	}
	return DefWindowProc(hwnd, msgid, wparam, lparam); // 这个函数是windows默认的回调函数，用来处理不在选择范围内的输入
}


// 这些变量为具体子类中的信息
CGameFrame* CreatObject();
extern int WND_POS_X;
extern int WND_POS_Y;
extern int WND_WIDTH;
extern int WND_HEIGHT;
extern const TCHAR* WND_TITLE;


int main()
{
	P_G = CreatObject();// 具有纯虚函数为抽象类，无法定义对象
	P_G->InitGame(WND_TITLE,WND_WIDTH, WND_HEIGHT, WND_POS_X, WND_POS_Y);
	//P_G->RunGame();
	P_G->PaintGame(); // 开始游戏时重绘一次

	while (!P_G->IfEndGame()) {

		Sleep(200);
	}

	delete P_G;
	P_G = nullptr;

	return 0;
}


