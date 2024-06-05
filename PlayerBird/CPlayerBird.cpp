#include "CPlayerBird.h"
#include"../GameConfig/GameConfig.h"


CPlayerBird::CPlayerBird()
{
	m_mode = 0;
	m_speed = 0;
	m_y = 0;
	m_x = 0;
	//m_direct = 0;
	m_a = 0; // 加速度
}

CPlayerBird::~CPlayerBird()
{
}

void CPlayerBird::InitPlayerBird()
{
	loadimage(&m_imgPlayer[0], "./res/0.png");
	loadimage(&m_imgPlayer[1], "./res/1.png");
	loadimage(&m_imgPlayer[2], "./res/2.png");
	loadimage(&m_imgPlayer[3], "./res/3.png");
	loadimage(&m_imgPlayer[4], "./res/4.png");
	loadimage(&m_imgPlayer[5], "./res/5.png");
	loadimage(&m_imgPlayer[6], "./res/6.png");
	loadimage(&m_imgPlayer[7], "./res/7.png");

	loadimage(&m_imgPlayerFront[0], "./res/0Front.png");
	loadimage(&m_imgPlayerFront[1], "./res/1Front.png");
	loadimage(&m_imgPlayerFront[2], "./res/2Front.png");
	loadimage(&m_imgPlayerFront[3], "./res/3Front.png");
	loadimage(&m_imgPlayerFront[4], "./res/4Front.png");
	loadimage(&m_imgPlayerFront[5], "./res/5Front.png");
	loadimage(&m_imgPlayerFront[6], "./res/6Front.png");
	loadimage(&m_imgPlayerFront[7], "./res/7Front.png");

	m_x = BIRD_POS_X;
	m_y = BIRD_POS_Y;
	m_mode = 0;
	m_speed = 0;
	//m_direct = 0;
	m_a = BIRD_A; // 加速度
}

void CPlayerBird::ShowPlayerBird()
{
	putimage(m_x, m_y,IMG_BIRD_WIDTH,IMG_BIRD_HEIGHT, &m_imgPlayer[m_mode],0,0,SRCPAINT);
	putimage(m_x, m_y, IMG_BIRD_WIDTH, IMG_BIRD_HEIGHT, &m_imgPlayerFront[m_mode], 0, 0, SRCAND);
}

void CPlayerBird::MovePlayerBird()
{
	m_y += m_speed;
	if (m_speed+m_a >BIRD_MAX_DOWN_SPEED)
	{
		m_speed = BIRD_MAX_DOWN_SPEED;
	}
	else
	{
		m_speed += m_a;
	}
}


