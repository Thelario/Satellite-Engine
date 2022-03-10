#pragma once

#include <vector>
#include <gl/glew.h>
#include "Buffer.h"

namespace Satellite
{
	namespace Graphics
	{
		class VertexArray
		{
		private:
			GLuint _arrayID;
			std::vector<Buffer*> _buffers;
		public:
			VertexArray();
			~VertexArray();

			void AddBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unbind() const;
		};
	}
}