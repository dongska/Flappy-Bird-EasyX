#pragma once
#include<easyx.h>
#include"../GameConfig/GameConfig.h"
#include"../PlayerBird/CPlayerBird.h"

class CGround
{
public:
	IMAGE  m_imgGround;
	int m_x;
	int m_y;

	CGround();
	~CGround();

	void InitGround();
	void ShowGround();
	void MoveGround(int step);
	bool IfTouchGround(CPlayerBird* player);
};