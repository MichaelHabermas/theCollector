#include "Player.h"
#include <iostream>

Player::Player()
{
	std::cout << "Alive" << std::endl;
}

void Player::Draw(Graphics& gfx) const
{
	gfx.DrawRect(X(), Y(), Width(), Height(), GetColor());
}

void Player::Update(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		x += speed;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		x -= speed;
	}
	if (kbd.KeyIsPressed(VK_UP))
	{
		y -= speed;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		y += speed;
	}
}

int Player::X() const
{
	return this->x;
}

int Player::Y() const
{
	return this->y;
}

int Player::Width() const
{
	return this->width;
}

int Player::Height() const
{
	return this->height;
}

Color Player::GetColor() const
{
	return this->color;
}

void Player::Clamp()
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
