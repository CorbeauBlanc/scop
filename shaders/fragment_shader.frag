#version 450

in vec4 fragmentColor;

out vec4 color;

void main(void)
{
	//color = debugColor;
	color = fragmentColor;
}
