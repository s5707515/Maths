
#include "GCP_GFX_Framework.h"
#include "Sphere.h"
#include "RayTracer.h"
#include "Camera.h"
#include "Ray.h"

#include <vector>


//MADE IT TO SLIDE 12!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main(int argc, char* argv[])
{
	// Set window size
	glm::ivec2 winSize(640, 480);

	// This will handle rendering to screen
	GCP_Framework _myFramework;

	// Initialises SDL and OpenGL and sets up a framebuffer
	if (!_myFramework.Init(winSize))
	{
		return -1;
	}

	//Instantiate some sphere objects

	Sphere sphere1 = Sphere(glm::vec3(50, 50, 50), 40, glm::vec3(1, 0, 0));

	Sphere sphere2 = Sphere(glm::vec3(600, 250, 80), 60, glm::vec3(1, 1, 0));

	Sphere sphere3 = Sphere(glm::vec3(250, 400, 200), 40, glm::vec3(0, 0, 1));

	std::vector<Sphere> spheres = { sphere1, sphere2, sphere3 };

	//Instantiate Ray Tracer and Camera

	RayTracer rayTracer(spheres);

	Camera camera;

	glm::ivec2 pixelPos(0, 0);

	for (int y = 0; y < 480; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			pixelPos = glm::ivec2(x, y);

			Ray ray = camera.GetRay(pixelPos);

			glm::vec3 colour = rayTracer.TraceRay(ray);

			_myFramework.DrawPixel(pixelPos, colour);
		}
	}





	//// Preparing a position to draw a pixel
	//glm::ivec2 pixelPosition = winSize / 2;

	//// Preparing a colour to draw
	//// Colours are RGB, each value ranges between 0 and 1
	//glm::vec3 pixelColour(1, 0, 0);


	//// Sets all pixels the same colour
	//_myFramework.SetAllPixels( glm::vec3(0.1f,0.1f,0.3f) );

	//// Draws a single pixel
	//_myFramework.DrawPixel(pixelPosition, pixelColour);





	//// Pushes the framebuffer to OpenGL and renders to screen
	//// Also contains an event loop that keeps the window going until it's closed
	_myFramework.ShowAndHold();
	return 0;


}
