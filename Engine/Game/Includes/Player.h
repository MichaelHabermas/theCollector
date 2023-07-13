#pragma once

#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2i.h"

class Player
{
	public:
	Player();

	void Draw( Graphics& gfx ) const;
	void Update( const Keyboard& kbd );
	int X() const;
	int Y() const;
	int Width() const;
	int Height() const;
	Color GetColor() const;
	void Clamp();

	private:
	Vec2i pos { 400, 300 };
	int speed = 5;
	int width = 30;
	int height = 30;
	Color color = Colors::White;
	Surface sprite = Surface( "Game\\Res\\Sprites\\SmileSprite.bmp" );
};
