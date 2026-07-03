#include "main.hpp"

namespace Game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	void Init();

	bool isRunning { true };
	void Run();

	SDL_Event testEvent {};
	void Events();
}