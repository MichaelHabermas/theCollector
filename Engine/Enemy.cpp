#include "Enemy.h"

Enemy::Enemy()
{

}

void Enemy::Draw(Graphics& gfx) const
{
	assert( initialized );
	gfx.DrawRect(X(), Y(), Width(), Height(), GetColor());
}

void Enemy::Update()
{
	assert(initialized);
	x += v_x;
	y += v_y;

	const int enemyright = x + width;
	const int enemybottom = y + height;

	if (x < 0)
	{
		x = 0;
		v_x = -v_x;
	}
	if (enemyright > Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth -1 - width;
		v_x = -v_x;
	}
	if (y < 0)
	{
		y = 0;
		v_y = -v_y;
	}
	if (enemybottom > Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - 1 - height;
		v_y = -v_y;
	}
}

int Enemy::X() const
{
	return this->x;
}

int Enemy::Y() const
{
	return this->y;
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
	if (x + width > Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width - 1;
	}
	if (x < 0)
	{
		x = 0;
	}
	if (y + height > Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height - 1;
	}
	if (y < 0)
	{
		y = 0;
	}
}

void Enemy::Init( int xPos, int yPos, int xVel, int yVel )
{
	assert( !initialized );
	x = xPos;
	y = yPos;
	v_x = xVel;
	v_y = yVel;
	initialized = true;
}

bool Enemy::Collision(const Player& player)
{
	const int playerright = player.X() + player.Width();
	const int playerbottom = player.Y() + player.Height();
	const int enemyright = x + Width();
	const int enemybottom = y + Height();

	return (playerright >= x) &&
		(player.X() <= enemyright) &&
		(playerbottom >= y) &&
		(player.Y() <= enemybottom);
}
