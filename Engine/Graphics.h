#pragma once
#include "DsaWin.h"
#include <d3d11.h>
#include <wrl.h>
#include "DsaException.h"
#include "Colors.h"

class Graphics
{
	public:
	class Exception : public DsaException
	{
		public:
		Exception( HRESULT hr, const std::wstring& note, const wchar_t* file, unsigned int line );
		std::wstring GetErrorName() const;
		std::wstring GetErrorDescription() const;
		virtual std::wstring GetFullMessage() const override;
		virtual std::wstring GetExceptionType() const override;
		private:
		HRESULT hr;
	};
	private:
		// vertex format for the framebuffer fullscreen textured quad
	struct FSQVertex
	{
		float x, y, z;		// position
		float u, v;			// texcoords
	};
	public:
	Graphics( class HWNDKey& key );
	Graphics( const Graphics& ) = delete;
	Graphics& operator=( const Graphics& ) = delete;
	void EndFrame();
	void BeginFrame();
	void PutPixel( int x, int y, int r, int g, int b )
	{
		PutPixel( x, y, { unsigned char( r ),unsigned char( g ),unsigned char( b ) } );
	}
	void PutPixel( int x, int y, Color c );
	void DrawRect( int x, int y, int width, int height, Color color );
	void DrawCircle( int x, int y, int radius, Color color );

	~Graphics();
	private:
	Microsoft::WRL::ComPtr<IDXGISwapChain>				pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device>				pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			pImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		pRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				pSysBufferTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	pSysBufferTextureView;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>			pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>			pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>				pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>			pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			pSamplerState;
	D3D11_MAPPED_SUBRESOURCE							mappedSysBufferTexture;
	Color* pSysBuffer = nullptr;
	public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};