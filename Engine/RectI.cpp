#include "RectI.h"

RectI::RectI( int left, int right, int top, int bottom )
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

RectI::RectI( const Vec2i& topLeft, const Vec2i& bottomRight ) :
	RectI( topLeft.x, bottomRight.x, topLeft.y, bottomRight.y )
{
}

RectI::RectI( const Vec2i& topLeft, int width, int height ) :
	RectI( topLeft, topLeft + Vec2i( width, height ) )
{
}

bool RectI::isOverlappingWith( const RectI& other ) const
{
	return left > other.left &&
		right < other.right &&
		top > other.top &&
		bottom < other.bottom;
}

bool RectI::isContainedBy( const RectI& other ) const
{
	return left >= other.left &&
		right <= other.right &&
		top >= other.top &&
		bottom <= other.bottom;
}

bool RectI::ContainsPoint( const Vec2i& point ) const
{
	return ( right >= point.x >= left ) && ( bottom >= point.y >= top );
}

RectI RectI::FromCenter( const Vec2i& centre, int halfWidth, int halfHeight )
{
	const Vec2i half = Vec2i( halfWidth, halfHeight );
	return RectI( centre - half, centre + half );
}

RectI RectI::GetExpanded( int offset ) const
{
	return RectI( left - offset, right + offset, top - offset, bottom + offset );
}

Vec2i RectI::GetCentre() const
{
	return Vec2i( ( left + right ) / 2, ( bottom + top ) / 2 );
}

int RectI::GetWidth() const
{
	return right - left;
}

int RectI::GetHeight() const
{
	return bottom - top;
}
