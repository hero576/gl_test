#include "shader.h"
#include <fstream>


static void CheckShaderError(GLuint shader, GLuint flag, bool isprogram, const string& errorMessage);
static string LoadShader(const string& filename);
static GLuint CreateShader(const string& text, GLenum shaderType);

Shader::Shader(const string& filename) {
	m_pramram = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(filename + ".vs"),GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(filename + ".fs"),GL_FRAGMENT_SHADER);
	for (unsigned int i = 0; i < NUM_SHADER; i++) {
		glAttachShader(m_pramram, m_shaders[i]);
	}
	glBindAttribLocation(m_pramram, 0, "position");
	glBindAttribLocation(m_pramram, 1, "texCoord");
	glLinkProgram(m_pramram);
	CheckShaderError(m_pramram, GL_LINK_STATUS, true, "Error:Progma Linking invalid");
	glValidateProgram(m_pramram);
	CheckShaderError(m_pramram, GL_VALIDATE_STATUS, true, "Error:Progma Validate invalid");
}
Shader::~Shader() {
	for (unsigned int i = 0; i < NUM_SHADER; i++) {
		glDetachShader(m_pramram, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	glDeleteProgram(m_pramram);
}

void Shader::Bind() {
	glUseProgram(m_pramram);
}
static void CheckShaderError(GLuint shader, GLuint flag, bool isprogram, const string& errorMessage) {
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isprogram) {
		glGetProgramiv(shader, flag, &success);
	}
	else {
		glGetShaderiv(shader, flag, &success);
	}
	if (success == GL_FALSE) {
		if (isprogram) {
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		}
		else {
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}
		cerr << errorMessage << ":'" << error << "'" << endl;
	}
}
static string LoadShader(const string& filename) {
	ifstream file;
	file.open((filename).c_str());

	string output, line;
	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		cerr << "Unable to load shader:" << filename << endl;
	}
	return output;
}
static GLuint CreateShader(const string& text, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);
	if (shader == 0) {
		cerr << "Error: Shader create failure" << endl;
	}
	const GLchar* shaderSourceString[1];
	GLint shaderSourceStringLength[1];
	shaderSourceString[0] = text.c_str();
	shaderSourceStringLength[0] = text.length();
	glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLength);
	glCompileShader(shader);
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error:shader compile failed");
	return shader;
}
