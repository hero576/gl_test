#pragma once
#include <iostream>
#include <string>
#include <gl/glew.h>
using namespace std;
class Shader {
public:
	Shader(const string& filename);
	~Shader();
	void Bind();
private:
	static const unsigned int NUM_SHADER = 2;
	GLuint m_pramram;
	GLuint m_shaders[NUM_SHADER];
};