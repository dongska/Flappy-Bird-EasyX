#pragma once
#include<easyx.h>
#include"../PlayerBird/CPlayerBird.h"

class CColumn
{
public:
	IMAGE m_imgColumn;
	IMAGE m_imgColumnFront;
	int m_x;
	int m_y;
	bool m_IfPass;

	CColumn();
	~CColumn();
	void InitColumn();
	void ShowColumn();
	void MoveColumn(int step);
	bool IfTouchBird(CPlayerBird* player);
};