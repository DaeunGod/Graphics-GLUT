#pragma once

#include "stdafx.h"

class axesClass : public Object
{
private:
	GLfloat axes[4][2];
	GLfloat axes_color[3];
	GLuint VBO_axes, VAO_axes;

public:
	axesClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {
		axes_color[0] = 0.0f;
		axes_color[1] = 0.0f;
		axes_color[2] = 0.0f;
	}
	~axesClass() {

	}


	virtual void initObject();
	void initObject(int win_width, int win_height);
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

