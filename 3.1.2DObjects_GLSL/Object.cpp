#include "stdafx.h"

void Object::calcUniforMat4(glm::mat4 ViewProjectionMatrix) {
	glm::mat4 ModelMatrix;
	//glLoadIdentity();
	ModelMatrix = glm::translate(ModelMatrix, m_position);
	ModelMatrix = glm::scale(ModelMatrix, m_scale);
	ModelMatrix = glm::rotate(ModelMatrix, m_angle * TO_RADIAN, m_rotate);
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
}

bool Object::AABBIntersection(glm::vec4 v1, glm::vec4 v2) {
	if (v1.z < v2.x || v1.x > v2.z) return false;
	if (v1.w < v2.y || v1.y > v2.w) return false;

	return true;
}

void Object::heartFuncMotion() {
	float t = circularMotionAngle * TO_RADIAN;
	glm::vec3 pos = glm::vec3(16.0f * sinf(t)* sinf(t)* sinf(t),
		13 * cosf(t) - 5 * cosf(2 * t) - 2 * cosf(3 * t) - cosf(4 * t), 0.0f) * mHeartMotionSize;
	//printf("%f %f %f\n", m_position.x, m_position.y, m_angle);
	//pos.x += 100.0f;
	pos.y += 200.0f;

	setPosition(pos);
	circularMotionAngle += 1.0f;
	//m_angle = circularMotionAngle;
	if (circularMotionAngle >= 360) {
		circularMotionAngle -= 360;
		mHeartMotionSize -= 1.0f;
		if (mHeartMotionSize < 4.0f)
			mHeartMotionSize = 6.0f;
	}
}