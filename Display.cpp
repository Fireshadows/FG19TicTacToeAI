#include "Display.h"
#include <iostream>

Display::Display()
{

}

void Display::PrintGrid(char p_grid[])
{
	int m_gridSize = 3;
	int m_gridLength = 9;
	int m_gridIndex = 0;

	char m_marker = 'O';

	PrintLine();

	for (unsigned int x = 0; x < m_gridSize; x++)
	{
		if (m_gridIndex >= m_gridLength) break;
		
		for (unsigned int y = 0; y < m_gridSize; y++)
		{
			if (m_gridIndex >= m_gridLength) break;

			std::cout << '|';
			std::cout << p_grid[m_gridIndex];
			m_gridIndex++;
		}
		std::cout << "|\n";

		PrintLine();
	}
}

void Display::PrintLine()
{
	std::cout << "-------\n";
}
