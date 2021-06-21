#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& graphics);
	void DrawCell(const Location& loc, Color c);
	void drawBorders();
	void setBoardPos(const int x, const int y);
	int getGridHeight() const;
	int getGridWidth() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	static constexpr int dimension = 20;
	static constexpr int width = 35;
	static constexpr int height = 25;
	int startPosX;
	int startPosY;
	Graphics& gfx;
};