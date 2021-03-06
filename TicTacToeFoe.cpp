// TicTacToeFoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <string>

#include "Grid.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

int main()
{
    Grid* m_grid = new Grid();

    Player* m_player1 = new HumanPlayer('X');
    Player* m_player2 = new ComputerPlayer('O');

    Player* m_players [] {m_player1, m_player2};

    bool m_running = true;
    int m_selection = 0;

	std::cout << "TIC-TAC-TOE!\n";
	m_grid->Print();

    while (m_running)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
			bool m_success = false;
			while (!m_success)
			{
				m_selection = m_players[i]->DecideMove(m_grid) - 1;
				if (m_selection < 0)
					return 0;
				else
					m_success = m_grid->PlaceMarker(m_selection, m_players[i]->m_marker);
			}

			if (m_grid->CheckVictory(m_selection, m_players[i]->m_marker))
			{
				std::cout << "GAME OVER! Player " << m_players[i]->m_marker << " won!\n";
				m_running = false;
				break;
			}
        }
    }

	std::cout << "Shutting down...\n";
	Sleep(3500);
}
