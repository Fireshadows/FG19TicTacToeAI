#pragma once
#include "Player.h"
#include "MiniMax.h"

#include <map>

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(char p_marker);

	int DecideMove(Grid* p_grid) override;
private:

	int RandomSelection(Grid* p_grid);
	int MiniMaxSelection(Grid* p_grid);
	
	MiniMax* m_miniMax;
};