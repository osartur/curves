#if not defined(ANUT_WINDOW_H)
#define ANUT_WINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>
#include "math/vec2.h"

class Window
{
public:
	Window();
	virtual ~Window();
	
	bool Initialize();
	
	static int GetWidth();
	static int GetHeight();
	static int GetCenterX();
	static int GetCenterY();
	
	bool IsOpen() const;
	void Close();
	
	void Display();
	void Clear(Uint32 color = 0x0);
	
private:
	SDL_Window* m_window;
	SDL_GLContext m_context;
	bool m_is_open;
	
	static Vec2i size;
	static Vec2i center;
};


inline int Window::GetWidth() {
	return Window::size.x;
}

inline int Window::GetHeight() {
	return Window::size.y;
}

inline int Window::GetCenterX() {
	return Window::center.x;
}

inline int Window::GetCenterY() {
	return Window::center.y;
}

inline bool Window::IsOpen() const {
	return m_is_open;
}

inline void Window::Close() {
	m_is_open = false;
}

inline void Window::Display() {
	SDL_GL_SwapWindow(m_window);
}

#endif