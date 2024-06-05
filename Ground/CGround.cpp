#include "CGround.h"


CGround::CGround()
{
	m_x = 0;
	m_y = 0;
}
CGround::~CGround()
{

}

void CGround::InitGround()
{
	m_x = 0;
	m_y = IMG_GROUND_POS_Y;
	loadimage(&m_imgGround, "./res/ground.png");
}

void CGround::ShowGround()
{
	putimage(m_x, m_y, &m_imgGround);
}

void CGround::MoveGround(int step)
{
		m_x -= step;
		
		if(m_x<=-IMG_GROUND_WIDTH)
		{
			m_x = 0;
		}
}

bool CGround::IfTouchGround(CPlayerBird* player)
{
	if (player->m_y + IMG_BIRD_HEIGHT * 3 / 4 >= m_y)
	{
		return true;
	}
	return false;
} 
