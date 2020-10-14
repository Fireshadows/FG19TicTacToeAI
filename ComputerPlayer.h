#pragma once
#include "Player.h"

#include <map>

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(char p_marker);

	int DecideMove(Grid* p_grid) override;
private:

	int RandomSelection(Grid* p_grid);
	map<string, int> MiniMax(Grid* p_grid, char p_marker);
};