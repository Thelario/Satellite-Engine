#include "Buffer.h"

namespace Satellite
{
	namespace Graphics
	{
		// We give the buffer a bunch of data and it fills the array buffer with the data
		Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
		{
			_componentCount = componentCount;

			// We generate 1 buffer object with the name of _bufferID
			glGenBuffers(1, &_bufferID); 

			// We bind the buffer object that we have generated to the GL_ARRAY_BUFFER (vertex attributes).
			glBindBuffer(GL_ARRAY_BUFFER, _bufferID); 

			// We create a new data store for the object buffer
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW); 

			// We unbind the buffer object
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		Buffer::~Buffer()
		{

		}

		void Buffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
		}

		void Buffer::unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}