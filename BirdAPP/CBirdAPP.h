#pragma once
#include"../GameFrame/frame.h"
#include"../BackGround/CBackGround.h"
#include"../GameFrame/frame.h"
#include"../Ground/CGround.h"
#include"../Column/CColumnBox.h"
#include"../PlayerBird/CPlayerBird.h"
#include"../BeforeGame/BeforeGame.h"
#include"../AfterGame/CAfterGame.h"

class CBirdAPP : public CGameFrame
{
private:

public:
	CBirdAPP();
	~CBirdAPP();

	CBackGround m_BackGround;
	CGround m_Ground;
	CPlayerBird m_PlayerBird;
	CColumnBox m_ColumnBox;
	CBeforeGame m_BeforeGame;
	CAfterGame m_AfterGame;
	static int m_rand;
	int m_GameStatus;
	int m_score;

	void ReStartStop();
	void On_SetTimer();
	void ShowScore();
	virtual void On_Init();
	virtual void On_Paint();
	virtual void On_Close();
	virtual void On_WM_LBUTTONDOWN(POINT& po);
	virtual void On_WM_TIMER(WPARAM wParam, LPARAM lParam);


};