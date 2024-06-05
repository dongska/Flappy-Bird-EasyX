#include "BeforeGame.h"

void CBeforeGame::InitBeforeGame()
{
	loadimage(&m_imgBeforeGame, "./res/start.png");
	loadimage(&m_imgBeforeGameFront, "./res/startFront.png");
	m_x = 0;
	m_y = 0;

}

void CBeforeGame::ShowBeforeGame()
{
	putimage(m_x,m_y,IMG_BACKGROUND_WIDTH,IMG_BACKGROUND_HEIGHT,&m_imgBeforeGame,0,0,SRCPAINT);
	putimage(m_x, m_y, IMG_BACKGROUND_WIDTH, IMG_BACKGROUND_HEIGHT, &m_imgBeforeGameFront, 0, 0, SRCAND);

}

void CBeforeGame::StartGame()
{
}
