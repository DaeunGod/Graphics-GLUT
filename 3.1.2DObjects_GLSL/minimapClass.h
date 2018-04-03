#pragma once
#include "Object.h"

#define NUMBER_OF_STRUCTURES 4

enum ENUM_MINIMAPPOINT_TYPE {
	MINIMAPPOINT_CHARACTER,
	MINIMAPPOINT_STRUCTURE
};

class minimapPointClass;

class minimapClass :
	public Object
{
private:
	GLuint VBO_minimap, VAO_minimap;
	minimapPointClass *mMainMinimapPoint;
	minimapPointClass *mStructuresPoint[NUMBER_OF_STRUCTURES];
	bool isCollided;

public:
	minimapClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {
		mMainMinimapPoint = NULL;
		for (int i = 0; i < NUMBER_OF_STRUCTURES; i++)
			mStructuresPoint[i] = NULL;
		isCollided = false;
	}
	~minimapClass() {

	}

	void setCollided(bool collided) { isCollided = collided; }
	void setStructuresPosition(int index, glm::vec3 Position);
	void setHeroPosition(glm::vec3 characterPosition);
	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

class minimapPointClass :
	public Object
{
private:
	GLuint VBO_minimapPoint, VAO_minimapPoint;
	glm::vec3 minimapPosition;
	glm::vec3 characterPosition;
	bool isBlink;
	bool blinkFlag;
	int delay;
	ENUM_MINIMAPPOINT_TYPE pointType;

public:
	minimapPointClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {
		isBlink = false;
		blinkFlag = false;
		delay = 0;
		pointType = MINIMAPPOINT_CHARACTER;
	}
	~minimapPointClass() {

	}

	void setPointType(ENUM_MINIMAPPOINT_TYPE type) { pointType = type; }
	void setBlink(bool blink) { isBlink = blink; }
	void setMinimapPosition(glm::vec3 newMinimapPosition) {	minimapPosition = newMinimapPosition; }
	void setCharacterPosition(glm::vec3 newCharacterPosition) { characterPosition = newCharacterPosition; }
	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};


