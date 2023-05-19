#include"pch.h"
#include"Shader.h"
#include"OpenGLCode/OpenGLShader.h"

namespace AEngine
{
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef AENGINE_OPENGL
		mImplementation = std::unique_ptr<ImplShader>{ new OpenGLShader{vertexFile, fragmentFile} };
#else
	#Only_OpenGL_is_implemented_at_the_moment
#endif
	}

	Shader::Shader(std::string&& vertexFile, std::string&& fragmentFile)
	{
#ifdef AENGINE_OPENGL
		mImplementation = std::unique_ptr<ImplShader>{ new OpenGLShader{std::move(vertexFile), std::move(fragmentFile)} };
#else
		#Only_OpenGL_is_implemented_at_the_moment
#endif
	}

	void Shader::Activate()
	{
		mImplementation->Activate();
	}

	void Shader::Pass2FloatValues(const std::string& name, float val1, float val2)
	{
		mImplementation->Pass2FloatValues(name, val1, val2);
	}

	void Shader::Pass2FloatValues(std::string&& name, float val1, float val2)
	{
		mImplementation->Pass2FloatValues(name, val1, val2);
	}
}
