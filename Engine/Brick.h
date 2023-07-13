#pragma once

#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
	public:
	Brick( const Rectf& rect, Color color );
	void Draw( Graphics gfx ) const;

	private:
	Rectf rect;
	Color color;
	bool destroyed = false;
};
