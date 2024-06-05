#include"CBirdAPP.h"
#include"../GameConfig/GameConfig.h"
#include<time.h>
#include <string>

WND_PARAM(200, 100, WINDOW_WIDTH, WINDOW_HEIGHT, "FlappyBird")
DYNAMIC_CREATE(CBirdAPP)

int CBirdAPP::m_rand = 0;

CBirdAPP::CBirdAPP()
{
	m_GameStatus = 0; // 初始状态为：未开始游戏
	m_score = 0;
}
CBirdAPP::~CBirdAPP()
{

}


void CBirdAPP::On_SetTimer()
{
	if (m_GameStatus == 1) // 如果游戏开始了
	{
		// 设定定时更新随机数的定时器 ID 2
		SetTimer(hwnd, TIMER_RAND_NEW_TIMERID, TIMER_RAND_NEW_INTERVAL, nullptr);
		// 设定定时新建柱子的定时器 ID 3
		SetTimer(hwnd, TIMER_NEW_COLUMN_TIMERID, TIMER_NEW_COLUMN_INTERVAL, nullptr);
		// 设定定时展示&改变小鸟的定时器 ID 5
		SetTimer(hwnd, TIMER_BIRD_POSITION_TIMERID, TIMER_BIRD_POSITION_INTERVAL, nullptr);
	}
	else if (m_GameStatus == 0)
	{
		//设定定时移动背景的定时器  ID 1
		SetTimer(hwnd, TIMER_GROUND_MOVE_TIMERID, TIMER_GROUND_MOVE_INTERVAL, nullptr);
		// 设定定时修改小鸟IMG状态的定时器 ID 4
		SetTimer(hwnd, TIMER_BIRD_CHANGE_TIMERID, TIMER_BIRD_CHANGE_INTERVAL, nullptr);
		// 设定定时展示&改变小鸟的定时器 ID 5
		SetTimer(hwnd, TIMER_BIRD_SHOW_TIMERID, TIMER_BIRD_SHOW_INTERVAL, nullptr);
	}
}


void CBirdAPP::On_Init()
{
	if (m_GameStatus == 1) // 如果游戏开始了
	{
		
		srand((unsigned int)time(NULL));
		m_AfterGame.InitAfterGame();
		On_SetTimer();
	}
	else if (m_GameStatus == 0)
	{
		m_score = 0;
		m_ColumnBox.m_ColLst.clear();
		m_BackGround.InitBackGround();
		m_Ground.InitGround();
		m_PlayerBird.InitPlayerBird();
		m_BeforeGame.InitBeforeGame();
		On_SetTimer();
	}
}


void CBirdAPP::On_Paint()
{
	if (m_GameStatus == 1) // 如果游戏开始了
	{
		m_BackGround.ShowBackGround();
		m_ColumnBox.ShowAllColumn();
		m_Ground.ShowGround();
		ShowScore();
		m_PlayerBird.ShowPlayerBird();
	}
	else if (m_GameStatus == 0)
	{
		m_BackGround.ShowBackGround();
		m_Ground.ShowGround();
		m_BeforeGame.ShowBeforeGame();
		m_PlayerBird.ShowPlayerBird();
	}
	else if (m_GameStatus == 2)
	{
		m_BackGround.ShowBackGround();
		m_ColumnBox.ShowAllColumn();
		m_Ground.ShowGround();
		m_PlayerBird.ShowPlayerBird();
		m_AfterGame.ShowAfterGame();
		ShowScore();
	}
}


void CBirdAPP::On_Close()
{
	KillTimer(hwnd, 1);
	KillTimer(hwnd, 2);
	KillTimer(hwnd, 3);
	KillTimer(hwnd, 4);
	KillTimer(hwnd, 5);
	KillTimer(hwnd, 6);
	m_ColumnBox.m_ColLst.clear();
}


