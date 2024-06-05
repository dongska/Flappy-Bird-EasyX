#include "CColumnBox.h"
#include"../GameConfig/GameConfig.h"
CColumnBox::CColumnBox()
{

}
CColumnBox::~CColumnBox()
{
	list<CColumn*>::iterator ite = m_ColLst.begin();
	while (ite != m_ColLst.end())
	{
		if (*ite)
		{
			delete* ite;
			*ite = nullptr;
			ite=m_ColLst.erase(ite);
			continue;
		}
		ite++;
	}
}
void CColumnBox::InitColumnBox()
{
}

void CColumnBox::ShowAllColumn()
{
	list<CColumn*>::iterator ite = m_ColLst.begin();
	while (ite != m_ColLst.end())
	{
		if (*ite)
		{
			(*ite)->ShowColumn();
		}
		ite++;
	}
}

void CColumnBox::MoveAllColumn(int step)
{
	list<CColumn*>::iterator ite = m_ColLst.begin();
	while (ite != m_ColLst.end())
	{
		if (*ite)
		{
			(*ite)->MoveColumn(step);
			if ((*ite)->m_x < -IMG_COLUMN_WIDTH)
			{
				delete* ite;
				*ite = nullptr;
				ite = m_ColLst.erase(ite);
				continue;
			}
		}
		ite++;
	}
}
