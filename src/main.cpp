#include "../lib/Shader.h"

int main()
{
	GLFWwindow* window;

	if (GLFW_TRUE != glfwInit()) return -1;

	window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (GLEW_OK != glewInit()) return -1;

	static float trianglePositions[] =
	{
	   -1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, -1.0f, 0.0f
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(trianglePositions), trianglePositions, GL_STATIC_DRAW);

	const int sizeOfVertexElements = 3;
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, sizeOfVertexElements, GL_FLOAT, GL_FALSE, sizeof(float) * sizeOfVertexElements, 0);

	std::cout << glGetString(GL_VERSION) << std::endl;

	unsigned int program;
	Shader shader(&program, "../lib/shaders/basic.vs", "../lib/shaders/basic.fs");

	glUseProgram(program);

	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		double currentTime = glfwGetTime();

		/* Render here */
		glClearColor(
			(float)sin(currentTime) * 0.5f + 0.5f,
			(float)cos(currentTime) * 0.5f + 0.5f,
			0.0f,
			1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		// update shader uniform
		double greenValue = sin(currentTime) / 2.0f + 0.5f;
		int vertexColorLocation = glGetUniformLocation(program, "ourColor");
		glUniform4f(vertexColorLocation, 0.0f, (GLfloat)greenValue, 0.0f, 1.0f);

		glDrawArrays(GL_TRIANGLES, 0, sizeOfVertexElements);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}