void CBirdAPP::On_WM_LBUTTONDOWN(POINT& po)
{
	//m_PlayerBird.m_direct = 1;
	if (m_GameStatus == 1) // 如果游戏已经开始
	{
		m_PlayerBird.m_speed = BIRD_STARTSPEED;
	}
	// 如果游戏没有开始，并且鼠标点在开始范围内
	else if (m_GameStatus == 0 && po.x >= BUTTON_POS_X_1 && po.x <= BUTTON_POS_X_2 && po.y >= BUTTON_POS_Y_1 && po.y <= BUTTON_POS_Y_2) // 如果游戏没有开始，并且鼠标点在开始范围内
	{
		m_GameStatus = 1; // 游戏开始
		On_Init();
	}
	// 如果游戏已经开始，并且鼠标点在重启范围内
	else if (m_GameStatus == 2 && po.x >= BUTTON2_POS_X_1 && po.x <= BUTTON2_POS_X_2 && po.y >= BUTTON2_POS_Y_1 && po.y <= BUTTON2_POS_Y_2) 
	{
		m_GameStatus = 0; // 重启
		On_Init();
	}
}


void CBirdAPP::On_WM_TIMER(WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case TIMER_GROUND_MOVE_TIMERID:
	{
		// m_BackGround.MoveBackGround(TIMER_BACKGROUND_MOVE_STEP);
		m_Ground.MoveGround(TIMER_GROUND_MOVE_STEP);
		m_ColumnBox.MoveAllColumn(TIMER_GROUND_MOVE_STEP);
		list<CColumn*>::iterator ite = m_ColumnBox.m_ColLst.begin();
		while (ite != m_ColumnBox.m_ColLst.end())
		{
			if (*ite)
			{
				if ((*ite)->IfTouchBird(&m_PlayerBird))
				{
					ReStartStop();
					m_GameStatus = 2;
				}
				if ((*ite)->m_x + IMG_COLUMN_WIDTH <= m_PlayerBird.m_x&&!(*ite)->m_IfPass)
				{
					(*ite)->m_IfPass = true;
					m_score++;
				}
			}
			ite++;
		}
	}
	break;
	case TIMER_RAND_NEW_TIMERID:
	{
		m_rand = rand();
	}
	break;
	case TIMER_NEW_COLUMN_TIMERID:
	{
		CColumn* newCol = new CColumn;
		newCol->InitColumn();
		m_ColumnBox.m_ColLst.push_back(newCol);
	}
	break;
	case TIMER_BIRD_CHANGE_TIMERID:
	{
		if (m_PlayerBird.m_mode + 1 <= 7)
		{
			m_PlayerBird.m_mode++;
		}
		else
		{
			m_PlayerBird.m_mode = 0;
		}
	}
	break;
	case TIMER_BIRD_SHOW_TIMERID:
	{

		m_PlayerBird.ShowPlayerBird();
	}
	break;
	case TIMER_BIRD_POSITION_TIMERID:
	{
		m_PlayerBird.MovePlayerBird();
		// 检测是否碰到地面
		if (m_Ground.IfTouchGround(&m_PlayerBird))
		{
			ReStartStop();
			m_GameStatus = 2;
		}
	}
	break;
	}
}



void CBirdAPP::ReStartStop()
{
	KillTimer(hwnd, 1);
	KillTimer(hwnd, 2);
	KillTimer(hwnd, 3);
	KillTimer(hwnd, 4);
	KillTimer(hwnd, 5);
	KillTimer(hwnd, 6);
}

void CBirdAPP::ShowScore()
{
	string strScore("");
	char sc[5] = { 0 };
	_itoa_s(m_score, sc, 10);
	strScore += sc;

	RECT rect = { 0,0,WINDOW_HEIGHT,WINDOW_WIDTH };
	::settextcolor(RGB(150, 100, 99));  //设置文字颜色
	settextstyle(60, 0, _T("黑体"));
	setbkmode(TRANSPARENT);
	::drawtext(strScore.c_str(), &rect, DT_CENTER | DT_SINGLELINE);  //显示字符串
}
