#include "Window.h"
#include <iostream>

namespace Satellite
{
	namespace Graphics
	{
		void window_resize(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		Window::Window(const char *title, int width, int height)
		{
			_title = title;
			_width = width;
			_height = height;

			if (!init())
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; i++)
			{
				_keys[i] = false;
			}

			for (int i = 0; i <	MAX_BUTTONS; i++)
			{
				_mouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			// When you are done using GLFW, typically just before the application exits, you need to terminate GLFW.
			// This destroys any remaining windows and releases any other resources allocated by GLFW. After this call, 
			// you must initialize GLFW again before using any GLFW functions that require it.
			glfwTerminate();
		}

		bool Window::init()
		{
			// We try to initialize GLFW
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			// This function creates a window and its associated OpenGL or OpenGL ES context.
			_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);

			// When a window and context is no longer needed, destroy it:
			// glfwDestroyWindow(_window);

			if (!_window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW Window!" << std::endl;
				return false;
			}
			
			glfwMakeContextCurrent(_window); // Before I can use the OpenGL API, you must have a current OpenGL context.
			glfwSetWindowUserPointer(_window, this);
			glfwSetWindowSizeCallback(_window, window_resize); // Callback when resizing the window happens.
			glfwSetKeyCallback(_window, key_callback);
			glfwSetMouseButtonCallback(_window, mouse_button_callback);
			glfwSetCursorPosCallback(_window, cursor_position_callback);

			// Make sure to try to initialize glew after a current OpenGL context has been set.
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		bool Window::isMouseButtonPressed(unsigned int button)
		{
			// TODO: Log this!
			if (button >= MAX_BUTTONS)
				return false;

			return _mouseButtons[button];
		}

		bool Window::isKeyPressed(unsigned int keycode)
		{
			//TODO: Log this!
			if (keycode >= MAX_KEYS)
				return false;

			return _keys[keycode];
		}

		void Window::getMousePosition(double& x, double& y)
		{
			x = _mx;
			y = _my;
		}

		void Window::clear() const
		{
			// glClear clears the buffers to preset the values.
			// GL_COLOR_BUFFER_BIT: indicates the buffers currently enabled for color writing.
			// GL_DEPTH_BUFFER_BIT: indicates the depth buffer.
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			// The following code checks for possible errors and prints them
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "OpenGL Error: " << error << std::endl;

			// GLFW needs to communicate regularly with the window system both in order to receive events and to show 
			// that the application hasn't locked up. Event processing must be done regularly while you have visible 
			// windows and is normally done each frame after buffer swapping.
			glfwPollEvents();

			// This function retrieves the size, in pixels, of the framebuffer of the specified window. If you wish 
			// to retrieve the size of the window in screen coordinates, see glfwGetWindowSize.
			// glfwGetFramebufferSize(_window, &_width, &_height);

			// GLFW windows by default use double buffering. That means that each window has two rendering buffers; 
			// a front buffer and a back buffer. The front buffer is the one being displayed and the back buffer the 
			// one you render to. When the entire frame has been rendered, the buffers need to be swapped with one another,
			// so the back buffer becomes the front buffer and vice versa.
			glfwSwapBuffers(_window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(_window) == 1;
		}

		void window_resize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height); // Sets the viewport of the window
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->_keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->_mouseButtons[button] = action != GLFW_RELEASE;
		}
		
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->_mx = xpos;
			win->_my = ypos;
		}
	}
}