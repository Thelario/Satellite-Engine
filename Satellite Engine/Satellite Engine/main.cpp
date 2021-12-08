#include <iostream>

#include "Window.h"

int main()
{
	using namespace Satellite;
	using namespace Graphics;

	Window window("Satellite", 1080, 720);
	glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

	while (!window.closed())
	{
		std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;

		window.clear();

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();

		window.update();
	}

	return 0;
}