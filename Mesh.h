#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
class Vertex {
public:
    Vertex(const glm::vec3& pos,const glm::vec2& texCoord){
        this->pos = pos;
        this->texCoord = texCoord;
    };
    inline glm::vec3* GetPos() { return &pos; };
    inline glm::vec2* GetTexCoord() { return &texCoord; };
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
};
class Mesh {
public:
    Mesh(Vertex* vertices, unsigned int numvertices);
    ~Mesh();
    void Draw();
private:
    enum {
        POSITION_VB,
        TextCOORD_VB,
        NUM_BUFFERS
    };
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
    unsigned int m_drawCount;
};
