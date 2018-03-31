#include "stdafx.h"


void lineClass::initObject() {

}

void lineClass::initObject(int win_width, int win_height) {
	m_winSize = glm::vec2(win_width, win_height);

	line[0][0] = (1.0f / 4.0f - 1.0f / 2.5f)*win_height;
	line[0][1] = (1.0f / 4.0f - 1.0f / 2.5f)*win_height - win_height / 4.0f;
	line[1][0] = win_width / 2.5f;
	line[1][1] = win_width / 2.5f - win_height / 4.0f;

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_line);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_line);
	glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_line);
	glBindVertexArray(VAO_line);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_line);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void lineClass::drawObject() {
	glUniform3fv(loc_primitive_color, 1, line_color);
	glBindVertexArray(VAO_line);
	glDrawArrays(GL_LINES, 0, 2);
	glBindVertexArray(0);
}

void lineClass::updateObjcet() {
	line[0][0] = (1.0f / 4.0f - 1.0f / 2.5f)*m_winSize.y;
	line[0][1] = (1.0f / 4.0f - 1.0f / 2.5f)*m_winSize.y - m_winSize.y / 4.0f;
	line[1][0] = m_winSize.x / 2.5f;
	line[1][1] = m_winSize.x / 2.5f - m_winSize.y / 4.0f;

	glBindBuffer(GL_ARRAY_BUFFER, VBO_line);
	glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void lineClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_line);
	glDeleteBuffers(1, &VBO_line);
}


