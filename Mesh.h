#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include<string>
#include "obj_loader.h"
using namespace std;
using namespace glm;
class Vertex {
public:
    Vertex(const vec3& pos,const vec2& texCoord,const vec3 normal=vec3()){
        this->pos = pos;
        this->texCoord = texCoord;
        this->normal = normal;
    };
    inline vec3* GetPos() { return &pos; };
    inline vec2* GetTexCoord() { return &texCoord; };
    inline vec3* GetNormal() { return &normal; };
private:
    vec3 pos;
    vec2 texCoord;
    vec3 normal;
};
class Mesh {
public:
    Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
    Mesh(const string& filename);
    ~Mesh();
    void Draw();
private:
    enum {
        POSITION_VB,
        TextCOORD_VB,
        NORMAL_VB,
        INDEX_VB,
        NUM_BUFFERS
    };
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
    unsigned int m_drawCount;
    void InitMesh(const IndexedModel& model);
};
