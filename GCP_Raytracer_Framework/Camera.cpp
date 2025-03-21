#include "Camera.h"

Ray Camera::GetRay(glm::ivec2 windowPos)
{
	Ray ray(glm::vec3(windowPos.x, windowPos.y, 0), glm::vec3(0, 0, -1));

	return ray;
}