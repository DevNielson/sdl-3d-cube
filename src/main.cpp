#include <SDL3/SDL_main.h>

#include "cube.hpp"
#include "object.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (!SDL_Init(SDL_INIT_VIDEO)) { throw std::string(std::format("Error initialize SDL3: {}", SDL_GetError())); }

		SDL_Window *window { SDL_CreateWindow(WINDOW_TITLE.c_str(), WINDOW_WIDTH, WINDOW_HEIGHT, 0) };
		if (!window) { throw std::string(std::format("Error creating window: {}", SDL_GetError())); }

		SDL_Renderer *renderer { SDL_CreateRenderer(window, nullptr) };
		if (!renderer) { throw std::string(std::format("Error creating renderer: {}", SDL_GetError())); }

		Object2d objectProjected { { {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} } };
		Object cube(object, objectProjected);

		bool isRunning { true };
		while (isRunning)
		{
			SDL_Event testEvent {};
			while (SDL_PollEvent(&testEvent))
			{
				switch (testEvent.type)
				{
					case SDL_EVENT_QUIT:
						isRunning = false;
						break;
					case SDL_EVENT_KEY_DOWN:
						cube.update();
						cube.coordinatesLog();
						break;
					default:
						break;
				}
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderClear(renderer);

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				cube.renderObject(renderer);

				SDL_RenderPresent(renderer);
			}
		}
	}
	catch (std::string e)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", e.c_str(), nullptr);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
