#pragma once
#include "Object.h"

enum ENUM_HOUSE {
	HOUSE_ROOF,
	HOUSE_BODY,
	HOUSE_CHIMNEY,
	HOUSE_DOOR,
	HOUSE_WINDOW
};

class houseClass :
	public Object
{
private:
	GLuint VBO_house, VAO_house;

public:
	houseClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {

	}
	~houseClass() {

	}

	virtual void initObject();
	virtual void drawObject();
	virtual void updateObjcet();
	virtual void cleanup();
};

