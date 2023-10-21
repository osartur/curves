#if not defined(ANUT_FINGER_H)
#define ANUT_FINGER_H
#include <SDL2/SDL.h>
#include "math/vec2.h"
#include "math/timer.h"

class Finger
{
public:
	Finger();
	
	Vec2f GetPos() const;
	float GetX() const;
	float GetY() const;
	
	bool IsDown() const;
	bool IsUp() const;
	bool Pressed();
	bool Clicked(float interval = 0.4f);
	
	void FingerProc(SDL_Event* ev);
	
private:
	Vec2f m_position;
	bool m_is_down;
	bool m_pressed;
	Timer m_press_counter;
	bool m_stopped;
	float m_press_elapsed;
};


inline Vec2f Finger::GetPos() const {
	return m_position;
}

inline float Finger::GetX() const {
	return m_position.x;
}

inline float Finger::GetY() const {
	return m_position.y;
}

inline bool Finger::IsDown() const {
	return m_is_down;
}

inline bool Finger::IsUp() const {
	return !m_is_down;
}

#endif
