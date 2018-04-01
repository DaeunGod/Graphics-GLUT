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