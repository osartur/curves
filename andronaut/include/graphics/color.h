#if not defined(ANUT_COLOR_H)
#define ANUT_COLOR_H

struct Color
{
	float r;
	float g;
	float b;
	float a;
	
	Color(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f)
	{
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}
};

#endif