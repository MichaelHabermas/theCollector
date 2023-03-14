#include "Vec2f.h"
#include <cmath>

Vec2f::Vec2f( float x, float y )
{
	this->x = x;
	this->y = y;
}

Vec2f Vec2f::operator+( const Vec2f& rhs ) const
{
	return Vec2f( x + rhs.x, y + rhs.y );
}

Vec2f& Vec2f::operator+=( const Vec2f& rhs )
{
	return *this = *this + rhs;
}

Vec2f Vec2f::operator-( const Vec2f& rhs ) const
{
	return Vec2f( x - rhs.x, y - rhs.y );
}

Vec2f& Vec2f::operator-=( const Vec2f& rhs )
{
	return *this = *this - rhs;
}

Vec2f Vec2f::operator*( float rhs ) const
{
	return Vec2f( x * rhs, y * rhs );
}

Vec2f Vec2f::operator/( float rhs ) const
{
	return Vec2f( x / rhs, y / rhs );
}

Vec2f& Vec2f::operator*=( float rhs )
{
	return *this = *this * rhs;
}

Vec2f& Vec2f::operator/=( float rhs )
{
	return *this = *this / rhs;
}

float Vec2f::GetLenSqu() const
{
	return ( x * x ) + ( y * y );
}

float Vec2f::GetLen() const // Magnitude
{
	return std::sqrt( float( GetLenSqu() ) );
}
