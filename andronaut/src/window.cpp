#include "window.h"

Vec2i Window::size = Vec2i();
Vec2i Window::center = Vec2i();

Window::Window()
{
	m_is_open = false;
	m_window = nullptr;
	m_context = nullptr;
}

Window::~Window()
{
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

bool Window::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("SDL_Init Error: %s", SDL_GetError());
		return false;
	}
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	
	m_window = SDL_CreateWindow(
		nullptr, 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		640, 480, // Resolution is ignored on Android
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN
	);
	
	if (!m_window) {
		SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
		return false;
	}
	
	m_context = SDL_GL_CreateContext(m_window);
	if (!m_context) {
		SDL_Log("SDL_GL_CreateContext Error: %s", SDL_GetError());
		return false;
	}
	
	SDL_GL_MakeCurrent(m_window, m_context);
	
	SDL_DisplayMode display;
	SDL_GetCurrentDisplayMode(0, &display);
	size.x = display.w;
	size.y = display.h;
	center.x = size.x / 2;
	center.y = size.y / 2;
	
	glViewport(0, 0, size.x, size.y);
	SDL_GL_SetSwapInterval(0);
	
	m_is_open = true;
	
	return true;
}

void Window::Clear(Uint32 color)
{
	float red = (color >> 16) / 255.f;
	float green = (color >> 8 & 255) / 255.f;
	float blue = (color & 255) / 255.f;
	
	glClearColor(red, green, blue, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

