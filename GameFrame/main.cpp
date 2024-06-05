#include<easyx.h>
#include"frame.h"
#include<windowsx.h>
#include<iostream>
using namespace std;
CGameFrame* P_G = nullptr;

/* -----------�ص�����������------------ */
LRESULT Wndproc(HWND hwnd, UINT msgid, WPARAM wparam, LPARAM lparam)
{				/* ��һ�������Ǵ��ھ�����ڶ�������ϢID,����������ϢIDЯ���Ĳ��� */
	/* ------������Щ�ֱ��Ż��ˣ���Ϊ�����------ */
	if (P_G->m_msgmap.count(msgid)) // �����Ϣ�б����� msgid ��Ӧ����Ϣ����
	{
		switch (P_G->m_msgmap[msgid].msg_type)
		{
		case EM_MOUSE: // �����������͵� msgid 
		{
			POINT po = { 0 };// ����һ���ṹ�壬��long x ,long y
			po.x = GET_X_LPARAM(lparam); // windowsx.h  �����ĵ���WM_LBUTTONDOWN
			po.y = GET_Y_LPARAM(lparam); // windowsx.h
			(P_G->*(P_G->m_msgmap[msgid].p_fun_EM_MOUSE))(po); // �������Ա����ָ��
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
			// ��Ϣ������ˢ�´���
			P_G->On_Paint();
		}
	}
	return DefWindowProc(hwnd, msgid, wparam, lparam); // ���������windowsĬ�ϵĻص�����������������ѡ��Χ�ڵ�����
}


// ��Щ����Ϊ���������е���Ϣ
CGameFrame* CreatObject();
extern int WND_POS_X;
extern int WND_POS_Y;
extern int WND_WIDTH;
extern int WND_HEIGHT;
extern const TCHAR* WND_TITLE;


int main()
{
	P_G = CreatObject();// ���д��麯��Ϊ�����࣬�޷��������
	P_G->InitGame(WND_TITLE,WND_WIDTH, WND_HEIGHT, WND_POS_X, WND_POS_Y);
	//P_G->RunGame();
	P_G->PaintGame(); // ��ʼ��Ϸʱ�ػ�һ��

	while (!P_G->IfEndGame()) {

		Sleep(200);
	}

	delete P_G;
	P_G = nullptr;

	return 0;
}


