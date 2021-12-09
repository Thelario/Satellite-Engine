#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Satellite
{
	namespace Graphics
	{
		class Window
		{
		private:
			int _width, _height;
		    const char *_title;
			GLFWwindow *_window;
			bool _closed;
		public:
			Window(const char *title, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			inline int getWidth() const { return _width; };
			inline int getHeight() const { return _height; };
		private:
			bool init();			
		};
	}
}