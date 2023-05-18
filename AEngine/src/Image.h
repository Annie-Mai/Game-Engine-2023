#pragma once

#include"pch.h"
#include"AEngineUtil.h"
#include"ImplImage.h"

namespace AEngine
{
	class AENGINE_API Image
	{
	public:
		Image(const std::string& imageFile);
		Image(std::string&& imageFile);

		void Activate();

		int GetWidth()const;
		int GetHeight() const;


	private:
		std::unique_ptr<ImplImage> mImplementation{ nullptr };;

	};
}