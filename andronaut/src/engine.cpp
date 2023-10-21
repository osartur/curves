#include "engine.h"
#include "window.h"
#include "renderer.h"
#include "input.h"
#include "app.h"

void    (* Engine::win_proc)(SDL_Event*) = nullptr;
Window   * Engine::window = nullptr;
Renderer * Engine::renderer = nullptr;
Input    * Engine::input = nullptr;
Timer    * Engine::timer = nullptr;
bool       Engine::paused = false;

Engine::Engine()
{
	window = new Window;
	renderer = new Renderer;
	input = new Input;
	timer = new Timer;
}

Engine::~Engine()
{
	delete window;
	delete renderer;
	delete input;
	delete timer;
}

int Engine::Start(App* application)
{
	if (!window->Initialize()) {
		return -1;
	}
	
	m_app = application;
	m_app->Init();
	Loop();
	return m_app->Finalize();
}

void Engine::Loop()
{
	timer->Start();
	
	while (window->IsOpen()) {
		if (win_proc != nullptr) {
			SDL_Event ev;
			while (SDL_PollEvent(&ev)) {
				if (ev.type == SDL_QUIT)
					return;
				win_proc(&ev);
			}
		}
		
		if (!paused) {
			window->Clear(0x0);
			m_app->Draw();
			window->Display();
			m_app->Update(timer->Restart());
		}
		else {
			m_app->OnPause();
		}
	}
}
