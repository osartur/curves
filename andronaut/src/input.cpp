#include "input.h"
#include "engine.h"

Finger Input::fingers[10] = {};

Input::Input()
{
	Engine::win_proc = InputProc;
}

Input::~Input()
{
	Engine::win_proc = nullptr;
}

void Input::InputProc(SDL_Event* ev)
{
	switch (ev->type) {
		case SDL_FINGERDOWN:
		case SDL_FINGERUP:
		case SDL_FINGERMOTION:
			fingers[ev->tfinger.fingerId].FingerProc(ev);
			return;
	}
}
