#include "Vec2i.h"
#include <cmath>


Vec2i::Vec2i( int x, int y )
{
	this->x = x;
	this->y = y;
}

Vec2i Vec2i::operator+( const Vec2i& rhs ) const
{
	return Vec2i( x + rhs.x, y + rhs.y );
}

Vec2i& Vec2i::operator+=( const Vec2i& rhs )
{
	return *this = *this + rhs;
}

Vec2i Vec2i::operator-( const Vec2i& rhs ) const
{
	return Vec2i( x - rhs.x, y - rhs.y );
}

Vec2i& Vec2i::operator-=( const Vec2i& rhs )
{
	return *this = *this - rhs;
}

Vec2i Vec2i::operator*( int rhs ) const
{
	return Vec2i( x * rhs, y * rhs );
}

Vec2i Vec2i::operator/( int rhs ) const
{
	return Vec2i( x / rhs, y / rhs );
}

Vec2i& Vec2i::operator*=( int rhs )
{
	return *this = *this * rhs;
}

Vec2i& Vec2i::operator/=( int rhs )
{
	return *this = *this / rhs;
}

int Vec2i::GetLenSqu() const
{
	return ( x * x ) + ( y * y );
}

float Vec2i::GetLen() const // Magnitude
{
	return std::sqrt( float( GetLenSqu() ) );
}
