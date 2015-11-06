// Copyright 2011 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include "VideoCommon/BPMemory.h"
#include "VideoCommon/TextureCacheBase.h"
#include "VideoCommon/VideoCommon.h"

namespace DX11
{
// Maximum number of bytes that can occur in a texture block-row generated by
// the encoder
static const UINT MAX_BYTES_PER_BLOCK_ROW = (EFB_WIDTH/4)*64;
// The maximum amount of data that the texture encoder can generate in one call
static const UINT MAX_BYTES_PER_ENCODE = MAX_BYTES_PER_BLOCK_ROW*(EFB_HEIGHT/4);

class TextureEncoder
{

public:

	virtual ~TextureEncoder() { }

	virtual void Init() = 0;
	virtual void Shutdown() = 0;
	// Returns size in bytes of encoded block of memory
	virtual void Encode(u8* dst, const TextureCacheBase::TCacheEntryBase* texture_entry,
		PEControl::PixelFormat srcFormat, const EFBRectangle& srcRect,
		bool isIntensity, bool scaleByHalf) = 0;

};

}
