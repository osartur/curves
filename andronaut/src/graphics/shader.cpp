#include "graphics/shader.h"
#include <fstream>

Shader::Shader()
{
	m_glsl_message = nullptr;
	m_vertex_object = 0;
	m_fragment_object = 0;
	m_program = 0;
}

Shader::~Shader()
{
	if (m_program != 0) {
		glDeleteProgram(m_program);
	}
	
	if (m_vertex_object != 0) {
		glDeleteShader(m_vertex_object);
	}
	
	if (m_fragment_object != 0) {
		glDeleteShader(m_fragment_object);
	}
}

bool Shader::Compile(const char* vertex_filename, const char* fragment_filename)
{
	m_vertex_object = glCreateShader(GL_VERTEX_SHADER);
	m_fragment_object = glCreateShader(GL_FRAGMENT_SHADER);
	m_program = glCreateProgram();
	
	glAttachShader(m_program, m_vertex_object);
	glAttachShader(m_program, m_fragment_object);
	
	std::string vertex_src = GetFileContents(vertex_filename);
	std::string fragment_src = GetFileContents(fragment_filename);
	bool vert_success = CompileShader(m_vertex_object, vertex_src.c_str());
	bool frag_success = CompileShader(m_fragment_object, fragment_src.c_str());
	
	if (!vert_success) {
		SDL_Log("VERTEX_SHADER_ERROR:\n%s\n", GetCompilerMessage(m_vertex_object));
		delete[] m_glsl_message;
	}
	
	if (!frag_success) {
		SDL_Log("FRAGMENT_SHADER_ERROR:\n%s\n", GetCompilerMessage(m_fragment_object));
		delete[] m_glsl_message;
	}
	
	if (!vert_success || !frag_success) {
		return false;
	}
	
	if (!LinkProgram()) {
		SDL_Log("LINK_ERROR:\n%s\n", GetLinkerMessage());
		delete[] m_glsl_message;
		return false;
	}
	
	return true;
}

std::string Shader::GetFileContents(const char* filename)
{
	std::ifstream file{filename};
	std::string line, content;
	while (std::getline(file, line)) {
		content += line + '\n';
	}
	return content;
}

bool Shader::CompileShader(GLuint shader_obj, const char* shader_src)
{
	glShaderSource(shader_obj, 1, &shader_src, nullptr);
	glCompileShader(shader_obj);
	GLint compile_status;
	glGetShaderiv(shader_obj, GL_COMPILE_STATUS, &compile_status);
	return compile_status == GL_TRUE;
}

bool Shader::LinkProgram()
{
	glLinkProgram(m_program);
	GLint link_status;
	glGetProgramiv(m_program, GL_LINK_STATUS, &link_status);
	return link_status == GL_TRUE;
}

const char* Shader::GetCompilerMessage(GLuint shader_obj)
{
	GLint length;
	glGetShaderiv(shader_obj, GL_INFO_LOG_LENGTH, &length);
	m_glsl_message = new char[length + 1];
	glGetShaderInfoLog(shader_obj, length, nullptr, m_glsl_message);
	return m_glsl_message;
}

const char* Shader::GetLinkerMessage()
{
	GLint length;
	glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &length);
	m_glsl_message = new char[length + 1];
	glGetProgramInfoLog(m_program, length, nullptr, m_glsl_message);
	return m_glsl_message;
}
