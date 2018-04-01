#pragma once
#include "Object.h"



enum ENUM_SWORD {
	SWORD_BODY,
	SWORD_BODY2,
	SWORD_HEAD,
	SWORD_HEAD2,
	SWORD_IN,
	SWORD_DOWN,
	SWORD_BODY_IN
};

class swordClass :
	public Object
{
private:
	GLuint VBO_sword, VAO_sword;
	int mRotateType;
public:
	void setRotateType(int rotateType) { mRotateType = rotateType; }
public:
	swordClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {
		mRotateType = 0;
	}
	~swordClass() {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

