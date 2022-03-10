#pragma once

#include <gl/glew.h>

namespace Satellite
{
	namespace Graphics
	{
		class IndexBuffer
		{
		private:
			GLuint _bufferID;
			GLuint _count;
		public:
			IndexBuffer(GLushort* data, GLsizei count);
			IndexBuffer(GLuint* data, GLsizei count);
			~IndexBuffer();

			inline GLuint getCount() const { return _count; }

			void bind() const;
			void unbind() const;
		};
	}
}