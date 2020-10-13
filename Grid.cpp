#include "Grid.h"
#include <iostream>
#include <vector>

Grid::Grid()
{
	m_display = new Display();
}

bool Grid::PlaceMarker(int p_index, char p_marker)
{
	if (m_grid[p_index] != m_empty) {
		std::cout << "Can't place marker here!\n";
		return false;
	}

	m_grid[p_index] = p_marker;
	m_display->PrintGrid(m_grid);
	
	return true;
}

bool Grid::CheckVictory(int p_index, char p_marker)
{
	if (HorizontalCheck(p_index, p_marker))
		return true;

	if (VerticalCheck(p_index, p_marker))
		return true;

	if (DiagonalCheck(p_index, p_marker))
		return true;
	
	return false;
}

bool Grid::HasEmptyTiles()
{
	for (unsigned int i = 0; i < 9; i++)
	{
		if (m_grid[i] == m_empty)
			return true;
	}
	return false;
}

int* Grid::GetEmptyTiles()
{
	std::vector<int> emptyTiles;

	for (unsigned int i = 0; i < 9; i++)
	{
		if (m_grid[i] == m_empty)
			emptyTiles.push_back(i);
	}

	return &emptyTiles[0];
}

bool Grid::HorizontalCheck(int p_index, char p_marker)
{
	int m_rowIndex = floor(p_index / 3);
	int m_rowStart = m_rowIndex * 3;
	int m_rowEnd = (m_rowIndex + 1) * 3;

	for (unsigned int i = m_rowStart; i < m_rowEnd; i++)
	{
		if (m_grid[i] != p_marker)
			return false;
	}
	return true;
}

bool Grid::VerticalCheck(int p_index, char p_marker)
{
	int m_colIndex = p_index % 3;
	for (unsigned int i = 0; i < 3; i++)
	{
		if (m_grid[m_colIndex + i * 3] != p_marker)
			return false;
	}
	
	return true;
}

bool Grid::DiagonalCheck(int p_index, char p_marker)
{
	if (p_index % 2 == 0)
	{
		bool m_victory = true;

		//Top Left To Bottom Right
		for (unsigned int i = 0; i <= 8; i += 4)
		{
			if (m_grid[i] != p_marker)
				m_victory = false;
		}
		if (m_victory)
			return true;

		//Top Right To Bottom Left
		m_victory = true;

		for (unsigned int i = 2; i <= 6; i += 2)
		{
			if (m_grid[i] != p_marker)
				m_victory = false;
		}

		if (m_victory)
			return true;
	}
	
	return false;
}
