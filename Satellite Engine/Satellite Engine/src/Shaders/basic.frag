#version 330 core

// Where the variable's location is
// We set location to 0 so that we can actually pass an attribute to the shader
layout (location = 0) out vec4 color;

uniform vec4 colour;
uniform vec2 light_pos;

in vec4 pos;

void main()
{
	float intensity = 1.0 / length(pos.xy - light_pos);
	color = colour * intensity;
}