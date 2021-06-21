#include "Board.h"
#include <assert.h>

Board::Board(Graphics& graphics)
	:
	gfx(graphics)
{
	startPosX = 0;
	startPosY = 0;
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim((loc.x * dimension) + startPosX, (loc.y * dimension) + startPosY, dimension, dimension, c);
	if (c.GetG() > 0)
	{
		gfx.DrawRectDim((loc.x * dimension) + startPosX, (loc.y * dimension) + startPosY, dimension-18, dimension, Colors::Black);
		gfx.DrawRectDim((loc.x * dimension) + startPosX, (loc.y * dimension) + startPosY, dimension, dimension - 18, Colors::Black);
	}	
}

void Board::drawBorders()
{
	//Right border
	for (int y = startPosY; y < (height*dimension) + startPosY; y++)
	{
		gfx.PutPixel((width * dimension) + startPosX, y, Color{255,215,0});
	}
	for (int y = startPosY-5; y < (height * dimension) + startPosY+5; y++)
	{
		gfx.PutPixel((width * dimension) + startPosX+5, y, Color{ 255,215,0 });
	}

	//Left border
	for (int y = startPosY; y < (height * dimension) + startPosY; y++)
	{
		gfx.PutPixel(startPosX, y, Color{ 255,215,0 });
	}
	for (int y = startPosY-5; y < (height * dimension) + startPosY+5; y++)
	{
		gfx.PutPixel(startPosX-5, y, Color{ 255,215,0 });
	}

	//Top border
	for (int x = startPosX; x < (width * dimension) + startPosX; x++)
	{
		gfx.PutPixel(x, startPosY, Color{ 255,215,0 });
	}
	for (int x = startPosX-5; x < (width * dimension) + startPosX+5; x++)
	{
		gfx.PutPixel(x, startPosY-5, Color{ 255,215,0 });
	}

	//Bottom border
	for (int x = startPosX; x < (width * dimension) + startPosX; x++)
	{
		gfx.PutPixel(x, (height*dimension)+startPosY, Color{ 255,215,0 });
	}
	for (int x = startPosX-5; x < (width * dimension) + startPosX+5; x++)
	{
		gfx.PutPixel(x, (height * dimension) + startPosY + 5, Color{ 255,215,0 });
	}
}

void Board::setBoardPos(const int x, const int y)
{
	startPosX = x;
	startPosY = y;
}

int Board::getGridHeight() const
{
	return height;
}

int Board::getGridWidth() const
{
	return width;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x>=0 && loc.x<width && loc.y>=0 && loc.y<height;
}
