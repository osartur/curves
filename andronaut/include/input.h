#if not defined(ANUT_INPUT_H)
#define ANUT_INPUT_H
#include <SDL2/SDL.h>
#include "finger.h"

class Input
{
public:
	Input();
	virtual ~Input();
	
	float FingerX(int id);
	float FingerY(int id);
	
	bool FingerDown(int id);
	bool FingerUp(int id);
	bool FingerPressed(int id);
	bool FingerClick(int id, float interval = 0.4f);
	
private:
	static Finger fingers[10];
	static void InputProc(SDL_Event* ev);
};


inline float Input::FingerX(int id) {
	return fingers[id].GetX();
}

inline float Input::FingerY(int id) {
	return fingers[id].GetY();
}

inline bool Input::FingerDown(int id) {
	return fingers[id].IsDown();
}

inline bool Input::FingerUp(int id) {
	return fingers[id].IsUp();
}

inline bool Input::FingerPressed(int id) {
	return fingers[id].Pressed();
}

inline bool Input::FingerClick(int id, float interval) {
	return fingers[id].Clicked(interval);
}

#endif
