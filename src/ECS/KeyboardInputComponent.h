#pragma once

#include "../Game.h"
#include "Components.h"

namespace DungeonDelvers {
    namespace ECS {
        class KeyboardInputComponent : public Component {
        public:
            KeyboardInputComponent() {}
            ~KeyboardInputComponent() = default;

            void init() override;
            void update() override;

        private:
            TransformComponent* transform_;
        };
    }
}