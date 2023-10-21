#include "finger.h"

Finger::Finger()
{
	m_stopped = false;
	m_is_down = false;
	m_pressed = false;
}

bool Finger::Pressed()
{
	if (m_pressed) {
		m_pressed = false;
		return true;
	}
	return false;
}

bool Finger::Clicked(float interval)
{
	if (m_stopped && m_press_elapsed <= interval) {
		m_stopped = false;
		return true;
	}
	return false;
}

void Finger::FingerProc(SDL_Event* ev)
{
	switch (ev->type) {
		case SDL_FINGERDOWN:
			m_press_counter.Start();
			m_stopped = false;
			m_is_down = m_pressed = true;
			
		case SDL_FINGERMOTION:
			m_position.x = ev->tfinger.x;
			m_position.y = ev->tfinger.y;
			break;
			
		case SDL_FINGERUP:
			m_press_elapsed = m_press_counter.Elapsed();
			m_stopped = true;
			m_is_down = m_pressed = false;
			break;
	}
}

