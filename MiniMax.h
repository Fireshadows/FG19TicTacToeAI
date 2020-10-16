#pragma once
#include "Grid.h"

#include <map>
#include <string>

using namespace std;

class MiniMax
{
public:
	MiniMax(char p_maxPlayer);
	std::map<string, int> Run(Grid* p_grid, int p_alpha, int p_beta, char p_player);

private:
	char m_maxPlayer;
	char m_winningPlayer;

	int m_count = 0;
};