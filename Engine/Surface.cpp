#include "Surface.h"
#include "DsaWin.h"
#include <cassert>
#include <fstream>

Surface::Surface( const std::string& fileName )
{
	std::ifstream file( fileName, std::ios::binary );
	assert( file );

	BITMAPFILEHEADER bmFileHeader;

	file.read( reinterpret_cast< char* >( &bmFileHeader ), sizeof( bmFileHeader ) );

	BITMAPINFOHEADER bmInfoHeader;

	file.read( reinterpret_cast< char* >( &bmInfoHeader ), sizeof( bmInfoHeader ) );

	assert( bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32 );
	assert( bmInfoHeader.biCompression == BI_RGB );

	const bool is32Bit = bmInfoHeader.biBitCount == 32;

	width = bmInfoHeader.biWidth;

	int yStart;
	int yEnd;
	int dy;

	if ( bmInfoHeader.biHeight < 0 )
	{
		height = -bmInfoHeader.biHeight;
		yStart = 0;
		yEnd = height;
		dy = 1;
	}
	else
	{
		height = bmInfoHeader.biHeight;
		yStart = height - 1;
		yEnd = -1;
		dy = -1;
	}

	p_Pixels = new Color[width * height];

	file.seekg( bmFileHeader.bfOffBits );
	const int padding = ( 4 - ( width * 3 ) % 4 ) % 4;

	for ( int y = yStart; y != yEnd; y += dy )
	{
		for ( int x = 0; x < width; x++ )
		{
			PutPixel( x, y, Color( file.get(), file.get(), file.get() ) );
			if ( is32Bit )
			{
				file.seekg( 1, std::ios::cur );
			}
		}
		if ( !is32Bit )
		{
			file.seekg( padding, std::ios::cur );
		}
	}
}

Surface::Surface( int width, int height )
{
	this->width = width;
	this->height = height;

	p_Pixels = new Color[width * height];
}

Surface::Surface( const Surface& surface ) :
	Surface( surface.width, surface.height )
{
	const int n_Pixels = width * height;

	for ( int i = 0; i < n_Pixels; i++ )
	{
		p_Pixels[i] = surface.p_Pixels[i];
	}
}

Surface::~Surface()
{
	delete[] p_Pixels;
	p_Pixels = nullptr;
}

Surface& Surface::operator=( const Surface& surface )
{
	width = surface.width;
	height = surface.height;

	delete[] p_Pixels;
	p_Pixels = new Color[width * height];

	const int n_Pixels = width * height;

	for ( int i = 0; i < n_Pixels; i++ )
	{
		p_Pixels[i] = surface.p_Pixels[i];
	}
	return *this;
}

void Surface::PutPixel( int x, int y, Color color )
{
	assert( x >= 0 );
	assert( y >= 0 );
	assert( x < width );
	assert( y < height );

	p_Pixels[( y * width ) + x] = color;
}

Color Surface::GetPixel( int x, int y ) const
{
	assert( x >= 0 );
	assert( y >= 0 );
	assert( x < width );
	assert( y < height );

	return p_Pixels[( y * width ) + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

RectI Surface::GetRect() const
{
	return { 0, width, 0, height };
}
