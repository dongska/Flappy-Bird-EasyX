#include<easyx.h>
#include"../GameConfig/GameConfig.h"
using namespace std;

class CBeforeGame
{
public:
	IMAGE m_imgBeforeGame;
	IMAGE m_imgBeforeGameFront;
	int m_x;
	int m_y;

	void InitBeforeGame();
	void ShowBeforeGame();
	void StartGame();
};

