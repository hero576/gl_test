#pragma once
#include <string>
#include <gl/glew.h>
using namespace std;
class Texture {
public:
	Texture(const string& filename);
	~Texture();
	void Bind();
private:
	GLuint m_texture;
};