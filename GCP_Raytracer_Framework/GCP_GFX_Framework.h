#pragma once


#include <SDL/SDL.h>


#include <iostream>
#include <string>
#include <fstream>

#include <GLM/glm.hpp>

// Forward declaration of internal utility class to handle framebuffer functionality
class Framebuffer;

// Main interface for the framework
// Must call Init() before other functions
class GCP_Framework
{
public:

	~GCP_Framework();

	// Must call Init after creation
	// Sets up SDL, OpenGL and the internal framebuffer
	bool Init( glm::ivec2 screenSize );

	// Set all pixels to the same colour
	// Colour is RGB, each must range from 0 to 1
	void SetAllPixels( glm::vec3 pixelColour );

	// Set a single pixel to the specified colour
	// Colour is RGB, each must range from 0 to 1
	void DrawPixel(glm::ivec2 pixelPosition, glm::vec3 pixelColour);

	// Sends framebuffer to OpenGL and displays to screen
	// Will return when user closes the window
	// SDL is uninitialised, you are expected to exit the program
	void ShowAndHold();

protected:

	// Internal variables
		Framebuffer* _mainBuffer = nullptr;
		glm::ivec2 _screenSize;

	// SDL variables
		SDL_Window* _SDLwindow = nullptr;
		SDL_GLContext _SDLglcontext;

	// OpenGL drawing variables
		unsigned int _triangleVAO = 0;
		unsigned int _shaderProgram = 0;

};

