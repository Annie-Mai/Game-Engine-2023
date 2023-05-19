#pragma once

#include"RendererTypes.h"
#include"Image.h"
#include"Shader.h"

namespace AEngine
{
	class ImplRenderer
	{
	public:
		virtual void Draw(Image& image,
			TextureBox texCoord,
			Shader& shader,
			ScreenCoord coords) = 0;

		virtual void Clear() = 0;
	};
}