#pragma once
#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path);

	void init() override;
	void update() override;
	void draw() override;

private:
	PositionComponent* position_;
	SDL_Texture* texture_;
	SDL_Rect sourceRect_, destinationRect_;
};