#version 450 core

layout(location = 0) out vec4 color;

uniform vec4 ourColor;

void main()
{
   color = ourColor;
};