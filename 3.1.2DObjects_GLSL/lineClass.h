#pragma once
#include "Object.h"
class lineClass :
	public Object
{
private:
	GLfloat line[2][2];
	GLfloat line_color[3];
	GLuint VBO_line, VAO_line;

public:
	lineClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {
		line_color[0] = 1.0f;
		line_color[1] = 0.0f;
		line_color[2] = 0.0f;
	}
	~lineClass(){
	}

	virtual void initObject();
	void initObject(int win_width, int win_height);
	virtual void drawObject();
	virtual void updateObjcet();
	virtual void cleanup();
};

