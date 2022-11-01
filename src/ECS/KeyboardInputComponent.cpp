#include "KeyboardInputComponent.h"

namespace DungeonDelvers {
    namespace ECS {
        void KeyboardInputComponent::init() {
            transform_ = &entity->GetComponent<TransformComponent>();
        }

        void KeyboardInputComponent::update() {
            if (Game::event.type == SDL_KEYDOWN) {
                /* Check the SDLKey values and change the velocity of the transform component */
                switch (Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    transform_->velocity.x = -1;
                    break;
                case SDLK_RIGHT:
                    transform_->velocity.x = 1;
                    break;
                case SDLK_UP:
                    transform_->velocity.y = -1;
                    break;
                case SDLK_DOWN:
                    transform_->velocity.y = 1;
                    break;
                default:
                    break;
                }
            }

            if (Game::event.type == SDL_KEYUP) {
                /* Check the SDLKey values and change the velocity of the transform component */
                switch (Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    transform_->velocity.x = 0;
                    break;
                case SDLK_RIGHT:
                    transform_->velocity.x = 0;
                    break;
                case SDLK_UP:
                    transform_->velocity.y = 0;
                    break;
                case SDLK_DOWN:
                    transform_->velocity.y = 0;
                    break;
                default:
                    break;
                }
            }
        }

    }
}