#include <common/camera.hpp>

Camera::Camera(const vec3 Eye, const vec3 Target)
{
	eye = Eye;
	target = Target;
}

void Camera::calculateMatrices()
{
	// Calculate camera vectors
	calculateCameraVectors();

	//CALCULATE view matrix
	view = lookAt(eye, eye + front, worldUp);

	//calculate projection matrix
	projection = perspective(fov, aspect, near, far);
}

void Camera::calculateCameraVectors()
{
	front = glm::vec3(cos(yaw) * cos(pitch), sin(pitch), sin(yaw) * cos(pitch));
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::cross(right, front);
}
