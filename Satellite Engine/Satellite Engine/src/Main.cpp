#include <iostream>

#include "Graphics/Window.h"
#include "Maths/Maths.h"

int main()
{
	// We say that we want to use the code in the Satellite and Graphics namespaces.
	using namespace Satellite;
	using namespace Graphics;
	using namespace Maths;

	// We create a new Window object, passing the name, width and height.
	Window window("Satellite", 1080, 720);

	// glClearColor specify clear values for the color buffers (from what I can see, it changes the background color of the window).
	glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//mat4 position = mat4::translation(vec3(2, 3, 4));
	mat4 position = mat4();
	position *= mat4::identity();

	position.elements[12] = 2.0f;

	// I cnanot do this because I cannot use unions, FUCK MY LIFE
	//vec4 c0 = position.columns[3];
	//vec4 c1 = position.columns[3];
	//std::cout << &position.elements[12] << std::endl;
	//std::cout << &position.columns[3].x << std::endl;

	// This is NOT the way to proceed, I need to be able to do the above.
	vec4 c2 = position.getColumn(3);
	std::cout << c2 << std::endl;

	// We loop infinitely till the user closes the window (with the red button in the right upper corner).
	while (!window.closed())
	{
		window.clear();
#if 1
		// drawing a white square in the center of the window.
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}

	return 0;
}

/* TESTING INPUT */
//double x, y;
//window.getMousePosition(x, y);
//std::cout << "Mouse: " << x << "," << y << std::endl;

//if (window.isKeyPressed(GLFW_KEY_A))
//	std::cout << "a" << std::endl;

//if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
//	std::cout << "MOUSE 1" << std::endl;