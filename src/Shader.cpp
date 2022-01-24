#pragma once

#include "../lib/Shader.h"

Shader::Shader(unsigned int* shader, const std::string& vertexShader, const std::string& fragmentShader)
{
    Shader::CreateShader(shader, vertexShader, fragmentShader);
}

unsigned int Shader::CompileShader(unsigned int shaderType, const std::string& source)
{
    unsigned int id = glCreateShader(shaderType);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result); //iv : i - integer, v - vector

    return id;
}

void Shader::CreateShader(unsigned int* shader, const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
    unsigned int vsCompiled = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fsCompiled = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vsCompiled);
    glAttachShader(program, fsCompiled);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vsCompiled);
    glDeleteShader(fsCompiled);

    program = *shader;
}