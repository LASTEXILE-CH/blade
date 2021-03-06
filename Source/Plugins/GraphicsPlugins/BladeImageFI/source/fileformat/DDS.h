/********************************************************************
	created:	2012/04/26
	filename: 	DDS.h
	author:		Crazii
	purpose:	DDS file loading. 
	from:		http://blogs.msdn.com/cfs-file.ashx/__key/communityserver-components-postattachments/00-10-03-88-57/DDSTextureLoader-Updates-August-2011.zip
				http://blogs.msdn.com/b/chuckw/archive/2010/07/15/ddswithoutd3dx-sample-update.aspx
				changed by crazii for Blade engine
*********************************************************************/

//--------------------------------------------------------------------------------------
// dds.h
//
// This header defines constants and structures that are useful when parsing 
// DDS files.  DDS files were originally designed to use several structures
// and constants that are native to DirectDraw and are defined in ddraw.h,
// such as DDSURFACEDESC2 and DDSCAPS2.  This file defines similar 
// (compatible) constants and structures so that one can use DDS files 
// without needing to include ddraw.h.
//--------------------------------------------------------------------------------------

#ifndef __Blade_DDS_h__
#define __Blade_DDS_h__

#include <utility/IOBuffer.h>
#include <interface/public/graphics/PixelFormat.h>

#ifndef MAKEFOURCC

