#pragma once

#include"pch.h"
#include"AEngineUtil.h"
#include"ImplShader.h"

namespace AEngine
{
	class AENGINE_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(std::string&& vertexFile, std::string&& fragmentFile);

		void Activate();

		void Pass2FloatValues(const std::string& name, float val1, float val2);
		void Pass2FloatValues(std::string&& name, float val1, float val2);

	private:
		std::unique_ptr<ImplShader> mImplementation;
	};


}