#include "VertexArray.h"

namespace Satellite
{
	namespace Graphics
	{
		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &_arrayID); // We generate 1 vertex array object name
		}

		VertexArray::~VertexArray()
		{
			for (int i = 0; i < _buffers.size(); i++)
				delete _buffers[i];

			glDeleteVertexArrays(1, &_arrayID);
		}

		void VertexArray::AddBuffer(Buffer* buffer, GLuint index)
		{
			bind();
			buffer->bind();

			// We enable the generic vertex attribute specified by index
			glEnableVertexAttribArray(index); 

			// We specify the location and data format of the array of generic vertex attributes at index index to use when rendering
			glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

			buffer->unbind();
			unbind();
		}

		void VertexArray::bind() const
		{
			glBindVertexArray(_arrayID); // We bind the buffer
		}

		void VertexArray::unbind() const
		{
			glBindVertexArray(0); // We unbind the buffer
		}
	}
}