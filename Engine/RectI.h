#pragma once
#include "Vec2i.h"

struct RectI
{
	RectI() = default;
	RectI(int left, int right, int top, int bottom);
	RectI(const Vec2i& topLeft, const Vec2i& bottomRight);
	RectI(const Vec2i& topLeft, int width, int height);

	bool isOverlappingWith(const RectI& other) const;
	bool isContainedBy(const RectI& other) const;
	bool ContainsPoint(const Vec2i& point) const;

	static RectI FromCenter(const Vec2i& centre, int halfWidth, int halfHeight);
	RectI GetExpanded(int offset) const;
	Vec2i GetCentre() const;
	int GetWidth() const;
	int GetHeight() const;

	int left;
	int right;
	int top;
	int bottom;

};
