#pragma once


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/gtc/matrix_transform.hpp>

class Object {
protected:
	glm::vec3 m_position;
	glm::vec3 m_scale;
	glm::vec2 m_winSize;
	glm::vec3 m_rotate;
	float m_angle;
	//glm::mat4 ModelMatrix;
	glm::mat4 ModelViewProjectionMatrix;

	GLint loc_ModelViewProjectionMatrix;
	GLint loc_primitive_color;

	void calcUniforMat4(glm::mat4 ViewProjectionMatrix);

public:
	void setWinSize(glm::vec2 newWinSize){ m_winSize = newWinSize; }
	void setPosition(glm::vec3 newPosition) { m_position = newPosition; }
	void setScale(glm::vec3 newScale) { m_scale = newScale; }
	void setScale(float newScale) { m_scale = glm::vec3(newScale, newScale, 0.0f); }
	const glm::vec3 getScale() { return m_scale; }
	const glm::vec3 getPosition() { return m_position;  }
	const glm::mat4 getPositionMat4() {
		glm::mat4 ModelMatrix;
		ModelMatrix = glm::translate(ModelMatrix, m_position);
		ModelMatrix = glm::scale(ModelMatrix, m_scale);
		return ModelMatrix;
	}
	void setRotate(float newAngle, glm::vec3 newRotate = glm::vec3(0.0f, 0.0f, 1.0f)) { m_angle = newAngle;  m_rotate = newRotate; }
	const glm::vec3 getRotate() { return m_rotate; }

public:
	Object(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		loc_ModelViewProjectionMatrix(_loc_ModelViewProjectionMatrix), loc_primitive_color(_loc_primitive_color) {
		//ModelMatrix = glm::mat4(1.0f);
		m_position = glm::vec3(0.0f, 0.0f, 0.0f);
		m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
		m_winSize = glm::vec2(0.0f, 0.0f);
		m_angle = 0;
		m_rotate = glm::vec3(0.0f, 0.0f, 1.0f);
	}

public:

	virtual void initObject() = 0;
	virtual void drawObject(glm::mat4 ViewProjectionMatrix) = 0;
	virtual void updateObjcet() = 0;
	virtual void cleanup() = 0;

};