#	define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
	((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |       \
	((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
#endif

#define DDS_MAGIC 0x20534444 // "DDS "

namespace Blade
{
	namespace DDSUtil
	{
	
		typedef ulong DWORD;
		typedef uchar BYTE;
		typedef uint UINT;
		typedef wchar WCHAR;

#pragma pack(push,1)

		//following code from NVidia-Texture Tools
		//http://code.google.com/p/nvidia-texture-tools/
		enum D3DFORMAT
		{
			D3DFMT_UNKNOWN              =  0,

			// 32 bit RGB formats.
			D3DFMT_R8G8B8 = 20,
			D3DFMT_A8R8G8B8 = 21,
			D3DFMT_X8R8G8B8 = 22,
			D3DFMT_R5G6B5 = 23,
			D3DFMT_X1R5G5B5 = 24,
			D3DFMT_A1R5G5B5 = 25,
			D3DFMT_A4R4G4B4 = 26,
			D3DFMT_R3G3B2 = 27,
			D3DFMT_A8 = 28,
			D3DFMT_A8R3G3B2 = 29,
			D3DFMT_X4R4G4B4 = 30,
			D3DFMT_A2B10G10R10 = 31,
			D3DFMT_A8B8G8R8 = 32,
			D3DFMT_X8B8G8R8 = 33,
			D3DFMT_G16R16 = 34,
			D3DFMT_A2R10G10B10 = 35,

			D3DFMT_A16B16G16R16 = 36,

			// Palette formats.
			D3DFMT_A8P8 = 40,
			D3DFMT_P8 = 41,

			// Luminance formats.
			D3DFMT_L8 = 50,
			D3DFMT_A8L8 = 51,
			D3DFMT_A4L4 = 52,
			D3DFMT_L16 = 81,

			// Floating point formats
			D3DFMT_R16F = 111,
			D3DFMT_G16R16F = 112,
			D3DFMT_A16B16G16R16F = 113,
			D3DFMT_R32F = 114,
			D3DFMT_G32R32F = 115,
			D3DFMT_A32B32G32R32F = 116,

			//
			D3DFMT_DXT1                 = MAKEFOURCC('D', 'X', 'T', '1'),
			D3DFMT_DXT2                 = MAKEFOURCC('D', 'X', 'T', '2'),
			D3DFMT_DXT3                 = MAKEFOURCC('D', 'X', 'T', '3'),
			D3DFMT_DXT4                 = MAKEFOURCC('D', 'X', 'T', '4'),
			D3DFMT_DXT5                 = MAKEFOURCC('D', 'X', 'T', '5'),
		};

		// DXGI formats.
		enum DXGI_FORMAT
		{
			DXGI_FORMAT_UNKNOWN = 0,

			DXGI_FORMAT_R32G32B32A32_TYPELESS = 1,
			DXGI_FORMAT_R32G32B32A32_FLOAT = 2,
			DXGI_FORMAT_R32G32B32A32_UINT = 3,
			DXGI_FORMAT_R32G32B32A32_SINT = 4,

			DXGI_FORMAT_R32G32B32_TYPELESS = 5,
			DXGI_FORMAT_R32G32B32_FLOAT = 6,
			DXGI_FORMAT_R32G32B32_UINT = 7,
			DXGI_FORMAT_R32G32B32_SINT = 8,

			DXGI_FORMAT_R16G16B16A16_TYPELESS = 9,
			DXGI_FORMAT_R16G16B16A16_FLOAT = 10,
			DXGI_FORMAT_R16G16B16A16_UNORM = 11,
			DXGI_FORMAT_R16G16B16A16_UINT = 12,
			DXGI_FORMAT_R16G16B16A16_SNORM = 13,
			DXGI_FORMAT_R16G16B16A16_SINT = 14,

			DXGI_FORMAT_R32G32_TYPELESS = 15,
			DXGI_FORMAT_R32G32_FLOAT = 16,
			DXGI_FORMAT_R32G32_UINT = 17,
			DXGI_FORMAT_R32G32_SINT = 18,

			DXGI_FORMAT_R32G8X24_TYPELESS = 19,
			DXGI_FORMAT_D32_FLOAT_S8X24_UINT = 20,
			DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,
			DXGI_FORMAT_X32_TYPELESS_G8X24_UINT = 22,

			DXGI_FORMAT_R10G10B10A2_TYPELESS = 23,
			DXGI_FORMAT_R10G10B10A2_UNORM = 24,
			DXGI_FORMAT_R10G10B10A2_UINT = 25,

			DXGI_FORMAT_R11G11B10_FLOAT = 26,

			DXGI_FORMAT_R8G8B8A8_TYPELESS = 27,
			DXGI_FORMAT_R8G8B8A8_UNORM = 28,
			DXGI_FORMAT_R8G8B8A8_UNORM_SRGB = 29,
			DXGI_FORMAT_R8G8B8A8_UINT = 30,
			DXGI_FORMAT_R8G8B8A8_SNORM = 31,
			DXGI_FORMAT_R8G8B8A8_SINT = 32,

			DXGI_FORMAT_R16G16_TYPELESS = 33,
			DXGI_FORMAT_R16G16_FLOAT = 34,
			DXGI_FORMAT_R16G16_UNORM = 35,
			DXGI_FORMAT_R16G16_UINT = 36,
			DXGI_FORMAT_R16G16_SNORM = 37,
			DXGI_FORMAT_R16G16_SINT = 38,

			DXGI_FORMAT_R32_TYPELESS = 39,
			DXGI_FORMAT_D32_FLOAT = 40,
			DXGI_FORMAT_R32_FLOAT = 41,
			DXGI_FORMAT_R32_UINT = 42,
			DXGI_FORMAT_R32_SINT = 43,

			DXGI_FORMAT_R24G8_TYPELESS = 44,
			DXGI_FORMAT_D24_UNORM_S8_UINT = 45,
			DXGI_FORMAT_R24_UNORM_X8_TYPELESS = 46,
			DXGI_FORMAT_X24_TYPELESS_G8_UINT = 47,

			DXGI_FORMAT_R8G8_TYPELESS = 48,
			DXGI_FORMAT_R8G8_UNORM = 49,
			DXGI_FORMAT_R8G8_UINT = 50,
			DXGI_FORMAT_R8G8_SNORM = 51,
			DXGI_FORMAT_R8G8_SINT = 52,

			DXGI_FORMAT_R16_TYPELESS = 53,
			DXGI_FORMAT_R16_FLOAT = 54,
			DXGI_FORMAT_D16_UNORM = 55,
			DXGI_FORMAT_R16_UNORM = 56,
			DXGI_FORMAT_R16_UINT = 57,
			DXGI_FORMAT_R16_SNORM = 58,
			DXGI_FORMAT_R16_SINT = 59,

			DXGI_FORMAT_R8_TYPELESS = 60,
			DXGI_FORMAT_R8_UNORM = 61,
			DXGI_FORMAT_R8_UINT = 62,
			DXGI_FORMAT_R8_SNORM = 63,
			DXGI_FORMAT_R8_SINT = 64,
			DXGI_FORMAT_A8_UNORM = 65,

			DXGI_FORMAT_R1_UNORM = 66,

			DXGI_FORMAT_R9G9B9E5_SHAREDEXP = 67,

			DXGI_FORMAT_R8G8_B8G8_UNORM = 68,
			DXGI_FORMAT_G8R8_G8B8_UNORM = 69,

			DXGI_FORMAT_BC1_TYPELESS = 70,
			DXGI_FORMAT_BC1_UNORM = 71,
			DXGI_FORMAT_BC1_UNORM_SRGB = 72,

			DXGI_FORMAT_BC2_TYPELESS = 73,
			DXGI_FORMAT_BC2_UNORM = 74,
			DXGI_FORMAT_BC2_UNORM_SRGB = 75,

			DXGI_FORMAT_BC3_TYPELESS = 76,
			DXGI_FORMAT_BC3_UNORM = 77,
			DXGI_FORMAT_BC3_UNORM_SRGB = 78,

			DXGI_FORMAT_BC4_TYPELESS = 79,
			DXGI_FORMAT_BC4_UNORM = 80,
			DXGI_FORMAT_BC4_SNORM = 81,

			DXGI_FORMAT_BC5_TYPELESS = 82,
			DXGI_FORMAT_BC5_UNORM = 83,
			DXGI_FORMAT_BC5_SNORM = 84,

			DXGI_FORMAT_B5G6R5_UNORM = 85,
			DXGI_FORMAT_B5G5R5A1_UNORM = 86,
			DXGI_FORMAT_B8G8R8A8_UNORM = 87,
			DXGI_FORMAT_B8G8R8X8_UNORM = 88,

			DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,
			DXGI_FORMAT_B8G8R8A8_TYPELESS = 90,
			DXGI_FORMAT_B8G8R8A8_UNORM_SRGB = 91,
			DXGI_FORMAT_B8G8R8X8_TYPELESS = 92,
			DXGI_FORMAT_B8G8R8X8_UNORM_SRGB = 93,

			DXGI_FORMAT_BC6H_TYPELESS = 94,
			DXGI_FORMAT_BC6H_UF16 = 95,
			DXGI_FORMAT_BC6H_SF16 = 96,

			DXGI_FORMAT_BC7_TYPELESS = 97,
			DXGI_FORMAT_BC7_UNORM = 98,
			DXGI_FORMAT_BC7_UNORM_SRGB = 99,
		};



		struct DDS_PIXELFORMAT
		{
			DWORD dwSize;
			DWORD dwFlags;
			DWORD dwFourCC;
			DWORD dwRGBBitCount;
			DWORD dwRBitMask;
			DWORD dwGBitMask;
			DWORD dwBBitMask;
			DWORD dwABitMask;
		};

#define DDS_FOURCC      0x00000004  // DDPF_FOURCC
#define DDS_RGB         0x00000040  // DDPF_RGB
#define DDS_RGBA        0x00000041  // DDPF_RGB | DDPF_ALPHAPIXELS
#define DDS_LUMINANCE   0x00020000  // DDPF_LUMINANCE
#define DDS_ALPHA       0x00000002  // DDPF_ALPHA

		const DDS_PIXELFORMAT DDSPF_DXT1 =
		{ sizeof(DDS_PIXELFORMAT), DDS_FOURCC, MAKEFOURCC('D','X','T','1'), 0, 0, 0, 0, 0 };

		const DDS_PIXELFORMAT DDSPF_DXT2 =
		{ sizeof(DDS_PIXELFORMAT), DDS_FOURCC, MAKEFOURCC('D','X','T','2'), 0, 0, 0, 0, 0 };

		const DDS_PIXELFORMAT DDSPF_DXT3 =
		{ sizeof(DDS_PIXELFORMAT), DDS_FOURCC, MAKEFOURCC('D','X','T','3'), 0, 0, 0, 0, 0 };

		const DDS_PIXELFORMAT DDSPF_DXT4 =
		{ sizeof(DDS_PIXELFORMAT), DDS_FOURCC, MAKEFOURCC('D','X','T','4'), 0, 0, 0, 0, 0 };

		const DDS_PIXELFORMAT DDSPF_DXT5 =
		{ sizeof(DDS_PIXELFORMAT), DDS_FOURCC, MAKEFOURCC('D','X','T','5'), 0, 0, 0, 0, 0 };

		const DDS_PIXELFORMAT DDSPF_A8R8G8B8 =
		{ sizeof(DDS_PIXELFORMAT), DDS_RGBA, 0, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000 };

		const DDS_PIXELFORMAT DDSPF_A1R5G5B5 =
		{ sizeof(DDS_PIXELFORMAT), DDS_RGBA, 0, 16, 0x00007c00, 0x000003e0, 0x0000001f, 0x00008000 };

		const DDS_PIXELFORMAT DDSPF_A4R4G4B4 =
		{ sizeof(DDS_PIXELFORMAT), DDS_RGBA, 0, 16, 0x00000f00, 0x000000f0, 0x0000000f, 0x0000f000 };

		const DDS_PIXELFORMAT DDSPF_R8G8B8 =
		{ sizeof(DDS_PIXELFORMAT), DDS_RGB, 0, 24, 0x00ff0000, 0x0000ff00, 0x000000ff, 0x00000000 };

		const DDS_PIXELFORMAT DDSPF_R5G6B5 =
		{ sizeof(DDS_PIXELFORMAT), DDS_RGB, 0, 16, 0x0000f800, 0x000007e0, 0x0000001f, 0x00000000 };

		// This indicates the DDS_HEADER_DXT10 extension is present (the format is in dxgiFormat)
		const DDS_PIXELFORMAT DDSPF_DX10 =
		{ sizeof(DDS_PIXELFORMAT), DDS_FOURCC, MAKEFOURCC('D','X','1','0'), 0, 0, 0, 0, 0 };

#define DDS_HEADER_FLAGS_TEXTURE        0x00001007  // DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT 
#define DDS_HEADER_FLAGS_MIPMAP         0x00020000  // DDSD_MIPMAPCOUNT
#define DDS_HEADER_FLAGS_VOLUME         0x00800000  // DDSD_DEPTH
#define DDS_HEADER_FLAGS_PITCH          0x00000008  // DDSD_PITCH
#define DDS_HEADER_FLAGS_LINEARSIZE     0x00080000  // DDSD_LINEARSIZE

#define DDS_HEIGHT 0x00000002 // DDSD_HEIGHT
#define DDS_WIDTH  0x00000004 // DDSD_WIDTH

//CAPS
#define DDS_SURFACE_FLAGS_TEXTURE 0x00001000 // DDSCAPS_TEXTURE
#define DDS_SURFACE_FLAGS_MIPMAP  0x00400008 // DDSCAPS_COMPLEX | DDSCAPS_MIPMAP
#define DDS_SURFACE_FLAGS_COMPLEX 0x00000008 // DDSCAPS_COMPLEX

//CAPS2
#define DDS_CUBEMAP 0x00000200 // DDSCAPS2_CUBEMAP

#define DDS_CUBEMAP_POSITIVEX 0x00000600 // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_POSITIVEX
#define DDS_CUBEMAP_NEGATIVEX 0x00000a00 // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_NEGATIVEX
#define DDS_CUBEMAP_POSITIVEY 0x00001200 // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_POSITIVEY
#define DDS_CUBEMAP_NEGATIVEY 0x00002200 // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_NEGATIVEY
#define DDS_CUBEMAP_POSITIVEZ 0x00004200 // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_POSITIVEZ
#define DDS_CUBEMAP_NEGATIVEZ 0x00008200 // DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_NEGATIVEZ

#define DDS_CUBEMAP_ALLFACES ( DDS_CUBEMAP_POSITIVEX | DDS_CUBEMAP_NEGATIVEX |\
	DDS_CUBEMAP_POSITIVEY | DDS_CUBEMAP_NEGATIVEY |\
	DDS_CUBEMAP_POSITIVEZ | DDS_CUBEMAP_NEGATIVEZ )

#define DDS_FLAGS_VOLUME 0x00200000 // DDSCAPS2_VOLUME

		// Subset here matches D3D10_RESOURCE_DIMENSION and D3D11_RESOURCE_DIMENSION
		typedef enum DDS_RESOURCE_DIMENSION
		{
			DDS_DIMENSION_TEXTURE1D	= 2,
			DDS_DIMENSION_TEXTURE2D	= 3,
			DDS_DIMENSION_TEXTURE3D	= 4,
		} DDS_RESOURCE_DIMENSION;

		// Subset here matches D3D10_RESOURCE_MISC_FLAG and D3D11_RESOURCE_MISC_FLAG
		typedef enum DDS_RESOURCE_MISC_FLAG
		{
			DDS_RESOURCE_MISC_TEXTURECUBE = 0x4L,
		} DDS_RESOURCE_MISC_FLAG;

		typedef struct
		{
			DWORD dwSize;
			DWORD dwFlags;
			DWORD dwHeight;
			DWORD dwWidth;
			DWORD dwPitchOrLinearSize;
			DWORD dwDepth; // only if DDS_HEADER_FLAGS_VOLUME is set in dwFlags
			DWORD dwMipMapCount;
			DWORD dwReserved1[11];
			DDS_PIXELFORMAT ddspf;
			DWORD dwCaps;
			DWORD dwCaps2;
			DWORD dwCaps3;
			DWORD dwCaps4;
			DWORD dwReserved2;
		} DDS_HEADER;

		typedef struct
		{
			DXGI_FORMAT dxgiFormat;
			UINT resourceDimension;
			DWORD miscFlag; // see DDS_RESOURCE_MISC_FLAG
			UINT arraySize;
			UINT reserved;
		} DDS_HEADER_DXT10;

#pragma pack(pop)


		/*
		@describe
		@param
		@return
		*/
		bool		loadTextureData(IOBuffer& buffer, DDS_HEADER* pHeader, size_t* faceCount, const DDS_HEADER_DXT10** ppDX10Header, uint8** ppBitData, size_t* pBitSize);

		/*
		@describe save texture as DDS file
		@param
		@return
		*/
		bool		saveTexture(IOBuffer& buffer, const DDS_HEADER& header, const DDS_HEADER_DXT10* pDX10Header, const uint8* bitData, size_t bitSize);

		/*
		@describe
		@param
		@return
		*/
		PixelFormat	getPixelFormat(const DDS_PIXELFORMAT& ddpf, const DDS_HEADER_DXT10* pDX10Header);

		/*
		@describe
		@param
		@return
		*/
		DDS_PIXELFORMAT	getDDSFormat(PixelFormat format);

		/*
		@describe
		@param
		@return
		*/
		DXGI_FORMAT		getDXGIFormat(PixelFormat format);


		/*
		@describe
		@param
		@return
		*/
		void		getSurfaceInfo(size_t width, size_t height, PixelFormat fmt, size_t* pNumBytes, size_t* pRowBytes, size_t* pNumRows);
	
	}//namespace DDSUtil

}//namespace Blade

#endif //__Blade_DDS_h__
