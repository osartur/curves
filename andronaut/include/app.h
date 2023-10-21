#if not defined(ANUT_APP_H)
#define ANUT_APP_H
#include <SDL2/SDL.h>

class Window;
class Renderer;
class Input;

class App
{
public:
	static Window* window;
	static Input* input;
	static Renderer* renderer;
	
	App();
	virtual ~App() = default;
	
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual int Finalize() = 0;
	
	virtual void OnPause() {}
	virtual void Draw() {}
};

#endif
