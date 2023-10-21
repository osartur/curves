#include "curves.h"
#include <cstdlib>

void Curves::Init()
{
	main_vert = new Vertex[TOTAL_VERTEXES];
	tmp_vert = new Vertex[TOTAL_VERTEXES];
	size = count = 0;
	
	InitPipeline();
}

void Curves::Update(float dt)
{
	if (input->FingerPressed(1))
	{
		int new_size = 2 * size - 2;
		if (new_size > TOTAL_VERTEXES)
			return;
		
		int next_size = 2 * new_size - 2;
		Color vert_color = next_size > TOTAL_VERTEXES ? Color(1.0f, 1.0f, 1.0f) : Color(1.0f, 1.0f, 0.0f);
		
		MakeCurves(vert_color);
		
		glBufferSubData(GL_ARRAY_BUFFER, 0, size * sizeof(Vertex), main_vert);
	}
	else if (input->FingerClick(0))
	{
		float x = (input->FingerX(0) - 0.5f) / 0.5f;
		float y = (0.5f - input->FingerY(0)) / 0.5f;
		main_vert[count] = {Vec2f(x, y), Color(1.0f, 1.0f, 1.0f)};
		
		glBufferSubData(GL_ARRAY_BUFFER, count * sizeof(Vertex), sizeof(Vertex), &main_vert[count]);
		
		count = (count + 1) % TOTAL_VERTEXES;
		if (size < TOTAL_VERTEXES)
			size++;
	}
}

void Curves::Draw()
{
	window->Clear(0x0F0F0F);
	glDrawArrays(GL_LINE_STRIP, 0, size);
}

int Curves::Finalize()
{
	delete[] tmp_vert;
	delete[] main_vert;
	glDeleteVertexArraysOES(1, &vao);
	glDeleteBuffers(1, &vbo);
	return 0;
}

void Curves::MakeCurves(const Color& vert_color)
{
	for (int i=0, j=0; i < size - 1; i++, j+=2)
	{
		tmp_vert[j].pos = main_vert[i].pos * 3.f/4.f + main_vert[i + 1].pos * 1.f/4.f;
		tmp_vert[j + 1].pos = main_vert[i].pos * 1.f/4.f + main_vert[i + 1].pos * 3.f/4.f;
		
		tmp_vert[j].color = vert_color;
		tmp_vert[j + 1].color = vert_color;
	}
	
	size = 2 * size - 2;
	count = size;
	std::swap(main_vert, tmp_vert);
}

void Curves::InitPipeline()
{
	if (!shader.Compile("shader/default_vert.glsl", "shader/default_frag.glsl"))
	{
		window->Close();
		return;
	}
	
	shader.Use();
	
	glGenVertexArraysOES(1, &vao);
	glBindVertexArrayOES(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, TOTAL_VERTEXES * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*) sizeof(Vec2f));
}
