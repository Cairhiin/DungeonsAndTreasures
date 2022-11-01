#include "Game.h"

namespace DungeonDelvers {
	Game* game{ nullptr };

	const int FPS{ 60 };
	const int frameDelay{ 1000 / FPS };
	Uint32 frameStart;
	int frameTime;


	int main(int argc, const char* argv[]) {
		game = new Game();

		game->init("Dungeons and Treasures", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 800, false);

		while (game->running()) {

			frameStart = SDL_GetTicks();

			game->handleEvents();
			game->update();
			game->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
		}

		game->clean();

		return 0;
	}
}