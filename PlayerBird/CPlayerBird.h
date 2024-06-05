#pragma once
#include<easyx.h>

class CPlayerBird
{
public:
	IMAGE m_imgPlayer[8];
	IMAGE m_imgPlayerFront[8];
	int m_x;
	int m_y;
	int m_speed;
	int m_mode;
	//bool m_direct;
	int m_a;

	CPlayerBird();
	~CPlayerBird();
	void InitPlayerBird();
	void MovePlayerBird();
	void ShowPlayerBird();
};