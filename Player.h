#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	Player(char p_marker);

	virtual int DecideMove() = 0;

	char m_marker = ' ';
};

