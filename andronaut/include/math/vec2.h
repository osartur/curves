#if not defined(ANUT_VEC2_H)
#define ANUT_VEC2_H

template <class T>
struct Vec2
{
	T x;
	T y;
	
	Vec2(T pos_x = 0, T pos_y = 0) {
		x = pos_x;
		y = pos_y;
	}
	
	Vec2<T> operator+(const Vec2<T>& other) const {
		return {x + other.x, y + other.y};
	}
	
	Vec2<T> operator-(const Vec2<T>& other) const {
		return {x - other.x, y - other.y};
	}
	
	Vec2<T> operator*(T scalar) const {
		return {x * scalar, y * scalar};
	}
	
	Vec2<T> operator/(T scalar) const {
		return {x / scalar, y / scalar};
	}
};

using Vec2f = Vec2<float>;
using Vec2i = Vec2<int>;

#endif