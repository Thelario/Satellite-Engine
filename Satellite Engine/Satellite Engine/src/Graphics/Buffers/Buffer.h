#pragma once

#include <gl/glew.h>

namespace Satellite
{
	namespace Graphics
	{
		class Buffer
		{
		private:
			GLuint _bufferID;
			GLuint _componentCount;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
			~Buffer();

			inline GLuint getComponentCount() const { return _componentCount; }

			void bind() const;
			void unbind() const;
		};
	}
}