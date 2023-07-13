#pragma once

struct Vec2i
{
	Vec2i() = default;
	Vec2i( int x, int y );

	int x;
	int y;

	Vec2i operator+ ( const Vec2i& rhs ) const;
	Vec2i& operator+= ( const Vec2i& rhs );
	Vec2i operator- ( const Vec2i& rhs ) const;
	Vec2i& operator-= ( const Vec2i& rhs );

	Vec2i operator* ( int rhs ) const;
	Vec2i operator/ ( int rhs ) const;
	Vec2i& operator*= ( int rhs );
	Vec2i& operator/= ( int rhs );

	int GetLenSqu() const;
	float GetLen() const;
};
