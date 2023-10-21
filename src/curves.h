#ifndef CURVES_APP_H
#define CURVES_APP_H
#include "anut.h"

class Curves : public App
{
public:
	void Init() override;
	void Update(float dt) override;
	void Draw() override;
	int Finalize() override;
	
private:
	Shader shader;
	GLuint vao;
	GLuint vbo;
	const int TOTAL_VERTEXES = 1024;
	Vertex* main_vert;
	Vertex* tmp_vert;
	int count;
	int size;
	
	void InitPipeline();
	void MakeCurves(const Color& vert_color);
};

#endif