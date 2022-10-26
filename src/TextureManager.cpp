#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	SDL_Surface* tempSurface{ IMG_Load(texture) };
	SDL_Texture* tex{ SDL_CreateTextureFromSurface(Game::renderer_, tempSurface) };
	SDL_FreeSurface(tempSurface);

	if (!tex) std::cerr << "[ERROR] FAILED TO LOAD TEXTURE: " << texture << std::endl;
	return tex;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect) {
	SDL_RenderCopy(Game::renderer_, texture, &sourceRect, &destinationRect);
}