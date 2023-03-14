#include "Rectf.h"

Rectf::Rectf( float left, float right, float top, float bottom )
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

Rectf::Rectf( const Vec2f& topLeft, const Vec2f& bottomRight ) :
	Rectf( topLeft.x, bottomRight.x, topLeft.y, bottomRight.y )
{
}

Rectf::Rectf( const Vec2f& topLeft, float width, float height ) :
	Rectf( topLeft, topLeft + Vec2f( width, height ) )
{
}

bool Rectf::isOverlappingWith( const Rectf& other ) const
{
	return left > other.left &&
		right < other.right &&
		top > other.top &&
		bottom < other.bottom;
}

bool Rectf::isContainedBy( const Rectf& other ) const
{
	return left >= other.left &&
		right <= other.right &&
		top >= other.top &&
		bottom <= other.bottom;
}

bool Rectf::ContainsPofloat( const Vec2f& pofloat ) const
{
	return ( right >= pofloat.x >= left ) && ( bottom >= pofloat.y >= top );
}

Rectf Rectf::FromCenter( const Vec2f& centre, float halfWidth, float halfHeight )
{
	const Vec2f half = Vec2f( halfWidth, halfHeight );
	return Rectf( centre - half, centre + half );
}

Rectf Rectf::GetExpanded( float offset ) const
{
	return Rectf( left - offset, right + offset, top - offset, bottom + offset );
}

Vec2f Rectf::GetCentre() const
{
	return Vec2f( ( left + right ) / 2, ( bottom + top ) / 2 );
}

float Rectf::GetWidth() const
{
	return right - left;
}

float Rectf::GetHeight() const
{
	return bottom - top;
}
