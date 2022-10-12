/*
* GAMEOBJECT.H
*
* GameObject class takes a texture or texture sheet 
* as an old style C string, and an x and y of the 
* location of the texture on the texture sheet
* 
* Each GameObject has its own render and update method
* The class initializes an empty SDL_Rect source and destination
* rectangle by default
*/

#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject(const char *textureSheet, int x, int y);
	virtual ~GameObject() = default;

	void Update();
	void Render();

private:
	int xpos_;
	int ypos_;
	SDL_Texture* texture_;
	SDL_Rect srcRect_, destinationRect_;
};