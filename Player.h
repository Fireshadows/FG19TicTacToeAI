#pragma once
#include "Grid.h"

#include <iostream>
#include <Windows.h>

using namespace std;

class Player
{
public:
	Player(char p_marker);

	virtual int DecideMove(Grid* p_grid) = 0;

	char m_marker = ' ';

protected:
	bool HasAvailableMoves(Grid* p_grid);
};

