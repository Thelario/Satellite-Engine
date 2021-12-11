#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Satellite
{
	namespace Graphics
	{
		#define MAX_KEYS	1024
		#define MAX_BUTTONS	32

		class Window
		{
		private:
			int _width, _height;
		    const char *_title;
			GLFWwindow *_window;
			bool _closed;

			bool _keys[MAX_KEYS];
			bool _mouseButtons[MAX_BUTTONS];
			double _mx, _my;
		public:
			Window(const char *title, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			inline int getWidth() const { return _width; };
			inline int getHeight() const { return _height; };

			bool isKeyPressed(unsigned int keycode);
			bool isMouseButtonPressed(unsigned int button);
			void getMousePosition(double& x, double& y);
		private:
			bool init();	
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}