#include "stdafx.h"
#include <string>

//GLfloat left_bottom[4][2] = { { 0.0, 0.0 },{ 40.0, 40.0 }, { 40.0, 0.0 },{ 40.0, 0.0 } };
//GLfloat left_bottom[4][2] = { { -20.0, -20.0 },{ 20.0, -20.0 } ,{ 10.0, 10.0 },{ -10.0f, 10.0f } };

GLfloat main_box[5][2] = { { -20.0f, -20.0f },{ -20.0f, 20.0f } ,{ 20.0, -20.0f },{ 20.0f, 20.0f },{ 20.0f, 0.0f } };
GLfloat left_bottom[5][2] = { { -20.0f, -20.0f },{ -20.0f, -16.0f }, { -16.0f, -20.0f }, { -16.0f, -16.0f },{-16.0f, -18.0f} };
GLfloat left_top[5][2] = { { -20.0f, 16.0f },{ -20.0f, 20.0f },{ -16.0f, 16.0f },{ -16.0f, 20.0f },{ -16.0f, 18.0f } };
GLfloat right_bottom[5][2] = { { 16.0f, -20.0f },{ 16.0f, -16.0f },{ 20.0f, -20.0f },{ 20.0f, -16.0f },{ 20.0f, -18.0f } };
GLfloat right_top[5][2] = { { 16.0f, 16.0f },{ 16.0f, 20.0f },{ 20.0f, 16.0f },{ 20.0f, 20.0f },{ 20.0f, 18.0f } };
GLfloat bottom_line[5][2] = { { -20.0f, -16.0f },{ -20.0f, -15.3f },{ 20.0f, -16.0f },{ 20.0f, -15.3f },{ 20.0f, -15.2f } };
GLfloat line1[4][2] = { { -20.0f, -20.0f },{ -20.0f, -19.5f }, { 20.0f, -20.0f },{ 20.0f, -19.5f } };
GLfloat line2[4][2] = { { -20.0f, -20.0f },{ -20.0f, 20.0f },{ -19.5f, -20.0f },{ -19.5f, 20.0f } };
GLfloat line3[4][2] = { { 19.5f, -20.0f },{ 19.5f, 20.0f },{ 20.0f, -20.0f },{ 20.0f, 20.0f } };
GLfloat line4[4][2] = { { -20.0f, 19.5f },{ -20.0f, 20.0f },{ 20.0f, 19.5f },{ 20.0f, 20.0f } };
GLfloat top_line[4][2] = { { -20.0f, 15.3f },{ -20.0f, 16.0f },{ 20.0f, 15.3f },{ 20.0f, 16.0f } };
GLfloat left_line[4][2] = { { -16.0f, -20.0f },{ -16.0f, 20.0f },{ -15.3f, -20.0f },{ -15.3f, 20.0f } };
GLfloat right_line[4][2] = { { 15.3f, -20.0f },{ 15.3f, 20.0f },{ 16.0f, -20.0f },{ 16.0f, 20.0f } };

GLfloat left_right_line[4][2] = { { -9.2f, -15.5f },{ -9.2f, 15.5f },{ -9.9f, -15.5f },{ -9.9f, 15.5f } };
GLfloat center_left_line[4][2] = { { -2.8f, -15.5f },{ -2.8f, 15.5f },{ -3.5f, -15.5f },{ -3.5f, 15.5f } };
GLfloat center_right_line[4][2] = { { 3.2f, -15.5f },{ 3.2f, 15.5f },{ 3.9f, -15.5f },{ 3.9f, 15.5f } };
GLfloat right_left_line[4][2] = { { 9.8f, -15.5f },{ 9.8f, 15.5f },{ 10.5f, -15.5f },{ 10.5f, 15.5f } };
//GLfloat left_middle[5][2] = { { -20.0, -16.0 },{ -16.0, -16.0 } ,{ -20.0, 16.0 },{ -16.0f, 16.0f }, {-16.0f, 0.0f} };

