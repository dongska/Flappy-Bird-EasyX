#include"CColumn.h"
#include"../GameConfig/GameConfig.h"
#include"../BirdAPP/CBirdAPP.h"

CColumn::CColumn()
{
	m_x = 0;
	m_y = 0;
	m_IfPass = 0;
}

CColumn::~CColumn()
{

}

void CColumn::InitColumn()
{
	loadimage(&m_imgColumn, "./res/column.png");
	loadimage(&m_imgColumnFront, "./res/columnFront.png");
	m_x = WINDOW_WIDTH + 5;
	m_y = (-CBirdAPP::m_rand % (340)) - 120;
	m_IfPass = 0;
}

void CColumn::ShowColumn()
{
	putimage(m_x, m_y, IMG_COLUMN_WIDTH, IMG_COLUMN_HEIGHT, &m_imgColumn, 0, 0, SRCPAINT);
	putimage(m_x, m_y, IMG_COLUMN_WIDTH, IMG_COLUMN_HEIGHT, &m_imgColumnFront, 0, 0, SRCAND);
}

void CColumn::MoveColumn(int step)
{
	m_x -= step;
}

bool CColumn::IfTouchBird(CPlayerBird* player)
{
	if (m_x <= (player->m_x) + (IMG_BIRD_WIDTH) * 3 / 4 && m_x + IMG_COLUMN_WIDTH >= player->m_x
		&&
		(m_y + IMG_HALF_COLUMN_HEIGHT >= (player->m_y) + (IMG_BIRD_HEIGHT * 1 / 4)
			||
			m_y + IMG_COLUMN_DOWN_Y <= (player->m_y) + (IMG_BIRD_HEIGHT) * 3 / 4)
		)
	{
		
		return true;
	}
	return false;
}
