#pragma once

#include "GCP_GFX_Framework.h"
#include "Ray.h"

#include <iostream>

class Camera
{
	//private:

		//glm::mat4 viewMat1;

		//glm::mat4 viewMat2;

		//glm::mat4 viewMat3;

	public:

		Camera()
		{
			std::cout << "Camera CTOR called" << std::endl;
		}

		~Camera()
		{
			std::cout << "Camera DTOR called" << std::endl;
		}

		Ray GetRay(glm::ivec2 windowPos);

	
		
};
