#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D user_texture;

void main()
{
	FragColor = texture(user_texture, TexCoord);
}
