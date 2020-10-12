#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(char p_marker);

	int DecideMove() override;
private:
	void ValidateInput();

	int m_input;
};