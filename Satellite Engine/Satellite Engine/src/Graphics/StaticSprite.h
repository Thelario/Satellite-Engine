#pragma once

#include "Renderable2D.h"

namespace Satellite
{
	namespace Graphics
	{
		class StaticSprite : public Renderable2D
		{
		private:
			Shader* _shader;
			VertexArray* _vertexArray;
			IndexBuffer* _indexBuffer;
		public:
			StaticSprite(float x, float y, float width, float height, Maths::vec4 color, Shader* shader);
			~StaticSprite();

			inline const VertexArray* getVAO() const { return _vertexArray; }
			inline const IndexBuffer* getIBO() const { return _indexBuffer; }

			inline Shader* getShader() const { return _shader; }
		};
	}
}