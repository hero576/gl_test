#pragma once
#include <iostream>
#include <string>
#include <gl/glew.h>
#include "Transform.h"
using namespace std;
class Shader {
public:
	Shader(const string& filename);
	~Shader();
	void Bind();
	void Update(const Transform& transform);
private:
	enum {
		TRANSFROM_U,
		NUM_UNIFORM,
	};
	static const unsigned int NUM_SHADER = 2;
	GLuint m_pramram;
	GLuint m_shaders[NUM_SHADER];
	GLuint m_unifroms[NUM_UNIFORM];
};