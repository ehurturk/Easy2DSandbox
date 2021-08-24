#version 330 core

in vec2 o_uv;

out vec4 color;

uniform sampler2D tex;

void main() 
{
	vec4 t_color = texture(tex, o_uv);
	if (t_color.a < 0.1)
		discard;
	color = t_color;
	// color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}