GLfloat box_color[17][3] = {
	{ 185.0f / 255.0f, 122.0f / 255.0f, 86.0f / 255.0f },
	{ 218.0f / 255.0f, 217.0f / 255.0f, 218.0f / 255.0f },  // big_wing
	{ 255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f },
	{ 147.0f / 255.0f, 146.0f / 255.0f, 146.0f / 255.0f },
	{ 215.0f / 255.0f, 213.0f / 255.0f, 214.0f / 255.0f },
	{ 137.0f / 255.0f, 60.0f / 255.0f, 33.0f / 255.0f },
	{ 111.0f / 255.0f, 60.0f / 255.0f, 42.0f / 255.0f },
	{ 147.0f / 255.0f, 78.0f / 255.0f, 50.0f / 255.0f },
	{ 110.0f / 255.0f, 60.0f / 255.0f, 41.0f / 255.0f },
	{ 127.0f / 255.0f, 78.0f / 255.0f, 60.0f / 255.0f },
	{ 96.0f / 255.0f, 50.0f / 255.0f, 24.0f / 255.0f },
{ 123.0f / 255.0f, 54.0f / 255.0f, 30.0f / 255.0f },
{ 138.0f / 255.0f, 61.0f / 255.0f, 33.0f / 255.0f },
{ 145.0f / 255.0f, 77.0f / 255.0f, 36.0f / 255.0f },
{ 146.0f / 255.0f, 65.0f / 255.0f, 35.0f / 255.0f },
{ 139.0f / 255.0f, 61.0f / 255.0f, 33.0f / 255.0f },
{ 139.0f / 255.0f, 61.0f / 255.0f, 33.0f / 255.0f },
};
void boxClass::initObject() {
	GLsizeiptr buffer_size = sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3) + sizeof(line4) + sizeof(top_line) + sizeof(left_line) + sizeof(right_line) + sizeof(left_right_line) +
		sizeof(center_left_line) + sizeof(center_right_line) + sizeof(right_left_line);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_box);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_box);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory
	

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(main_box), main_box);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box), sizeof(left_bottom), left_bottom);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom), sizeof(left_top), left_top);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top), sizeof(right_bottom), right_bottom);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom), sizeof(right_top), right_top);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top), sizeof(bottom_line), bottom_line);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line), 
		sizeof(line1), line1);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1),
		sizeof(line2), line2);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2),
		sizeof(line3), line3);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3),
		sizeof(line4), line4);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3) + sizeof(line4),
		sizeof(top_line), top_line);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3) + sizeof(line4) + sizeof(top_line),
		sizeof(left_line), left_line);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3) + sizeof(line4) + sizeof(top_line) + sizeof(left_line),
		sizeof(right_line), right_line);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3) + sizeof(line4) + sizeof(top_line) + sizeof(left_line) + sizeof(right_line),
		sizeof(left_right_line), left_right_line);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3) + sizeof(line4) + sizeof(top_line) + sizeof(left_line) + sizeof(right_line) + sizeof(left_right_line),
		sizeof(center_left_line), center_left_line);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3) + sizeof(line4) + sizeof(top_line) + sizeof(left_line) + sizeof(right_line) + sizeof(left_right_line) + 
		sizeof(center_left_line),
		sizeof(center_right_line), center_right_line);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(main_box) + sizeof(left_bottom) + sizeof(left_top) + sizeof(right_bottom) + sizeof(right_top) + sizeof(bottom_line) +
		sizeof(line1) + sizeof(line2) + sizeof(line3) + sizeof(line4) + sizeof(top_line) + sizeof(left_line) + sizeof(right_line) + sizeof(left_right_line) +
		sizeof(center_left_line) + sizeof(center_right_line),
		sizeof(right_left_line), right_left_line);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_box);
	glBindVertexArray(VAO_box);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_box);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
void boxClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	if (m_position.y < 20.0f*m_scale.x)
		m_position.y = 20.0f*m_scale.x;
	calcUniforMat4(ViewProjectionMatrix);

	glBindVertexArray(VAO_box);

	glUniform3fv(loc_primitive_color, 1, box_color[0]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);

	glUniform3fv(loc_primitive_color, 1, box_color[1]);
	glDrawArrays(GL_TRIANGLE_STRIP, 5, 5);

	glUniform3fv(loc_primitive_color, 1, box_color[2]);
	glDrawArrays(GL_TRIANGLE_STRIP, 10, 5);

	glUniform3fv(loc_primitive_color, 1, box_color[3]);
	glDrawArrays(GL_TRIANGLE_STRIP, 15, 5);

	glUniform3fv(loc_primitive_color, 1, box_color[4]);
	glDrawArrays(GL_TRIANGLE_STRIP, 20, 5);

	glUniform3fv(loc_primitive_color, 1, box_color[5]);
	glDrawArrays(GL_TRIANGLE_STRIP, 25, 5);

	glUniform3fv(loc_primitive_color, 1, box_color[6]);
	glDrawArrays(GL_TRIANGLE_STRIP, 30, 4);

	glUniform3fv(loc_primitive_color, 1, box_color[7]);
	glDrawArrays(GL_TRIANGLE_STRIP, 34, 4);

	glUniform3fv(loc_primitive_color, 1, box_color[8]);
	glDrawArrays(GL_TRIANGLE_STRIP, 38, 4);

	glUniform3fv(loc_primitive_color, 1, box_color[9]);
	glDrawArrays(GL_TRIANGLE_STRIP, 42, 4);

	glUniform3fv(loc_primitive_color, 1, box_color[10]);
	glDrawArrays(GL_TRIANGLE_STRIP, 46, 4);
	glUniform3fv(loc_primitive_color, 1, box_color[11]);
	glDrawArrays(GL_TRIANGLE_STRIP, 50, 4);
	glUniform3fv(loc_primitive_color, 1, box_color[12]);
	glDrawArrays(GL_TRIANGLE_STRIP, 54, 4);
	glUniform3fv(loc_primitive_color, 1, box_color[13]);
	glDrawArrays(GL_TRIANGLE_STRIP, 58, 4);
	glUniform3fv(loc_primitive_color, 1, box_color[14]);
	glDrawArrays(GL_TRIANGLE_STRIP, 62, 4);
	glUniform3fv(loc_primitive_color, 1, box_color[15]);
	glDrawArrays(GL_TRIANGLE_STRIP, 66, 4);
	glUniform3fv(loc_primitive_color, 1, box_color[16]);
	glDrawArrays(GL_TRIANGLE_STRIP, 70, 4);

	
	glBindVertexArray(0);
}
void boxClass::updateObjcet() {

}
void boxClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_box);
	glDeleteBuffers(1, &VBO_box);
}
