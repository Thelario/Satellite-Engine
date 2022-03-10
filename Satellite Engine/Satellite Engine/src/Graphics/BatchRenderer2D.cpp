#include "BatchRenderer2D.h"	

namespace Satellite
{
	namespace Graphics
	{
		BatchRenderer2D::BatchRenderer2D()
		{
			Init();
		}

		BatchRenderer2D::~BatchRenderer2D()
		{
			delete _ibo;
			glDeleteBuffers(1, &_vbo);
		}

		void BatchRenderer2D::Init()
		{
			glGenVertexArrays(1, &_vao);
			glGenBuffers(1, &_vbo);

			glBindVertexArray(_vao);
			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, 0, GL_DYNAMIC_DRAW);
			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)0);
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(3 * sizeof(GLfloat)));
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			GLuint* indices = new GLuint[RENDERER_INDICES_SIZE];

			int offset = 0;
			for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
			{
				indices[  i  ] = offset + 0;
				indices[i + 1] = offset + 1;
				indices[i + 2] = offset + 2;

				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset + 0;

				offset += 4;
			}

			_ibo = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

			glBindVertexArray(0);
		}

		void BatchRenderer2D::Begin()
		{
			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			_buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}

		void BatchRenderer2D::Submit(const Renderable2D* renderable)
		{
			const Maths::vec3& position = renderable->getPosition();
			const Maths::vec2& size = renderable->getSize();
			const Maths::vec4& color = renderable->getColor();

			_buffer->vertex = position;
			_buffer->color = color; 
			_buffer++;

			_buffer->vertex = Maths::vec3(position.x, position.y + size.y, position.z);
			_buffer->color = color;
			_buffer++;

			_buffer->vertex = Maths::vec3(position.x + size.x, position.y + size.y, position.z);
			_buffer->color = color;
			_buffer++;

			_buffer->vertex = Maths::vec3(position.x + size.x, position.y, position.z);
			_buffer->color = color;
			_buffer++;

			_indexCount += 6;
		}

		void BatchRenderer2D::End()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void BatchRenderer2D::Flush()
		{
			glBindVertexArray(_vao);
			_ibo->bind();

			glDrawElements(GL_TRIANGLES, _indexCount, GL_UNSIGNED_INT, 0);

			_ibo->unbind();
			glBindVertexArray(0);

			_indexCount = 0;
		}
	}
}