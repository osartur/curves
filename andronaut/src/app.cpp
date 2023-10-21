#include "app.h"
#include "window.h"
#include "renderer.h"
#include "input.h"
#include "engine.h"

Window   * App::window = nullptr;
Input    * App::input = nullptr;
Renderer * App::renderer = nullptr;

App::App()
{
	window = Engine::window;
	input = Engine::input;
	renderer = Engine::renderer;
}

