#if not defined(ANUT_SHADER_H)
#define ANUT_SHADER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>
#include <string>

class Shader
{
public:
	Shader();
	virtual ~Shader();
	
	bool Compile(const char* vertex_filename, const char* fragment_filename);
	
	void Use() const;
	
private:
	GLuint m_program;
	GLuint m_vertex_object;
	GLuint m_fragment_object;
	char* m_glsl_message;
	
	std::string GetFileContents(const char* filename);
	
	bool CompileShader(GLuint shader_obj, const char* shader_src);
	bool LinkProgram();
	const char* GetCompilerMessage(GLuint shader_obj);
	const char* GetLinkerMessage();
};


inline void Shader::Use() const {
	glUseProgram(m_program);
}

#endif