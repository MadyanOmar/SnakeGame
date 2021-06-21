#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].getLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow(int offset)
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody(offset);
		nSegments++;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::isInTileExceptEnd(const Location& target) const
{
	for (int i = 0; i < nSegments-1; i++)
	{
		if (segments[i].getLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::isInTile(const Location& target) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].getLocation() == target)
		{
			return true;
		}
	}
	return false;
}

Snake::Segment::Segment()
{
	r = 150;
	g = 255;
	b = 0;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Color(255,255,0);
}

void Snake::Segment::InitBody(int offset)
{
	//Go from light green to dark green
	if (offset >= 150)
	{
		r = 0;
		offset -= 152;
		offset + 6;
		g -= offset;
	}
	//Go from yellow to green
	else
	{
		r -= offset;
	}
	c = Color(r,g,b);
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::getLocation() const
{
	return loc;
}
