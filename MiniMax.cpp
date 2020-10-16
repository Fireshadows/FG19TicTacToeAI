#include "MiniMax.h"
#include <vector>
#include <algorithm>
#include <iostream>

MiniMax::MiniMax(char p_maxPlayer) : m_maxPlayer(p_maxPlayer), m_winningPlayer(' ')
{
}

std::map<string, int> MiniMax::Run(Grid* p_grid, int p_alpha, int p_beta, char p_player)
{
	map<string, int> m_bestMove;
	map<string, int> m_simulatedMove;

	char m_otherPlayer = p_player == 'X' ? 'O' : 'X';

	vector<int> m_emptyTiles = p_grid->GetEmptyTiles();

	m_bestMove["selection"] = -1;

	//If previous move was a winning move
	if (m_winningPlayer == m_otherPlayer)
	{
		m_bestMove["score"] = (m_emptyTiles.size() + 1);
		m_bestMove["score"] *= (m_otherPlayer == m_maxPlayer ? 1 : -1);
		return m_bestMove;
	}
	else if (!p_grid->HasEmptyTiles())
	{
		m_bestMove["score"] = 0;
		return m_bestMove;
	}

	if (p_player == m_maxPlayer)
		m_bestMove["score"] = numeric_limits<int>::min();
	else
		m_bestMove["score"] = numeric_limits<int>::max();

	for (int selection : m_emptyTiles)
	{
		//Simulate move at current selection
		p_grid->PlaceMarker(selection, p_player, false);
		if (p_grid->CheckVictory(selection, p_player))
			m_winningPlayer = p_player;
		m_simulatedMove = Run(p_grid, p_alpha, p_beta, m_otherPlayer);

		//Undo simulation
		p_grid->ClearMarker(selection);
		m_winningPlayer = ' ';

		m_simulatedMove["selection"] = selection;

		if (p_player == m_maxPlayer) {
			if (m_simulatedMove["score"] > m_bestMove["score"])
				m_bestMove = m_simulatedMove;
			p_alpha = std::max(m_simulatedMove["score"], p_alpha);
		}
		else {
			if (m_simulatedMove["score"] < m_bestMove["score"])
				m_bestMove = m_simulatedMove;
			p_beta = std::min(m_simulatedMove["score"], p_beta);
		}

		//Pruning
		if (p_beta <= p_alpha)
			break;
	}

	return m_bestMove;
}