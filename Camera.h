#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;

class Camera {
public:
	Camera(const vec3& pos, float fov, float aspect, float zNear, float zFar) {
		this->pos = pos;
		this->forward = vec3(0., 0., 1.);
		this->up = vec3(0., 1., 1.);
		this->projection = perspective(fov, aspect, zNear, zFar);
	};
	~Camera() {};
	inline mat4 GetViewProjection() const {
		return projection*lookAt(pos, pos + forward, up);
	}
private:
	mat4 projection;
	vec3 pos, forward, up;
};