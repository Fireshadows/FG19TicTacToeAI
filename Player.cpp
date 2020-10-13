#include "Player.h"

Player::Player(char p_marker)
{
	m_marker = p_marker;
}

bool Player::HasAvailableMoves(Grid* p_grid)
{
	if (!p_grid->HasEmptyTiles()) {
		cout << "No tiles left - It's a draw!";
		Sleep(1000);
		return false;
	}
	return true;
}
