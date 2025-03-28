#pragma once

#include "GCP_GFX_Framework.h"
#include "Ray.h"

#include <iostream>



class Sphere
{
	private:
		
		glm::vec3 position;

		float radius;

		glm::vec3 colour;

	public:

		Sphere(glm::vec3 _pos, float _radius, glm::vec3 _colour) : position(_pos), radius(_radius), colour(_colour)
		{
			std::cout << "Sphere CTOR called" << std::endl;
		}

		~Sphere()
		{
			std::cout << "Sphere DTOR called" << std::endl;
		}

		bool RayIntersect(Ray ray);

		glm::vec3 Shade(glm::vec3 intersection);

		glm::vec3 GetNormal(glm::vec3 point);
		

};
