#include "Window.h"
#include <iostream>

namespace Satellite
{
	namespace Graphics
	{
		void windowResize(GLFWwindow* window, int width, int height);

		Window::Window(const char *title, int width, int height)
		{
			_title = title;
			_width = width;
			_height = height;

			if (!init())
				glfwTerminate();
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

			// Before I can use the OpenGL API, you must have a current OpenGL context.
			glfwMakeContextCurrent(_window);

			// Callback when resizing the window happens.
			glfwSetWindowSizeCallback(_window, windowResize);
			return true;
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
			// so the back buffer becomes the front bufferand vice versa.
			glfwSwapBuffers(_window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(_window) == 1;
		}

		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}