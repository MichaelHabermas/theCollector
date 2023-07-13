#include "Coin.h"

Coin::Coin(int x, int y )
{
	this->pos.x = x;
	this->pos.y = y;
}

void Coin::Draw(Graphics& gfx) const
{
	gfx.DrawRect(X(), Y(), Width(), Height(), GetColor());
}

void Coin::Update()
{
}

int Coin::X() const
{
	return this->pos.x;
}

int Coin::Y() const
{
	return this->pos.y;
}

int Coin::Width() const
{
	return this->width;
}

int Coin::Height() const
{
	return this->height;
}

Color Coin::GetColor() const
{
	return this->color;
}

void Coin::SetColor(Color color)
{
	this->color = color;
}

bool Coin::Collision(const Player& player) const
{
	const int playerright = player.X() + player.Width();
	const int playerbottom = player.Y() + player.Height();
	const int coinright = pos.x + Width();
	const int coinbottom = pos.y + Height();

	return (playerright >= pos.x) &&
		(player.X() <= coinright) &&
		(playerbottom >= pos.y) &&
		(player.Y() <= coinbottom);
}

void Coin::Respawn(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}
