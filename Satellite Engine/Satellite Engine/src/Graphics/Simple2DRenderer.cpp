#include "Simple2DRenderer.h"

namespace Satellite
{
	namespace Graphics
	{
		void Simple2DRenderer::Submit(const Renderable2D* renderable)
		{
			_renderQueue.push_back((StaticSprite*)renderable);
		}

		void Simple2DRenderer::Flush()
		{
			while (!_renderQueue.empty())
			{
				const StaticSprite* staticSprite = _renderQueue.front();

				staticSprite->getVAO()->bind();
				staticSprite->getIBO()->bind();

				// Very simple but very ineficient. 
				// Right now we need 1 draw call per renderable, which is a very slow way to do it, but gets the job done for the moment.
				staticSprite->getShader()->setUniformMat4("ml_matrix", Maths::mat4::translate(staticSprite->getPosition()));
				glDrawElements(GL_TRIANGLES, staticSprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

				staticSprite->getIBO()->unbind();
				staticSprite->getVAO()->unbind();

				_renderQueue.pop_front();
			}
		}
	}
}