#pragma once
#include "Object.h"
class boxClass :
	public Object
{
private:
	GLuint VBO_box, VAO_box;

public:
	boxClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {

	}
	~boxClass() {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

