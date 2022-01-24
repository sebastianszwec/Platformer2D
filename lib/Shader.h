#pragma once

#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Shader
{
public:
	Shader(unsigned int* shader, const std::string& vertexShader, const std::string& fragmentShader);
	void CreateShader(unsigned int* shader, const std::string& vertexShader, const std::string& fragmentShader);
private:
	unsigned int CompileShader(unsigned int shaderType, const std::string& source);
};

#endif // !SHADER_H_