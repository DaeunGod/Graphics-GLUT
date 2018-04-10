#include "stdafx.h"

GLfloat marco_body1[4][2] = { { -2.0f, -2.0f } ,{ -2.0f, 0.0f },{ 0.0f, 0.0f },{ 0.0f,-2.0f } };
GLfloat marco_body2[4][2] = { { -3.0f, -2.0f } ,{ -3.0f, 0.0f },{ -2.0f, 0.0f },{ -2.0f,-2.0f } };
GLfloat marco_body3[4][2] = { { -2.0f, -4.0f } ,{ -2.0f, -2.0f },{ 0.0f, -2.0f },{ 0.0f,-4.0f } };

GLfloat marco_color[7][3] = {
	{ 66.0f / 255.0f, 32.0f / 255.0f, 0.0f / 255.0f },
{ 140.0f / 255.0f, 89.0f / 255.0f, 33.0f / 255.0f },
{ 155.0f / 255.0f, 105.0f / 255.0f, 57.0f / 255.0f },
{ 155.0f / 255.0f, 155.0f / 255.0f, 155.0f / 255.0f },
{ 0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f },
{ 139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f },
{ 255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f }
};

GLuint VBO_marco, VAO_marco;

void marcoClass::initObject() {
	GLsizeiptr buffer_size = sizeof(marco_body1);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_marco);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_marco);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(marco_body1), marco_body1);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_marco);
	glBindVertexArray(VAO_marco);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_marco);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void marcoClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	calcUniforMat4(ViewProjectionMatrix);



	glBindVertexArray(VAO_marco);

	glUniform3fv(loc_primitive_color, 1, marco_color[SWORD_BODY]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glBindVertexArray(0);
}

void marcoClass::updateObjcet() {

}

void marcoClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_marco);
	glDeleteBuffers(1, &VBO_marco);
}