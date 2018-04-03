#pragma once
#include "Object.h"

//#define AIRPLANE_BIG_WING 0
//#define AIRPLANE_SMALL_WING 1
//#define AIRPLANE_BODY 2
//#define AIRPLANE_BACK 3
//#define AIRPLANE_SIDEWINDER1 4
//#define AIRPLANE_SIDEWINDER2 5
//#define AIRPLANE_CENTER 6
enum ENUM_AIRPLANE{
	AIRPLANE_BIG_WING,
	AIRPLANE_SMALL_WING,
	AIRPLANE_BODY,
	AIRPLANE_BACK,
	AIRPLANE_SIDEWINDER1,
	AIRPLANE_SIDEWINDER2,
	AIRPLANE_CENTER
};
enum ENUM_AIRPLANE_TYPE {
	AIRPLANE_NORMAL,
	AIRPLANE_CIRCULAR,
};
class airplaneClass :
	public Object
{
private:
	GLuint VBO_airplane, VAO_airplane;
	float mRadius;
	ENUM_AIRPLANE_TYPE mAirplaneType;
	glm::vec3 mPastPosition;

public:
	airplaneClass(GLint _loc_ModelViewProjectionMatrix, GLint _loc_primitive_color) :
		Object(_loc_ModelViewProjectionMatrix, _loc_primitive_color) {
		mPastPosition = m_position;
		mRadius = 0;
		circularMotionAngle = 0;
		mAirplaneType = AIRPLANE_NORMAL;
		/*big_wing[0][0] = 0.0f;		big_wing[0][1] = 0.0f;
		big_wing[1][0] = -20.0f;	big_wing[1][1] = 15.0f;
		big_wing[2][0] = -20.0f;	big_wing[2][1] = 20.0;
		big_wing[3][0] = 0.0f;		big_wing[3][1] = 23.0f;
		big_wing[4][0] = 20.0f;		big_wing[4][1] = 20.0f;
		big_wing[5][0] = 20.0f;		big_wing[5][1] = 15.0f;

		small_wing[0][0] = 0.0f;	small_wing[0][1] = -18.0f;
		small_wing[1][0] = -11.0f;	small_wing[1][1] = -12.0f;
		small_wing[2][0] = -12.0f;	small_wing[2][1] = -7.0f;
		small_wing[3][0] = 0.0f;	small_wing[3][1] = -10.0f;
		small_wing[4][0] = 12.0f;	small_wing[4][1] = -7.0f;
		small_wing[5][0] = 11.0f;	small_wing[5][1] = -12.0f;

		body[0][0] = 0.0f;		body[0][1] = -25.0f;
		body[1][0] = -6.0f;		body[1][1] = 0.0f;
		body[2][0] = -6.0f;		body[2][1] = 22.0f;
		body[3][0] = 6.0f;		body[3][1] = 22.0f;
		body[4][0] = 6.0f;		body[4][1] = 0.0f;

		= { { 0.0, 25.0 },{ -7.0, 24.0 },{ -7.0, 21.0 },{ 7.0, 21.0 },{ 7.0, 24.0 } };
		back[0][0] = 0.0f;		back[0][1] = 25.0f;
		back[1][0] = -7.0f;		back[1][1] = 24.0f;
		back[2][0] = -7.0f;		back[2][1] = 21.0f;
		back[3][0] = 7.0f;		back[3][1] = 2.0f;
		back[4][0] = 6.0f;		back[4][1] = 0.0f;*/
	}

	~airplaneClass() {

	}

	
	void circularMotion();
	void setPosition(glm::vec3 newPosition);
	void setRadius(float radius) { mRadius = radius; }
	void setType(ENUM_AIRPLANE_TYPE type) { mAirplaneType = type; }
	virtual void initObject();
	virtual void drawObject(glm::mat4 ViewProjectionMatrix);
	virtual void updateObjcet();
	virtual void cleanup();
};

