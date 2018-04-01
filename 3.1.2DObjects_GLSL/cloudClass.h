#pragma once
#include "Object.h"
class cloudClass :
	public Object
{
private:
	GLuint VBO_cloud, VAO_cloud;
	bool isFilled;
public:
	cloudClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {
		isFilled = false;
	}
	~cloudClass() {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

