#include "Sprite.h"

namespace Satellite
{
	namespace Graphics
	{
		Sprite::Sprite(float x, float y, float width, float height, Maths::vec4 color)
			: Renderable2D(Maths::vec3(x, y, 0.0f), Maths::vec2(width, height), color)
		{

		}
	}
}