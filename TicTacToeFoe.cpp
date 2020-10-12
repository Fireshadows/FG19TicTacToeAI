// TicTacToeFoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Grid.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

int main()
{
    //std::cout << "Hello World!\n";

    Grid* m_grid = new Grid();

    Player* m_player1 = new HumanPlayer('X');
    Player* m_player2 = new ComputerPlayer('O');

    Player* m_players [] {m_player1, m_player2};

    bool m_running = true;
    int m_selection = 0;

    while (m_running)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            m_selection = m_players[i]->DecideMove() - 1;
            if (m_selection < 0) {
                m_running = false;
                break;
            }
            bool m_success = m_grid->PlaceMarker(m_selection, m_players[i]->m_marker);
            //if (m_success) ;
        }
    }

}
