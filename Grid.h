#pragma once
#include "Display.h"

class Grid
{
public:
	Grid();

	bool PlaceMarker(int p_index, char p_marker);
	bool CheckVictory(int p_index, char p_marker);
	bool HasEmptyTiles();
	int* GetEmptyTiles();

private:
	Display* m_display;

	char m_empty = ' ';
	char m_grid[9] {
		m_empty, m_empty, m_empty,
		m_empty, m_empty, m_empty,
		m_empty, m_empty, m_empty };

	bool HorizontalCheck(int p_index, char p_marker);
	bool VerticalCheck(int p_index, char p_marker);
	bool DiagonalCheck(int p_index, char p_marker);
};