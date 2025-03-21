#pragma once

#include "GCP_GFX_Framework.h"
#include "Sphere.h"
#include "Ray.h"
#include <vector>
#include <iostream>

class RayTracer
{
	private:

		std::vector<Sphere> listOfObjects;

	public:

		RayTracer(std::vector<Sphere> _objects) : listOfObjects(_objects) 
		{
			std::cout << "RayTracer CTOR called" << std::endl;
		}

		~RayTracer()
		{
			std::cout << "RayTracer DTOR called" << std::endl;
		}

		glm::vec3 TraceRay(Ray ray);


};