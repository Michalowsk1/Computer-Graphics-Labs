#version 330 core

//inputs
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;

//outputs
out vec2 UV;

void main()
{
    // Output vertex position
    gl_Position = vec4(position, 1.0);

    //output texture coordinates
    UV = uv;
}
