#include "Enemy.h"

Enemy::Enemy()
{

}

void Enemy::Draw( Graphics& gfx ) const
{
	assert( initialized );
	gfx.DrawRect( X(), Y(), Width(), Height(), GetColor() );
}

void Enemy::Update()
{
	assert( initialized );
	pos.x += v_x;
	pos.y += v_y;

	const int enemyright = pos.x + width;
	const int enemybottom = pos.y + height;

	if ( pos.x < 0 )
	{
		pos.x = 0;
		v_x = -v_x;
	}
	if ( enemyright > Graphics::ScreenWidth )
	{
		pos.x = Graphics::ScreenWidth - 1 - width;
		v_x = -v_x;
	}
	if ( pos.y < 0 )
	{
		pos.y = 0;
		v_y = -v_y;
	}
	if ( enemybottom > Graphics::ScreenHeight )
	{
		pos.y = Graphics::ScreenHeight - 1 - height;
		v_y = -v_y;
	}
}

int Enemy::X() const
{
	return this->pos.x;
}

int Enemy::Y() const
{
	return this->pos.y;
}

int Enemy::Width() const
{
	return this->width;
}

int Enemy::Height() const
{
	return this->height;
}

Color Enemy::GetColor() const
{
	return this->color;
}

void Enemy::Clamp()
{
	if ( pos.x + width > Graphics::ScreenWidth )
	{
		pos.x = Graphics::ScreenWidth - width - 1;
	}
	if ( pos.x < 0 )
	{
		pos.x = 0;
	}
	if ( pos.y + height > Graphics::ScreenHeight )
	{
		pos.y = Graphics::ScreenHeight - height - 1;
	}
	if ( pos.y < 0 )
	{
		pos.y = 0;
	}
}

void Enemy::Init( int xPos, int yPos, int xVel, int yVel )
{
	assert( !initialized );
	pos.x = xPos;
	pos.y = yPos;
	v_x = xVel;
	v_y = yVel;
	initialized = true;
}

bool Enemy::Collision( const Player& player )
{
	const int playerright = player.X() + player.Width();
	const int playerbottom = player.Y() + player.Height();
	const int enemyright = pos.x + Width();
	const int enemybottom = pos.y + Height();

	return ( playerright >= pos.x ) &&
		( player.X() <= enemyright ) &&
		( playerbottom >= pos.y ) &&
		( player.Y() <= enemybottom );
}
