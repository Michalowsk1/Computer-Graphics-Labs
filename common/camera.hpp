
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <common/maths.hpp>

class Camera
{
public:
	//projection parameters
	float fov = Maths::radians(45.0f);
	float aspect = 1024.0f / 768.0f;
	float near = 0.2f;
	float far = 100.0f;

	//camera vectors
	vec3 eye;
	vec3 target;
	vec3 worldUp = vec3(0.0f, 1.0f, 0.0f);

	//transformation matrices
	mat4 view;
	mat4 projection;

	//constructor
	Camera(const vec3 eye, const vec3 target);

	//methods
	void calculateMatrices();
};
