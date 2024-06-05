#pragma once
#include<easyx.h>
#include<map>
using namespace std;

/* -------------------------�����Ż���ʼ����Ϣ�б�ĺ�----------------------- */
#define INIT_MSGMAP(MSGID,MSGTYPE)\
		m_msgmap[MSGID].msg_type = MSGTYPE;\
		m_msgmap[MSGID].p_fun_##MSGTYPE = &CGameFrame::On_##MSGID;

/* ------------------------------�ص�����������------------------------------*/
LRESULT Wndproc(HWND unnamedParam1, UINT unnamedParam2, WPARAM unnamedParam3, LPARAM unnamedParam4);


/* ---------------------------------------------------------------------------------------------------- */
class CGameFrame
{
private:
	/* -----��Ԫ����������ֱ��ʹ�����е�˽�г�Ա----- */
	friend LRESULT Wndproc(HWND unnamedParam1, UINT unnamedParam2, WPARAM unnamedParam3, LPARAM unnamedParam4);
	// �����ûص�����ʹ��˽�е� map 

	bool m_end; // �ж��Ƿ��˳�

	typedef void(CGameFrame::* P_FUN_MOUSE)(POINT&);
	typedef void(CGameFrame::* P_FUN_WINDOW)(WPARAM, LPARAM);
	typedef void (CGameFrame::* P_FUN_KEY)(WPARAM);
	typedef void (CGameFrame::* P_FUN_CHAR)(WPARAM);

	/* ----�����Ϣӳ���� value ��Ӧ�����ͺͺ���---- */
	struct Fun_Type  // �ýṹ�����������Ϣӳ����value ��Ӧ�����ͺͺ���
	{
		// Message Category
		//#define EM_MOUSE	1
		//#define EM_KEY	2
		//#define EM_CHAR	4
		//#define EM_WINDOW	8
		int msg_type; // ��Ϣ����Ϊ int �� ��������ĺ�
		union
		{
			P_FUN_MOUSE p_fun_EM_MOUSE; // ָ�����Ա������ָ��
			P_FUN_WINDOW p_fun_EM_WINDOW;
			P_FUN_KEY p_fun_EM_KEY;
			P_FUN_CHAR p_fun_EM_CHAR;
		};
	};
	void InitMsgMap()
	{
			// ����������� ��Ϣ
			/*m_msgmap[WM_LBUTTONDOWN].msg_type = EM_MOUSE;
			m_msgmap[WM_LBUTTONDOWN].p_fun_mouse = &CGameFrame::On_WM_LBUTTONDOWN;*/
			/* ���ֱ��Ż��ɺ��� ��������*/
			INIT_MSGMAP(WM_LBUTTONDOWN, EM_MOUSE)

			// ��� window ���͵���Ϣ
			/*m_msgmap[WM_CLOSE].msg_type = EM_WINDOW;
			m_msgmap[WM_CLOSE].p_fun_window = &CGameFrame::On_WM_CLOSE;*/
			INIT_MSGMAP(WM_CLOSE, EM_WINDOW)

			// ��� key ���͵���Ϣ
			INIT_MSGMAP(WM_KEYDOWN, EM_KEY)

			// ��� char ���͵���Ϣ
			INIT_MSGMAP(WM_CHAR, EM_CHAR)

			//
			INIT_MSGMAP(WM_TIMER, EM_WINDOW)
	}

	/* ---------------------��Ϣӳ���------- --------------------*/
	map<UINT, Fun_Type> m_msgmap;  // ���ڽ���Ϣ���࣬keyֵΪmsgid, valueΪ��Ӧ�����ͺͺ���
				//	�� msgid ��Ϊ key , ���Զ�Ӧ��ͬһ������
				// ���е���Ϣ�ڶ����ʼ����ʱ�����

public:
	HWND hwnd; // ���ھ����������ܻ��õ�
	CGameFrame() :m_end(0)
	{

	}
	virtual ~CGameFrame()//�����������
	{

	}

	/* -------�ж��Ƿ����--------- */
	bool IfEndGame()
	{
		return m_end;
	}

	/* --------��Ϸ�ĳ�ʼ��-------- */
	void InitGame(const TCHAR* title,int width=400 ,int height=400 ,int x=50, int y=50)
	{
		/* ------����ĳ�ʼ��------- */

		hwnd = initgraph(width, height);//����������ڳ�ʼ����ͼ����  
		MoveWindow(hwnd, x, y, width, height, TRUE);//�ı䴰�ڵ�λ��
		SetWindowText(hwnd,title);
		setbkcolor(RGB(255, 255, 255));//��������������õ�ǰ�豸��ͼ����ɫ
		cleardevice();//�������ʹ�õ�ǰ����ɫ��ջ�ͼ�豸�������ñ���ɫ֮�󣬲�����ı����б���ɫ������ֻ�ı䱳��ɫ��ֵ��֮����ִ�л�ͼ��䣬���� outtextxy����ʹ�������õı���ɫֵ�������Ҫ�޸�ȫ������ɫ�����������ñ���ɫ��ִ�� cleardevice() ������

		/* ------�����Ϣ�б��е���Ϣ------ */
		InitMsgMap(); // ����ĳ�ʼ�����ں�����

		//TODO:����ĳ�ʼ��;
		On_Init();

		/* ----�趨���ڵ�����,�����趨���ڵĻص�����---- */
		SetWindowLong(hwnd, GWL_WNDPROC, (LONG)&Wndproc);
		// ���һ�������ǻ�������ĵ�ַ������������
	}

	/* --------��Ϸ���ػ洰��-------- */
	void PaintGame()
	{
		BeginBatchDraw();
		cleardevice();

		//todo:������Ϸ����ʾ
		On_Paint();

		EndBatchDraw();
	}

	/* --------��Ϸ������-------- */
	//void RunGame()
	//{
	//	ExMessage msg;//����ṹ�����ڱ��������Ϣ����������
	//	while (1)
	//	{
	//		getmessage(&msg); //��ȡ����������Ϣ  //����������ڻ�ȡһ����Ϣ�������ǰ��Ϣ������û�У���һֱ�ȴ���
	//		if (msg.message == WM_LBUTTONDOWN)//������������Ϣ
	//		{
	//			POINT po;
	//			po.x = msg.x;
	//			po.y = msg.y;
	//			On_WM_LBUTTONDOWN(po);
	//		}
	//	}
	//} 

	// �޷�����window��������getmessage��ȡ����Ϣ���಻�ࣩ,�ع鵽win32,�Ѿ��Ƶ�InitGame�еĻص�����

	/* --------��Ϸ�Ľ���-------- */
	void EndGame()
	{
		On_Close(); // ������Ϸ�Ľ���

		closegraph();
		m_end = true; // �˳���ʶ
	}


	/* ------------------������Ϸ����غ���----------------------- */
	 
	
	// ��Ϊ���麯����������һ��Ҫ��д��3��
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

/* ---��Ŀ�ľ������  ���滻�����Ķ���  �ھ��������cpp��ʹ��--- */
#define WND_PARAM(POS_X,POS_Y,WIDTH,HEIGHT,TITLE)\
	int WND_POS_X = POS_X;\
	int WND_POS_Y = POS_Y;\
	int WND_WIDTH = WIDTH;\
	int WND_HEIGHT = HEIGHT;\
	const TCHAR* WND_TITLE = TITLE; // ������Ŀ����

/* ----��̬new������ĺ����ĺ�---- */
#define DYNAMIC_CREATE(CLASS_OBJECT)\
CGameFrame* CreatObject(){ \
	return new CLASS_OBJECT; \
}