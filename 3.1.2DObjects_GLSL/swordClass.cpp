#include "stdafx.h"

GLfloat sword_body[4][2] = { { -6.0f, 0.0f },{ -6.0f, -4.0f },{ 6.0f, -4.0f },{ 6.0f, 0.0f } };
GLfloat sword_body2[4][2] = { { -2.0f, -4.0f },{ -2.0f, -6.0f } ,{ 2.0f, -6.0f },{ 2.0f, -4.0f } };
GLfloat sword_head[4][2] = { { -2.0f, 0.0f },{ -2.0f, 16.0f } ,{ 2.0f, 16.0f },{ 2.0f, 0.0f } };
GLfloat sword_head2[3][2] = { { -2.0f, 16.0f },{ 0.0f, 19.46f } ,{ 2.0f, 16.0f } };
GLfloat sword_in[4][2] = { { -0.3f, 0.7f },{ -0.3f, 15.3f } ,{ 0.3f, 15.3f },{ 0.3f, 0.7f } };
GLfloat sword_down[4][2] = { { -2.0f, -6.0f } ,{ 2.0f, -6.0f },{ 4.0f, -8.0f },{ -4.0f, -8.0f } };
GLfloat sword_body_in[4][2] = { { 0.0f, -1.0f } ,{ 1.0f, -2.732f },{ 0.0f, -4.464f },{ -1.0f, -2.732f } };

GLfloat sword_color[7][3] = {
	{ 139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f },
{ 139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f },
{ 155.0f / 255.0f, 155.0f / 255.0f, 155.0f / 255.0f },
{ 155.0f / 255.0f, 155.0f / 255.0f, 155.0f / 255.0f },
{ 0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f },
{ 139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f },
{ 255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f }
};

void swordClass::initObject() {
	GLsizeiptr buffer_size = sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head) + sizeof(sword_head2) + sizeof(sword_in) + sizeof(sword_down) + sizeof(sword_body_in);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_sword);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_sword);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(sword_body), sword_body);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body), sizeof(sword_body2), sword_body2);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2), sizeof(sword_head), sword_head);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head), sizeof(sword_head2), sword_head2);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head) + sizeof(sword_head2), sizeof(sword_in), sword_in);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head) + sizeof(sword_head2) + sizeof(sword_in), sizeof(sword_down), sword_down);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head) + sizeof(sword_head2) + sizeof(sword_in) + sizeof(sword_down), sizeof(sword_body_in), sword_body_in);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_sword);
	glBindVertexArray(VAO_sword);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_sword);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
void swordClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	if (mRotateType == 1) {
		m_angle += 10;
		if (m_angle >= 360)
			m_angle -= 360;
	}

	m_position.y += 5.0f * cosf(m_angle*TO_RADIAN);

	calcUniforMat4(ViewProjectionMatrix);

	

	glBindVertexArray(VAO_sword);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_BODY]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_BODY2]);
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_HEAD]);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_HEAD2]);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 3);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_IN]);
	glDrawArrays(GL_TRIANGLE_FAN, 15, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_DOWN]);
	glDrawArrays(GL_TRIANGLE_FAN, 19, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_BODY_IN]);
	glDrawArrays(GL_TRIANGLE_FAN, 23, 4);

	glBindVertexArray(0);
}
void swordClass::updateObjcet() {

}
void swordClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_sword);
	glDeleteBuffers(1, &VBO_sword);
}
