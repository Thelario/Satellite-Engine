#include <iostream>
#include <time.h>

#include "Graphics/Window.h"
#include "Maths/Maths.h"
#include "Utils/FileUtils.h"
#include "Graphics/Shader.h"
#include "Graphics/Buffers/VertexArray.h"
#include "Graphics/Buffers/IndexBuffer.h"
#include "Graphics/Renderable2D.h"
#include "Graphics/Renderer2D.h"
#include "Graphics/Simple2DRenderer.h"
#include "Graphics/StaticSprite.h"
#include "Graphics/BatchRenderer2D.h"
#include "Graphics/Sprite.h"

int main()
{
	// We say that we want to use the code in the Satellite and Graphics namespaces.
	using namespace Satellite;
	using namespace Satellite::Utils;
	using namespace Graphics;
	using namespace Maths;

	// We create a new Window object, passing the name, width and height.
	Window window("Satellite", 1080, 720);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);

	std::vector < Renderable2D*> sprites;

	Sprite sprite1(0.0f, 0.0f, 8.0f, 4.0f, vec4(1, 0, 1, 1));
	Sprite sprite2(2.0f, 4.0f, 8.0f, 4.0f, vec4(0, 1, 1, 1));
	Sprite sprite3(4.0f, 2.0f, 8.0f, 4.0f, vec4(1, 1, 0, 1));

	BatchRenderer2D renderer;

	srand(time(NULL));

	for (float y = 0; y < 9.0f; y += 0.05f)
	{
		for (float x = 0; x < 16.0f; x += 0.05f)
		{
			sprites.push_back(new Sprite(x, y, 0.04f, 0.04f, Maths::vec4(rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, 1.0f)));
		}
	}
	
	shader.setUniform2f("light_pos", vec2(8.0f, 4.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed()) // We loop infinitely till the user closes the window (with the red button in the right upper corner).
	{
		window.clear();

		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 1080.0f), (float)(9.0f - y * 9.0f / 720.0f)));
		
		renderer.Begin();

		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.Submit(sprites[i]);
		}

		//renderer.Submit(&sprite1);
		//renderer.Submit(&sprite2);
		//renderer.Submit(&sprite3);

		renderer.End();
		renderer.Flush();

		printf("Sprites: %d\n", sprites.size());

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

/* GAME LOOP */
/* LoadStuff();
 * while (!shouldExitGame)
 * {
 *		ProcessInput();
 *		UpdateGame();
 *		RenderGame(); // audio, video, etc. (output)
 * }
 * UnloadStuff();

std::string file = FileUtils::read_file("src/Main.cpp");
std::cout << file << std::endl;
system("PAUSE");
return 0;

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
*/

/*
	GLfloat vertices[] =
	{
		4, 3, 0,
		12, 3, 0,
		4, 6, 0,
		12, 6, 0
	};

	GLushort indices[] =
	{
		0, 1, 3,
		2, 3, 0
	};

	GLfloat colorsA[] =
	{
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	GLfloat colorsB[] =
	{
		0, 1, 1, 1,
		0, 1, 1, 1,
		0, 1, 1, 1,
		0, 1, 1, 1
	};

	GLfloat colorsC[] =
	{
		1, 1, 0, 1,
		1, 1, 0, 1,
		1, 1, 0, 1,
		1, 1, 0, 1
	};

	VertexArray sprite1, sprite2, sprite3;
	IndexBuffer ibo(indices, 6);

	sprite1.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.AddBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.AddBuffer(new Buffer(colorsB, 4 * 4, 4), 1);

	sprite3.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite3.AddBuffer(new Buffer(colorsC, 4 * 4, 4), 1);
*/

/*
* 
* #if 0
	GLfloat vertices[] =
	{
		4, 3, 0,
		12, 3, 0,
		4, 6, 0,
		4, 6, 0,
		12, 6, 0,
		12, 3, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#endif

#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else
		sprite1.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", mat4::translate(vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite1.unbind();

		sprite2.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", mat4::translate(vec3(3, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite2.unbind();

		sprite3.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", mat4::translate(vec3(-3, -3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite3.unbind();
#endif

*/