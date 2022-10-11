#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *textureSheet, int x = 0, int y = 0) 
		:xpos_(x), ypos_(y) {
	srcRect_ = { };
	destinationRect_ = { };
	texture_ = TextureManager::LoadTexture(textureSheet);
}

void GameObject::Update() {
	++xpos_;
	++ypos_;

	srcRect_.h = 128;
	srcRect_.w = 128;
	srcRect_.x = 0;
	srcRect_.y = 0;

	destinationRect_.h = srcRect_.h;
	destinationRect_.w = srcRect_.w;
	destinationRect_.x = xpos_;
	destinationRect_.y = ypos_;
}
void GameObject::Render() {
	SDL_RenderCopy(Game::renderer_, texture_, &srcRect_, &destinationRect_);
}