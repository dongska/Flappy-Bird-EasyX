#include"CBackGround.h"
#include"../GameConfig/GameConfig.h"

CBackGround::CBackGround()
{
	m_x = 0;
	m_y = 0;
}

CBackGround::~CBackGround()
{
}

void CBackGround::InitBackGround()
{
	loadimage(&m_imgBack, "./res/background.png");
	m_x = 0;
	m_y = 0;
}

void CBackGround::ShowBackGround()
{
	putimage(m_x, m_y, &m_imgBack);
}

//void CBackGround::MoveBackGround(int step)
//{
//	
//		m_x -= step;
//	
//	if(m_x<=-IMG_BACKGROUND_WIDTH)
//	{
//		m_x = 0;
//	}
//}
