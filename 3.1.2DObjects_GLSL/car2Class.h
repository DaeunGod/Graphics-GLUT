#pragma once
#include "Object.h"

enum ENUM_CAR2 {
	CAR2_BODY,
	CAR2_FRONT_WINDOW,
	CAR2_BACK_WINDOW,
	CAR2_FRONT_WHEEL,
	CAR2_BACK_WHEEL,
	CAR2_LIGHT1,
	CAR2_LIGHT2
};

class car2Class :
	public Object
{
private:
	GLuint VBO_car2, VAO_car2;

public:
	car2Class(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {

	}
	~car2Class() {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

