#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#undef main

/**
     * @brief A class that is used to run the game.
     *
     * Functions:
     *
     * A constructor that takes two arguments. The first parameter is
     * a boolean that is by default false, ie the game is not running.
     * The second parameter is a pointer to the SDL_Window and is set
     * by default to a nullptr, ie no window.
     *
     * init: a function that initializes the SDL window. It takes six
     * arguments and returns nothing.
     *  - a C style string that contains the title.
     *  - an int for the x position of the window.
     *  - an int for the y position of the window.
     *  - an int for the width of the window.
     *  - an int for the height of the window.
     *  - a boolean to determine whether the window should be fullscreen.
     *
     * handleEvents: a function that handles SDL events like keyboard
     * and takes no arguments and returns nothing.
     *
     * update: a function that handles updates to the game world and
     * takes no arguments and returns nothing.
     *
     * render: a function that renders the game's graphics and takes
     * no arguments and returns nothing.
     *
     * clean: a function that cleans up SDL and destroys the SDL window
     * and renderer. It takes no arguments and returns nothing.
     *
     * running: a getter function that returns the private variable
     * isRunning. It takes no arguments and returns a boolean.
     *
     * Copy and assignment are disabled, and a default destructor.
     *
     * Members:
     * A static SDL_Renderer that holds a pointer to the renderer object.
     * A static SDL_Event variable that holds the event object.
     * A private variable bool isRunning to determine whether the
     * game is still running.
     * A private SDL_Window variable that holds a pointer to the game
     * window.
     */
namespace DungeonDelvers {
    class Game {
    public:
        Game(bool isRunning = false, SDL_Window* window = nullptr);
        ~Game() = default;
        Game(const Game&) = delete; // disallow copying
        Game& operator=(const Game&) = delete; // disallow assign


        void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        bool running();

        static SDL_Renderer* renderer_;

    private:
        bool isRunning_;
        SDL_Window* window_;
        int cnt_;
    };
}
