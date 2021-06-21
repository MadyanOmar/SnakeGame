#pragma once
#include "Board.h"
#include "Colors.h"

class Snake
{
private:
	class Segment
	{
		public:
			Segment();
			void InitHead(const Location& in_loc);
			void InitBody(int offset);
			void Follow(const Segment& next);
			void MoveBy(const Location& delta_loc);
			void Draw(Board& brd) const;
			const Location& getLocation() const;
		private:
			int r, g, b;
			Location loc;
			Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow(int offset);
	void Draw(Board& brd) const;
	bool isInTileExceptEnd(const Location& target) const;
	bool isInTile(const Location& target) const;
private:
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};