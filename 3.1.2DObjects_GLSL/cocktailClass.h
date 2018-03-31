#pragma once
#include "Object.h"

enum ENUM_COCKTAIL {
	COCKTAIL_NECK,
	COCKTAIL_LIQUID,
	COCKTAIL_REMAIN,
	COCKTAIL_STRAW,
	COCKTAIL_DECO
};

class cocktailClass :
	public Object
{
private:
	GLuint VBO_cocktail, VAO_cocktail;

public:
	cocktailClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {

	}
	~cocktailClass() {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

