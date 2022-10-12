/*
* TEXTUREMANAGER.H
* 
* Reponsible for loading a texture from a
* C style string file name
* Simplifies the assignment and deletion of
* an SDL surface to facilitate the texture
*/

#pragma once
#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
};

