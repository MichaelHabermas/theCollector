#pragma once

#include "Vec2f.h"
#include "Graphics.h"

class Ball
{
	public:
	Ball( const Vec2f& pos, const Vec2f& velocity );

	void Draw( Graphics& gfx ) const;
	void Update();
	void ReboundX();
	void ReboundY();
	void Collision();
	Rectf GetRect() const;

	private:
	static constexpr float radius { 20.0f };
	static constexpr Color color { Colors::White };
	Vec2f pos;
	Vec2f velocity;

};
