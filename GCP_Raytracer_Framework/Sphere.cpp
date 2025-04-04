
#include "Sphere.h"


RayIntersection Sphere::RayIntersect(Ray ray) //FINDS THE CLOSEST POINT OF INTERSECTION 
{
	RayIntersection rayIntersect;
	//Check if the ray origin is inside the sphere

	if ((ray.origin.x < position.x + radius && ray.origin.x > position.x - radius) && (ray.origin.y < position.y + radius && ray.origin.y > position.y - radius))
	{
		rayIntersect.m_isIntersection = false;

		return rayIntersect;
	}

	//Calculate d

	glm::vec3 d = sqrt(position - ray.origin - (glm::dot((position - ray.origin), ray.direction) * ray.direction));

	//Calculate x

	glm::vec3 x = sqrt(radius * radius - d * d);

	//Calculate Closest Intersection
	
	glm::vec3 closestIntersection = ray.origin + ((glm::dot(position - ray.origin, ray.direction) - x) * ray.direction);

	//Check if intersection is in front or behind the rays origin 

	if (closestIntersection.x < ray.origin.x)
	{
		// if (p-a).n) is negative

		if (glm::dot((position - ray.origin), ray.direction) < 0)
		{
			rayIntersect.m_isIntersection = false;
			return rayIntersect;
		}
	}

	//IF THERE IS AN INTERSECTION

	rayIntersect.m_isIntersection = true;
	rayIntersect.m_closestIntersection = closestIntersection;

	return rayIntersect;

}


glm::vec3 Sphere :: GetNormal(glm::vec3 point)
{
	//Find vector between the point on the sphere and its centre
	glm::vec3 normal = point - position;

	//Normalise and return

	normal = glm::normalize(normal);

	return normal;
}


glm::vec3 Sphere :: Shade(glm::vec3 intersection)
{
	glm::vec3 surfaceNormal = GetNormal(intersection);

	glm::vec3 distantLight = glm::vec3(1,1,1);

	glm::vec3 lightColour = glm::vec3(0, 0, 0);


	glm::vec3 light = (glm::dot(distantLight, surfaceNormal) * lightColour * colour);

	return light;
}
