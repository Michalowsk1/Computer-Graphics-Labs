#include <common/camera.hpp>

Camera::Camera(const vec3 Eye, const vec3 Target)
{
	eye = Eye;
	target = Target;
}

void Camera::calculateMatrices()
{
	//CALCULATE view matrix
	view = lookAt(eye, target, worldUp);

	//calculate projection matrix
	projection = perspective(fov, aspect, near, far);
}
