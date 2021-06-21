#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);
	points = 0;
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.getGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.getGridHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.isInTile(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Goal::getLocation() const
{
	return loc;
}

int Goal::getPoints() const
{
	return points;
}

void Goal::drawPoints(Graphics& gfx)
{
	gfx.DrawRectDim(10, 15, points, 15, Colors::Blue);
}

bool Goal::isWin() const
{
	if (points >= 760)
	{
		return true;
	}
	return false;
}

void Goal::increasePoints()
{
	points += 17;
}
