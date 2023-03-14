#pragma once

struct Vec2f
{
	Vec2f() = default;
	Vec2f( float x, float y );

	float x;
	float y;

	Vec2f operator+ ( const Vec2f& rhs ) const;
	Vec2f& operator+= ( const Vec2f& rhs );
	Vec2f operator- ( const Vec2f& rhs ) const;
	Vec2f& operator-= ( const Vec2f& rhs );

	Vec2f operator* ( float rhs ) const;
	Vec2f operator/ ( float rhs ) const;
	Vec2f& operator*= ( float rhs );
	Vec2f& operator/= ( float rhs );

	float GetLenSqu() const;
	float GetLen() const;
};
