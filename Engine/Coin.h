#pragma once

#include "Colors.h"
#include "Graphics.h"
#include "Player.h"

class Coin
{
	public:
		Coin( int x, int y );

		void Draw( Graphics& gfx ) const;
		void Update();
		int X() const;
		int Y() const;
		int Width() const;
		int Height() const;
		Color GetColor() const;
		void SetColor( Color color );
		bool Collision( const Player& player ) const;
		void Respawn( int x, int y );

	private:
		int x;
		int y;
		int width = 15;
		int height = 15;
		Color color = Colors::Yellow;
};

