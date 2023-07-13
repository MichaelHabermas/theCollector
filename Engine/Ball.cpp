#include "Ball.h"

Ball::Ball( const Vec2f& pos, const Vec2f& velocity )
	:
	pos( pos ),
	velocity( velocity )
{
}

void Ball::Draw( Graphics& gfx ) const
{
	gfx.DrawCircle( pos.x, pos.y, radius, color );
}

void Ball::Update()
{
	Collision();
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}

void Ball::Collision()
{
	Rectf rect = GetRect();

	if ( rect.top < 0 || rect.bottom > Graphics::ScreenHeight )
	{
		ReboundY();
	}
	if ( rect.left < 0 || rect.right > Graphics::ScreenWidth )
	{
		ReboundX();
	}
}

Rectf Ball::GetRect() const
{
	return Rectf::FromCenter( pos, radius, radius );
}
