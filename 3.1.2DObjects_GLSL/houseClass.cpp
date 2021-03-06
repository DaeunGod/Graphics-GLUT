#include "stdafx.h"


GLfloat roof[3][2] = { { -12.0, 0.0 },{ 0.0, 12.0 },{ 12.0, 0.0 } };
GLfloat house_body[4][2] = { { -12.0, -14.0 },{ -12.0, 0.0 },{ 12.0, 0.0 },{ 12.0, -14.0 } };
GLfloat chimney[4][2] = { { 6.0, 6.0 },{ 6.0, 14.0 },{ 10.0, 14.0 },{ 10.0, 2.0 } };
GLfloat door[4][2] = { { -8.0, -14.0 },{ -8.0, -8.0 },{ -4.0, -8.0 },{ -4.0, -14.0 } };
GLfloat window[4][2] = { { 4.0, -6.0 },{ 4.0, -2.0 },{ 8.0, -2.0 },{ 8.0, -6.0 } };

//GLfloat house_color[5][3] = {
//	{ 200 / 255.0f, 39 / 255.0f, 42 / 255.0f },
//	{ 235 / 255.0f, 225 / 255.0f, 196 / 255.0f },
//	{ 255 / 255.0f, 0 / 255.0f, 0 / 255.0f },
//	{ 233 / 255.0f, 113 / 255.0f, 23 / 255.0f },
//	{ 44 / 255.0f, 180 / 255.0f, 49 / 255.0f }
//};

void houseClass::initObject(ENUM_HOUSE_TYPE newType) {
	initObject();

	houseType = newType;
	if (houseType == HOUSE_ARMORY) {
		mSword = new swordClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
		mSword->initObject();
		mSword->setScale(2.0f);
		mSword->setRotateType(1);
		mSword->setRotate(0, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	if (houseType == HOUSE_SHOP) {
		mShirt = new shirtClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
		mShirt->initObject();
		mShirt->setScale(1.5f);
	}
}

void houseClass::initObject() {
	GLsizeiptr buffer_size = sizeof(roof) + sizeof(house_body) + sizeof(chimney) + sizeof(door)
		+ sizeof(window);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_house);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_house);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(roof), roof);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(roof), sizeof(house_body), house_body);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(roof) + sizeof(house_body), sizeof(chimney), chimney);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(roof) + sizeof(house_body) + sizeof(chimney), sizeof(door), door);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(roof) + sizeof(house_body) + sizeof(chimney) + sizeof(door),
		sizeof(window), window);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_house);
	glBindVertexArray(VAO_house);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_house);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	
}

void houseClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	calcUniforMat4(ViewProjectionMatrix);

	glBindVertexArray(VAO_house);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_ROOF]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 3);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_BODY]);
	glDrawArrays(GL_TRIANGLE_FAN, 3, 4);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_CHIMNEY]);
	glDrawArrays(GL_TRIANGLE_FAN, 7, 4);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_DOOR]);
	glDrawArrays(GL_TRIANGLE_FAN, 11, 4);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_WINDOW]);
	glDrawArrays(GL_TRIANGLE_FAN, 15, 4);

	glBindVertexArray(0);

	if (houseType == HOUSE_ARMORY) {
		mSword->setPosition(m_position + glm::vec3(114.0f, -39.0f, 0.0f));
		mSword->drawObject(ViewProjectionMatrix);
	}
	if (houseType == HOUSE_SHOP) {
		mShirt->setPosition(m_position + glm::vec3(123.0f, -42.0f, 0.0f));
		mShirt->drawObject(ViewProjectionMatrix);
	}
}

void houseClass::updateObjcet() {

}

void houseClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_house);
	glDeleteBuffers(1, &VBO_house);
	if (houseType == HOUSE_ARMORY) {
		mSword->cleanup();
		delete mSword;
	}
	if (houseType == HOUSE_SHOP) {
		mShirt->cleanup();
		delete mShirt;
	}
}

void houseClass::setColor(glm::vec3 roof, glm::vec3 body, glm::vec3 chimney, glm::vec3 door, glm::vec3 window) {
	house_color[0][0] = roof.r; house_color[0][1] = roof.g; house_color[0][2] = roof.b;
	house_color[1][0] = body.r; house_color[1][1] = body.g; house_color[1][2] = body.b;
	house_color[2][0] = chimney.r; house_color[2][1] = chimney.g; house_color[2][2] = chimney.b;
	house_color[3][0] = door.r; house_color[3][1] = door.g; house_color[3][2] = door.b;
	house_color[4][0] = window.r; house_color[4][1] = window.g; house_color[4][2] = window.b;
}