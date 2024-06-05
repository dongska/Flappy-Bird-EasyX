#include "CAfterGame.h"

void CAfterGame::InitAfterGame()
{
	m_x = 0;
	m_y = 0;
	loadimage(&m_imgAfterGame, "./res/gameover.png");
	loadimage(&m_imgAfterGameFront, "./res/gameoverFront.png");
}

void CAfterGame::ShowAfterGame()
{
	putimage(m_x, m_y, IMG_BACKGROUND_WIDTH, IMG_BACKGROUND_HEIGHT, &m_imgAfterGame, 0, 0, SRCPAINT);
	putimage(m_x, m_y, IMG_BACKGROUND_WIDTH, IMG_BACKGROUND_HEIGHT, &m_imgAfterGameFront, 0, 0, SRCAND);
}

void CAfterGame::ReStartGame()
{
}
