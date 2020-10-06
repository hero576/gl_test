#include <iostream>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"
#include "texture.h"
#include "Transform.h"
using namespace std;
#undef main
int main(int argc, char** argv) {
    Display display(800, 600, "gl title");
    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5,-0.5,0),glm::vec2(0.,0.)),
        Vertex(glm::vec3(0,0.5,0),glm::vec2(0.5,1.)),
        Vertex(glm::vec3(0.5,-0.5,0),glm::vec2(1.,0.)),
    };
    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    Shader shader("./res/basicShader");
    Texture texture("./res/brick.jfif");
    Transform transform;
    float counter = 0.;
    while (!display.IsClosed()) {
        display.Clear(0., 0.15, 0.3, 1.);
        float sinCounter = sinf(counter);
        transform.GetPos()->x = sinCounter;
        shader.Bind();
        texture.Bind();
        shader.Update(transform);
        mesh.Draw();
        display.Update();
        counter += 0.001f;
    }
    return 0;
}
