#pragma once
#include "Object.h"
#include <string>

class textClass :
	public Object
{
private:
	std::string String;
public:
	textClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {

	}
	~textClass() {

	}
	textClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color, std::string newString) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color), String(newString) {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

