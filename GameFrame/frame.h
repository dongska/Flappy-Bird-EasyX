#pragma once
#include<easyx.h>
#include<map>
using namespace std;

/* -------------------------用于优化初始化消息列表的宏----------------------- */
#define INIT_MSGMAP(MSGID,MSGTYPE)\
		m_msgmap[MSGID].msg_type = MSGTYPE;\
		m_msgmap[MSGID].p_fun_##MSGTYPE = &CGameFrame::On_##MSGID;

/* ------------------------------回调函数的声明------------------------------*/
LRESULT Wndproc(HWND unnamedParam1, UINT unnamedParam2, WPARAM unnamedParam3, LPARAM unnamedParam4);


/* ---------------------------------------------------------------------------------------------------- */
class CGameFrame
{
private:
	/* -----友元函数，可以直接使用类中的私有成员----- */
	friend LRESULT Wndproc(HWND unnamedParam1, UINT unnamedParam2, WPARAM unnamedParam3, LPARAM unnamedParam4);
	// 可以让回调函数使用私有的 map 

	bool m_end; // 判断是否退出

	typedef void(CGameFrame::* P_FUN_MOUSE)(POINT&);
	typedef void(CGameFrame::* P_FUN_WINDOW)(WPARAM, LPARAM);
	typedef void (CGameFrame::* P_FUN_KEY)(WPARAM);
	typedef void (CGameFrame::* P_FUN_CHAR)(WPARAM);

	/* ----存放消息映射表的 value 对应的类型和函数---- */
	struct Fun_Type  // 该结构体用来存放消息映射表的value 对应的类型和函数
	{
		// Message Category
		//#define EM_MOUSE	1
		//#define EM_KEY	2
		//#define EM_CHAR	4
		//#define EM_WINDOW	8
		int msg_type; // 消息类型为 int 型 ，见上面的宏
		union
		{
			P_FUN_MOUSE p_fun_EM_MOUSE; // 指向类成员函数的指针
			P_FUN_WINDOW p_fun_EM_WINDOW;
			P_FUN_KEY p_fun_EM_KEY;
			P_FUN_CHAR p_fun_EM_CHAR;
		};
	};
	void InitMsgMap()
	{
			// 添加鼠标左键的 消息
			/*m_msgmap[WM_LBUTTONDOWN].msg_type = EM_MOUSE;
			m_msgmap[WM_LBUTTONDOWN].p_fun_mouse = &CGameFrame::On_WM_LBUTTONDOWN;*/
			/* 这又被优化成宏了 。。。。*/
			INIT_MSGMAP(WM_LBUTTONDOWN, EM_MOUSE)

			// 添加 window 类型的信息
			/*m_msgmap[WM_CLOSE].msg_type = EM_WINDOW;
			m_msgmap[WM_CLOSE].p_fun_window = &CGameFrame::On_WM_CLOSE;*/
			INIT_MSGMAP(WM_CLOSE, EM_WINDOW)

			// 添加 key 类型的信息
			INIT_MSGMAP(WM_KEYDOWN, EM_KEY)

			// 添加 char 类型的消息
			INIT_MSGMAP(WM_CHAR, EM_CHAR)

			//
			INIT_MSGMAP(WM_TIMER, EM_WINDOW)
	}

	/* ---------------------消息映射表------- --------------------*/
	map<UINT, Fun_Type> m_msgmap;  // 用于将消息分类，key值为msgid, value为对应的类型和函数
				//	将 msgid 作为 key , 可以对应到同一个类型
				// 其中的消息在对象初始化的时候添加

public:
	HWND hwnd; // 窗口句柄，子类可能会用到
	CGameFrame() :m_end(0)
	{

	}
	virtual ~CGameFrame()//虚析构解决了
	{

	}

	/* -------判断是否结束--------- */
	bool IfEndGame()
	{
		return m_end;
	}

	/* --------游戏的初始化-------- */
	void InitGame(const TCHAR* title,int width=400 ,int height=400 ,int x=50, int y=50)
	{
		/* ------界面的初始化------- */

		hwnd = initgraph(width, height);//这个函数用于初始化绘图窗口  
		MoveWindow(hwnd, x, y, width, height, TRUE);//改变窗口的位置
		SetWindowText(hwnd,title);
		setbkcolor(RGB(255, 255, 255));//这个函数用于设置当前设备绘图背景色
		cleardevice();//这个函数使用当前背景色清空绘图设备。在设置背景色之后，并不会改变现有背景色，而是只改变背景色的值，之后再执行绘图语句，例如 outtextxy，会使用新设置的背景色值。如果需要修改全部背景色，可以在设置背景色后执行 cleardevice() 函数。

		/* ------添加消息列表中的消息------ */
		InitMsgMap(); // 具体的初始化放在函数里

		//TODO:具体的初始化;
		On_Init();

		/* ----设定窗口的属性,重新设定窗口的回调函数---- */
		SetWindowLong(hwnd, GWL_WNDPROC, (LONG)&Wndproc);
		// 最后一个参数是会调函数的地址，声明在上面
	}

	/* --------游戏的重绘窗口-------- */
	void PaintGame()
	{
		BeginBatchDraw();
		cleardevice();

		//todo:具体游戏的显示
		On_Paint();

		EndBatchDraw();
	}

	/* --------游戏的运行-------- */
	//void RunGame()
	//{
	//	ExMessage msg;//这个结构体用于保存鼠标消息，定义如下
	//	while (1)
	//	{
	//		getmessage(&msg); //获取所有类别的信息  //这个函数用于获取一个消息。如果当前消息队列中没有，就一直等待。
	//		if (msg.message == WM_LBUTTONDOWN)//鼠标左键按下消息
	//		{
	//			POINT po;
	//			po.x = msg.x;
	//			po.y = msg.y;
	//			On_WM_LBUTTONDOWN(po);
	//		}
	//	}
	//} 

	// 无法满足window处理需求（getmessage获取的消息种类不多）,回归到win32,已经移到InitGame中的回调函数

	/* --------游戏的结束-------- */
	void EndGame()
	{
		On_Close(); // 具体游戏的结束

		closegraph();
		m_end = true; // 退出标识
	}


	/* ------------------具体游戏的相关函数----------------------- */
	 
	
	// 变为纯虚函数，子类中一定要重写这3个
	virtual void On_Init() = 0;
	virtual void On_Paint() = 0;
	virtual void On_Close() = 0;

	virtual void On_WM_LBUTTONDOWN(POINT& po)
	{
	}

	void On_WM_CLOSE(WPARAM wParam, LPARAM lParam)
	{
		EndGame();
	}

	virtual void On_WM_KEYDOWN(WPARAM wparam)
	{

	}

	virtual void On_WM_CHAR(WPARAM wparam)
	{

	}

	virtual void On_WM_TIMER(WPARAM wParam, LPARAM lParam)
	{

	}

};

/* ---项目的具体参数  宏替换变量的定义  在具体的子类cpp中使用--- */
#define WND_PARAM(POS_X,POS_Y,WIDTH,HEIGHT,TITLE)\
	int WND_POS_X = POS_X;\
	int WND_POS_Y = POS_Y;\
	int WND_WIDTH = WIDTH;\
	int WND_HEIGHT = HEIGHT;\
	const TCHAR* WND_TITLE = TITLE; // 更改项目属性

/* ----动态new派生类的函数的宏---- */
#define DYNAMIC_CREATE(CLASS_OBJECT)\
CGameFrame* CreatObject(){ \
	return new CLASS_OBJECT; \
}