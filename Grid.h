#pragma once
#include "Display.h"

class Grid
{
public:
	Grid();

	bool PlaceMarker(int p_tile, char p_marker);
	bool Victory();

private:
	Display* m_display;

	char m_empty = ' ';
	char m_grid[9] {
		m_empty, m_empty, m_empty,
		m_empty, m_empty, m_empty,
		m_empty, m_empty, m_empty };
};