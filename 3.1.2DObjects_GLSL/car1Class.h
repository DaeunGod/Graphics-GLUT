#pragma once
#include "Object.h"



enum ENUM_CAR1 {
	CAR_BODY,
	CAR_FRAME,
	CAR_WINDOW,
	CAR_LEFT_LIGHT,
	CAR_RIGHT_LIGHT,
	CAR_LEFT_WHEEL,
	CAR_RIGHT_WHEEL
};

class car1Class :
	public Object
{
private:
	GLuint VBO_car, VAO_car;

public:
	car1Class(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {
	}
	~car1Class() {

	}
	virtual void initObject();
	virtual void drawObject();
	virtual void updateObjcet();
	virtual void cleanup();
};

