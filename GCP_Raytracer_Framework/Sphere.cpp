
#include "Sphere.h"


bool Sphere::RayIntersect(Ray ray)
{
	

	//Check if the ray origin is inside the sphere

	if ((ray.origin.x < position.x + radius && ray.origin.x > position.x - radius) && (ray.origin.y < position.y + radius && ray.origin.y > position.y - radius))
	{
		
	}

	//Calculate d

	glm::vec3 d = sqrt(position - ray.origin - (glm::dot((position - ray.origin), ray.direction) * ray.direction));

	//Calculate x

	glm::vec3 x = sqrt(radius * radius - d * d);

	//Calculate Closest Intersection
	
	glm::vec3 closestIntersection = ray.origin + ((glm::dot(position - ray.origin, ray.direction) - x) * ray.direction);

	//Check if intersection is in front or behind the rays origin / direction

	if (closestIntersection.x < ray.origin.x)
	{
		return false;
	}

}

