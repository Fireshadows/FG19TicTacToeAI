#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	/*
	for (int i = 0; i < 9; i++)
	{
		std::cout << m_grid[i];
	}
	std::cout << "\n";
	*/
	m_display = new Display();
}

bool Grid::PlaceMarker(int p_tile, char p_marker)
{
	if (m_grid[p_tile] != m_empty) {
		std::cout << "Can't place marker here!\n";
		return false;
	}

	m_grid[p_tile] = p_marker;
	m_display->PrintGrid(m_grid);
	
	return true;
}

bool Grid::Victory()
{
	for (unsigned int i = 0; i < 9; i++)
	{

	}

	return false;
}
