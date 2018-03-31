#pragma once


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/gtc/matrix_transform.hpp>

class Object {
protected:
	glm::vec3 m_position;
	glm::vec2 m_winSize;

	GLint loc_ModelViewProjectionMatrix;
	GLint loc_primitive_color;

public:
	void setWinSize(glm::vec2 newWinSize){ m_winSize = newWinSize; }

public:
	Object(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		loc_ModelViewProjectionMatrix(_loc_ModelViewProjectionMatrix), loc_primitive_color(_loc_primitive_color) {
	}

public:

	virtual void initObject() = 0;
	virtual void drawObject() = 0;
	virtual void updateObjcet() = 0;
	virtual void cleanup() = 0;

};