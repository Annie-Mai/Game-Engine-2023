#include"pch.h"
#include"Renderer.h"
#include"OpenGLCode/OpenGLRenderer.h"
#include"GameWindow.h"

namespace AEngine
{
	
#ifdef AENGINE_OPENGL
	Renderer::Renderer() :
		mImplementation(std::unique_ptr<ImplRenderer>{ new OpenGLRenderer }),
			mDefaultShader{ "../Assets/Shaders/DefaultVertexShader.glsl",
			"../Assets/Shaders/DefaultFragmentShader.glsl" }
		{}
#else
		#Only_OpenGL_is_implemented_at_the_moment
#endif

	void Renderer::Draw(Image& image, Shader& shader, ScreenCoord coords)
	{
		mImplementation->Draw(image,
			{0, 0, image.GetWidth(), image.GetHeight()},
			shader,
			coords);
	}

	void Renderer::Draw(Image& image, ScreenCoord coords)
	{
		mDefaultShader.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		mImplementation->Draw(image,
			{ 0, 0, image.GetWidth(), image.GetHeight() },
			mDefaultShader,
			coords);
	}

	void Renderer::Draw(Image& image, TextureBox texCoords, Shader& shader, ScreenCoord coords)
	{
		mImplementation->Draw(image,
			texCoords,
			shader,
			coords);
	}

	void Renderer::Draw(Image& image, TextureBox texCoords, ScreenCoord coords)
	{
		mDefaultShader.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());
		mImplementation->Draw(image,
			texCoords,
			mDefaultShader,
			coords);

	}
	void Renderer::Clear()
	{
		mImplementation->Clear();
	}
}