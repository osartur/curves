#if not defined(ANUT_ENGINE_H)
#define ANUT_ENGINE_H
#include <SDL2/SDL.h>
#include "math/timer.h"

class App;
class Window;
class Renderer;
class Input;

class Engine
{
public:
	static Window* window;
	static Renderer* renderer;
	static Input* input;
	static void (*win_proc)(SDL_Event*);
	
	Engine();
	virtual ~Engine();
	
	int Start(App* application);
	
	static void Pause();
	static void Resume();
	
private:
	static bool paused;
	static Timer* timer;
	App* m_app;
	
	void Loop();
};

inline void Engine::Pause() {
	timer->Pause();
	paused = true;
}

inline void Engine::Resume() {
	paused = false;
}

#endif