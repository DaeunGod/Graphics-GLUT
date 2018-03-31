#pragma once
#include "Object.h"

enum ENUM_SHIRT {
	SHIRT_LEFT_BODY,
	SHIRT_RIGHT_BODY,
	SHIRT_LEFT_COLLAR,
	SHIRT_RIGHT_COLLAR,
	SHIRT_FRONT_POCKET,
	SHIRT_BUTTON1,
	SHIRT_BUTTON2,
	SHIRT_BUTTON3,
	SHIRT_BUTTON4
};

class shirtClass :
	public Object
{
private:
	GLuint VBO_shirt, VAO_shirt;

public:
	shirtClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {

	}
	~shirtClass() {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

