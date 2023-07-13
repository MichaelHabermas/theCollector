#pragma once

#include <string>
#include "Colors.h"
#include "RectI.h"

class Surface
{
	public:
	Surface( const std::string& fileName );
	Surface( int width, int height );
	Surface( const Surface& surface );
	~Surface();

	Surface& operator=( const Surface& surface );

	void PutPixel( int x, int y, Color color );

	Color GetPixel( int x, int y ) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;

	private:
	Color* p_Pixels = nullptr;
	int width;
	int height;
};
