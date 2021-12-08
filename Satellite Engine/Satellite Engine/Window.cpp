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
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);

			if (!_window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW Window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(_window);
			glfwSetWindowSizeCallback(_window, windowResize);
			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			//glfwGetFramebufferSize(_window, &_width, &_height);
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