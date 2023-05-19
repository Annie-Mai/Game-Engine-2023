#pragma once

#include"ImplRenderer.h"

namespace AEngine
{
	class OpenGLRenderer : public ImplRenderer
	{
	public:
		OpenGLRenderer();

		virtual void Draw(Image& image,
			TextureBox texCoord,
			Shader& shader,
			ScreenCoord coords) override;

		virtual void Clear() override;

	private:
		unsigned int mVBO, mVAO, mEBO;
	};
}