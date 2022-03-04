#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../Utils/FileUtils.h"
#include "../Maths/Maths.h"

namespace Satellite
{
	namespace Graphics
	{
		class Shader
		{
		private:
			GLuint _shaderId;
			const char* _vertPath;
			const char* _fragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, Maths::vec2 vector);
			void setUniform3f(const GLchar* name, Maths::vec3 vector);
			void setUniform4f(const GLchar* name, Maths::vec4 vector);
			void setUniformMat4(const GLchar* name, const Maths::mat4& matrix);

			void enable() const;
			void disable() const;
		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};
	}
}