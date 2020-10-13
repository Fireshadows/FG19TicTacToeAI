#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(char p_marker);

	int DecideMove(Grid* p_grid) override;
private:
	void ValidateInput();

	int m_input;
};