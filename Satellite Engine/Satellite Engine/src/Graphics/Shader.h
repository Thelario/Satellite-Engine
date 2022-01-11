#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../Utils/FileUtils.h"

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

			void enable() const;
			void disable() const;
		private:
			GLuint load();
		};
	}
}