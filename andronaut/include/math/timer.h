#if not defined(ANUT_TIMER_H)
#define ANUT_TIMER_H
#include <chrono>

using std::chrono::high_resolution_clock;

class Timer
{
public:
	Timer();
	virtual ~Timer() = default;
	
	void Start();
	void Pause();
	float Restart();
	float Elapsed() const;
	bool Elapsed(float secs) const;
	bool IsPaused() const;
	
private:
	high_resolution_clock::time_point m_start;
	high_resolution_clock::time_point m_end;
	bool m_paused;
	
	static high_resolution_clock::time_point Now();
};


inline bool Timer::IsPaused() const {
	return m_paused;
}

inline high_resolution_clock::time_point Timer::Now() {
	return high_resolution_clock::now();
}

#endif
