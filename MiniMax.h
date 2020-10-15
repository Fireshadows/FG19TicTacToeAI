#pragma once
#include "Grid.h"

#include <map>
#include <string>

using namespace std;

class MiniMax
{
public:
	MiniMax(char p_maxPlayer);

	std::map<string, int> Run(Grid* p_grid, char p_marker);

private:
	char m_maxPlayer;
	char m_winningPlayer;
};