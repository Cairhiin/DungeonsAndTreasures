#include "Player.h"

namespace DungeonDelvers {
	Player::Player(const std::string& name, const char* textureSheet, int ypos, int xpos)
		: name_(name), GameObject(textureSheet, ypos, xpos) {
	}
}