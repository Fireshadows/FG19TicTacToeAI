#pragma once
#include "Display.h"
#include <vector>

class Grid
{
public:
	Grid();

	bool PlaceMarker(int p_index, char p_marker, bool p_print = true);
	bool CheckVictory(int p_index, char p_marker);
	void ClearMarker(int p_index);
	bool HasEmptyTiles();

	bool CheckVictoryRecord(int p_index, char p_marker);

	std::vector<int> GetEmptyTiles();
	//int* GetEmptyTiles();

	char m_winningMarker;

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