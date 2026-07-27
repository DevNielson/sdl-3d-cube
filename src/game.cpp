#include "game.hpp"

namespace Game
{
	void Init()
	{
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			const std::string ERROR { std::format("Error initialize SDL3: {}", SDL_GetError()) };
			throw std::runtime_error(ERROR);
		}

		window = SDL_CreateWindow(WINDOW_TITLE.c_str(), WINDOW_WIDTH, WINDOW_HEIGHT, 0);
		if (!window)
		{
			const std::string ERROR { std::format("Error creating window: {}", SDL_GetError()) };
			throw std::runtime_error(ERROR);
		}

		renderer = SDL_CreateRenderer(window, nullptr);
		if (!renderer)
		{
			const std::string ERROR { std::format("Error creating renderer: {}", SDL_GetError()) };
			throw std::runtime_error(ERROR);
		}
	}

	void Run()
	{
		while (isRunning)
		{
			Events();
		}
	}

	void Events()
	{
		while (SDL_PollEvent(&testEvent))
		{
			switch (testEvent.type)
			{
				case SDL_EVENT_QUIT:
					isRunning = false;
					break;
				default:
					break;
			}
		}
	}
}
