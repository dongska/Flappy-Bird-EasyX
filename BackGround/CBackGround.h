#pragma once
#include<easyx.h>

class CBackGround
{
public:
	IMAGE m_imgBack;
	int m_x;
	int m_y;

	CBackGround();
	~CBackGround();

	void InitBackGround();
	void ShowBackGround();
	// void MoveBackGround(int step);

};