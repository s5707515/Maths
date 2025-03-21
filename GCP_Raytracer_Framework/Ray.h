#pragma once

#include "GCP_GFX_Framework.h"

class Ray
{
	public:

		glm::vec3 origin;

		glm::vec3 direction;


		Ray(glm::vec3 _origin, glm::vec3 _direction) : origin(_origin), direction(_direction)
		{
			std::cout << "Ray CTOR called";
		}

		~Ray()
		{
			std::cout << "Ray DTOR called";
		}
			
};

