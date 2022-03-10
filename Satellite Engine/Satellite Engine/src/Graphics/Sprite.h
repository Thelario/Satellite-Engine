#pragma once

#include "Renderable2D.h"

namespace Satellite
{
	namespace Graphics
	{
		class Sprite : public Renderable2D
		{
		private:

		public:
			Sprite(float x, float y, float width, float height, Maths::vec4 color);
		};
	}
}