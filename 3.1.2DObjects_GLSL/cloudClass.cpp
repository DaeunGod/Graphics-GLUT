#include "stdafx.h"


GLfloat circle[360][2];

GLfloat cloud_color[1][3] = {
	{ 235 / 255.0f, 225 / 255.0f, 196 / 255.0f },
};

void cloudClass::initObject() {
	for (int i = 0; i < 360; i++) {
		circle[i][0] = 50 * cosf(i*TO_RADIAN);
		circle[i][1] = 50 * sinf(i*TO_RADIAN);
	}

	GLsizeiptr buffer_size = sizeof(circle);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_cloud);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_cloud);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(circle), circle);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_cloud);
	glBindVertexArray(VAO_cloud);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_cloud);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
void cloudClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	calcUniforMat4(ViewProjectionMatrix);

	glBindVertexArray(VAO_cloud);
	
	glUniform3fv(loc_primitive_color, 1, cloud_color[COCKTAIL_NECK]);
	if(isFilled )
		glDrawArrays(GL_TRIANGLE_FAN, 0, 360);
	else
		glDrawArrays(GL_LINE_LOOP, 0, 360);

	glBindVertexArray(0);
}
void cloudClass::updateObjcet() {

}
void cloudClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_cloud);
	glDeleteBuffers(1, &VBO_cloud);
}
