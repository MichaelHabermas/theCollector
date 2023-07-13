#pragma once

#include "Colors.h"
#include "Graphics.h"
#include "Player.h"
#include "Sound.h"
#include <assert.h>

class Enemy
{
	public:
	Enemy();

	void Draw( Graphics& gfx ) const;
	void Update();
	int X() const;
	int Y() const;
	int Width() const;
	int Height() const;
	Color GetColor() const;
	void Clamp();
	void Init( int xPos, int yPos, int xVel, int yVel );
	bool Collision( const Player& player );

	private:
	Vec2i pos { 100, 100 };
	int v_x = 1;
	int v_y = 1;
	int width = 40;
	int height = 40;
	Color color = Colors::Red;
	bool initialized = false;
	Sound boing = Sound( L"Game\\Res\\Sound\\boing.wav" );
};
