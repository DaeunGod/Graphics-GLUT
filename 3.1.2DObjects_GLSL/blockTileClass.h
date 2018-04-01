#pragma once
#include "Object.h"
class blockTileClass :
	public Object
{
private:
	GLuint VBO_blockTile, VAO_blockTile;

public:
	blockTileClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {

	}
	~blockTileClass() {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

