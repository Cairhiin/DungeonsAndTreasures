/*
* PLAYER.H
* 
* Player class extends the GameObject class
* It needs fleshing out further in the future!
*/

#include "GameObject.h"

class Player : public GameObject {
public:
	Player(const std::string& name, const char *textureSheet, int ypos, int xpos);
	virtual ~Player() {};

private:
	const std::string name_;
};