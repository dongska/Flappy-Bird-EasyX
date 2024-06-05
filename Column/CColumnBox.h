#pragma once
#include"CColumn.h"
#include<list>
using namespace std;

class CColumnBox
{
public:
	list<CColumn*> m_ColLst;

	CColumnBox();
	~CColumnBox();
	void InitColumnBox();
	void ShowAllColumn();
	void MoveAllColumn(int step);
};