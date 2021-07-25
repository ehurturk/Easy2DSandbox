#version 330 core

in vec2 o_uv;

out vec4 color;

uniform sampler2D tex;

void main() 
{
	color = texture(tex, o_uv);
	// color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}