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
	GLfloat house_color[5][3] = {
		{ 200.0f / 255.0f, 39.0f / 255.0f, 42.0f / 255.0f },
		{ 235.0f / 255.0f, 225.0f / 255.0f, 196.0f / 255.0f },
		{ 255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f },
		{ 233.0f / 255.0f, 113.0f / 255.0f, 23.0f / 255.0f },
		{ 44.0f / 255.0f, 180.0f / 255.0f, 49.0f / 255.0f }
	};

public:
	houseClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {

	}
	~houseClass() {

	}

	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();

	void setColor(glm::vec3 roof, glm::vec3 body, glm::vec3 chimney, glm::vec3 door, glm::vec3 window);
};

