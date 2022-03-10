#pragma once

#include <deque>
#include <gl/glew.h>
#include "../Maths/Maths.h"
#include "StaticSprite.h"
#include "Renderer2D.h"

namespace Satellite
{
	namespace Graphics
	{
		class Simple2DRenderer : public Renderer2D
		{
		private:
			std::deque<const StaticSprite*> _renderQueue;
		public:
			void Submit(const Renderable2D* staticSprite) override;
			void Flush() override;
		};
	}
}