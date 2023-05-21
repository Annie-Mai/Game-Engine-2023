#include"pch.h"
#include "OpenGLImage.h"
#include"glad/glad.h"
#include "stb_image.h"

namespace AEngine
{
	OpenGLImage::OpenGLImage(const std::string& imageFile)
	{
		glGenTextures(1, &mImage);
		glBindTexture(GL_TEXTURE_2D, mImage);
		//set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(imageFile.c_str(), &mWidth, &mHeight, &nrChannels, 0);

		if (data == nullptr)
			std::cout << "ERROR: Image reading has failed" << std::endl;

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}

	OpenGLImage::OpenGLImage(std::string&& imageFile)
	{
		glGenTextures(1, &mImage);
		glBindTexture(GL_TEXTURE_2D, mImage);
		//set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(imageFile.c_str(), &mWidth, &mHeight, &nrChannels, 0);

		if (data == nullptr)
			std::cout << "ERROR: Image reading has failed" << std::endl;

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}

	OpenGLImage::~OpenGLImage()
	{
		glDeleteTextures(1, &mImage);
	}

	void OpenGLImage::Activate()
	{
		glBindTexture(GL_TEXTURE_2D, mImage);
	}

	int OpenGLImage::GetWidth() const
	{
		return mWidth;
	}
	
	int OpenGLImage::GetHeight() const
	{
		return mHeight;
	}
}

