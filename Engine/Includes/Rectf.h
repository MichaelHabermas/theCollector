#pragma once
#include "Vec2f.h"

struct Rectf
{
	Rectf() = default;
	Rectf( float left, float right, float top, float bottom );
	Rectf( const Vec2f& topLeft, const Vec2f& bottomRight );
	Rectf( const Vec2f& topLeft, float width, float height );

	bool isOverlappingWith( const Rectf& other ) const;
	bool isContainedBy( const Rectf& other ) const;
	bool ContainsPofloat( const Vec2f& pofloat ) const;

	static Rectf FromCenter( const Vec2f& centre, float halfWidth, float halfHeight );
	Rectf GetExpanded( float offset ) const;
	Vec2f GetCentre() const;
	float GetWidth() const;
	float GetHeight() const;

	float left;
	float right;
	float top;
	float bottom;
};
