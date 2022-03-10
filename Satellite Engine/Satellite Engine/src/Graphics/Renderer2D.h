#pragma once

#include "StaticSprite.h"

namespace Satellite
{
	namespace Graphics
	{
		class Renderer2D
		{
		protected:
			virtual void Submit(const Renderable2D* renderable) = 0;
			virtual void Flush() = 0;
		};
	}
}