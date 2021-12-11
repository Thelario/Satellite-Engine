#include <iostream>

#include "Window.h"

int main()
{
	// We say that we want to use the code in the Satellite and Graphics namespaces.
	using namespace Satellite;
	using namespace Graphics;

	// We create a new Window object, passing the name, width and height.
	Window window("Satellite", 1080, 720);

	// glClearColor specify clear values for the color buffers (from what I can see, it changes the background color of the window).
	glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// We loop infinitely till the user closes the window (with the red button in the right upper corner).
	while (!window.closed())
	{
		// We print in the console the width and height of the window we have created.
		// std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;

		window.clear();

		double x, y;
		window.getMousePosition(x, y);
		std::cout << "Mouse: " << x << "," << y << std::endl;

		if (window.isKeyPressed(GLFW_KEY_A))
			std::cout << "a" << std::endl;

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
			std::cout << "MOUSE 1" << std::endl;

#if 1
		// drawing a white square in the center of the window.
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}

	return 0;
}