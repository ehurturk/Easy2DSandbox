#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv;

uniform mat4 ez_Projection;
uniform mat4 ez_Model;
uniform mat4 ez_View;


out vec2 o_uv;

void main()
{
	gl_Position = ez_Projection * ez_View * ez_Model * vec4(pos, 1.0f); /* need to have 1.0 as homogenous coordinate */
	o_uv = uv;
}