#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw(Board& brd) const;
	const Location& getLocation() const;
	int getPoints() const;
	void drawPoints(Graphics& gfx);
	void increasePoints();
	bool isWin() const;
private:
	int points=300;
	static constexpr Color c = Colors::Red;
	Location loc;
};