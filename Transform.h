#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;

class Transform {
public:
	Transform(const vec3& pos = vec3(),
		const vec3& rot = vec3(),
		const vec3& scale = vec3(1., 1., 1.)):pos(pos),rot(rot),scale(scale) {};
	~Transform() {};
	inline vec3* GetPos() { return &pos; };
	inline vec3* GetRot() { return &rot; };
	inline vec3* GetScale() { return &scale; };

	inline void SetPos(vec3& pos) { this->pos = pos; };
	inline void SetRot(vec3& rot) { this->rot = rot; };
	inline void SetScale(vec3& scale) { this->pos = scale; };

	inline mat4 GetModel()const {
		mat4 posMat = translate(pos);
		mat4 rotX = rotate(rot.x, vec3(1., 0., 0.));
		mat4 rotY = rotate(rot.y, vec3(0., 1., 0.));
		mat4 rotZ = rotate(rot.z, vec3(0., 0., 1.));
		mat4 rotMat = rotX * rotY * rotZ;
		mat4 scaleMat = glm::scale (scale);
		return posMat * scaleMat * rotMat;
	};
private:
	vec3 pos,rot,scale;
};



