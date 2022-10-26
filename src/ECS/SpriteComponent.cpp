#include "SpriteComponent.h"
#include "../TextureManager.h"

SpriteComponent::SpriteComponent(const char* path) 
	: position_(), sourceRect_(), destinationRect_() {
	texture_ = TextureManager::LoadTexture(path);
}

void SpriteComponent::init() {
	position_ = &entity->GetComponent<PositionComponent>();
	sourceRect_.x = sourceRect_.y = 0;
	sourceRect_.w = sourceRect_.h = 128;
	destinationRect_.w = destinationRect_.h = 128;
}

void SpriteComponent::update() {
	destinationRect_.x = position_->x();
	destinationRect_.y = position_->y();
}

void SpriteComponent::draw() {
	TextureManager::Draw(texture_, sourceRect_, destinationRect_);
}