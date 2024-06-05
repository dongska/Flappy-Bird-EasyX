#include<easyx.h>
#include"../GameConfig/GameConfig.h"
using namespace std;

class CAfterGame
{
public:
	IMAGE m_imgAfterGame;
	IMAGE m_imgAfterGameFront;
	int m_x;
	int m_y;

	void InitAfterGame();
	void ShowAfterGame();
	void ReStartGame();
};

