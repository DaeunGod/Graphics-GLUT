#include "stdafx.h"

GLfloat blockTileBackGround[5][2] = { { -40.0, 20.0 },{ -40.0, -100.0 } ,{ 40.0, 20.0 },{ 40.0f, -100.0 },{ -40.0f, -100.0 } };
GLfloat blockTileline[4][2] = { { -40, 15.0 },{ -40.0, 20.0 } ,{ 40.0, 15.0 },{ 40.0f, 20.0 } };
GLfloat blockTileDeco1[3][2] = { { -28, 15.0 },{ -23.0, 10.0 },{ -20.0, 15.0 } };
GLfloat blockTileDeco2[3][2] = { { -10, 15.0 },{ -7.0, 12.0 },{ 3.0, 15.0 } };
GLfloat blockTileDeco3[4][2] = { { 12, 20.0 },{ 15.0, 23.0 },{ 21.0, 19.0 },{ 25.0, 22.0 } };
GLfloat blockTileDeco4[4][2] = { { 20, 12.0 },{ 25.0, 17.0 },{ 31.0, 10.0 },{ 33.0, 16.0 } };

GLfloat blockTile_color[2][3] = {
	{ 110 / 255.0f, 67 / 255.0f, 42 / 255.0f },
{ 14 / 255.0f, 209 / 255.0f, 69 / 255.0f },
};

void blockTileClass::initObject() {
	GLsizeiptr buffer_size = sizeof(blockTileBackGround) + sizeof(blockTileline) + sizeof(blockTileDeco1) +
		sizeof(blockTileDeco2) + sizeof(blockTileDeco3) + sizeof(blockTileDeco4);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_blockTile);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_blockTile);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory


	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(blockTileBackGround), blockTileBackGround);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(blockTileBackGround), sizeof(blockTileline), blockTileline);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(blockTileBackGround) + sizeof(blockTileline), sizeof(blockTileDeco1), blockTileDeco1);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(blockTileBackGround) + sizeof(blockTileline) + sizeof(blockTileDeco1)
		, sizeof(blockTileDeco2), blockTileDeco2);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(blockTileBackGround) + sizeof(blockTileline) + sizeof(blockTileDeco1) +
		sizeof(blockTileDeco2), sizeof(blockTileDeco3), blockTileDeco3);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(blockTileBackGround) + sizeof(blockTileline) + sizeof(blockTileDeco1) +
		sizeof(blockTileDeco2) + sizeof(blockTileDeco3), sizeof(blockTileDeco4), blockTileDeco4);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_blockTile);
	glBindVertexArray(VAO_blockTile);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_blockTile);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void blockTileClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	calcUniforMat4(ViewProjectionMatrix);

	glBindVertexArray(VAO_blockTile);

	glUniform3fv(loc_primitive_color, 1, blockTile_color[0]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);

	glUniform3fv(loc_primitive_color, 1, blockTile_color[1]);
	glDrawArrays(GL_TRIANGLE_STRIP, 5, 4);

	glUniform3fv(loc_primitive_color, 1, blockTile_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 9, 3);

	glUniform3fv(loc_primitive_color, 1, blockTile_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 3);

	glUniform3fv(loc_primitive_color, 1, blockTile_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 15, 4);

	glUniform3fv(loc_primitive_color, 1, blockTile_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 19, 4);

	glBindVertexArray(0);
}

void blockTileClass::updateObjcet() {

}

void blockTileClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_blockTile);
	glDeleteBuffers(1, &VBO_blockTile);
}