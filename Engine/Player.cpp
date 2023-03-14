#include "Player.h"
#include <iostream>

Player::Player()
{
	std::cout << "Alive" << std::endl;
}

void Player::Draw( Graphics& gfx ) const
{
	gfx.DrawSprite( X(), Y(), sprite );
}

void Player::Update( const Keyboard& kbd )
{
	if ( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		pos.x += speed;
	}
	if ( kbd.KeyIsPressed( VK_LEFT ) )
	{
		pos.x -= speed;
	}
	if ( kbd.KeyIsPressed( VK_UP ) )
	{
		pos.y -= speed;
	}
	if ( kbd.KeyIsPressed( VK_DOWN ) )
	{
		pos.y += speed;
	}
}

int Player::X() const
{
	return this->pos.x;
}

int Player::Y() const
{
	return this->pos.y;
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
