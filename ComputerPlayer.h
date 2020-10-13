#pragma once
#include "Player.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(char p_marker);

	int DecideMove(Grid* p_grid) override;
private:

	int RandomSelection();
	int MiniMax();
};