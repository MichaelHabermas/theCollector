#include "Brick.h"

Brick::Brick( const Rectf& rect, Color color )
	:
	rect( rect ),
	color( color )
{
}

void Brick::Draw( Graphics gfx ) const
{
	gfx.DrawRect( rect, color );
}
