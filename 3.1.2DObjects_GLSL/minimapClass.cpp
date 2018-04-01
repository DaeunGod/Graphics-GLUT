#include "stdafx.h"

GLfloat minimap[5][2] = { { -70.0f, -70.0f },{ -70.0f, 70.0f } ,{ 70.0f, -70.0f },{ 70.0f, 70.0f },{ 70.0f, 0.0f } };

GLfloat minimap_color[2][3] = {
	{ 255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f },
};

void minimapClass::initObject() {
	GLsizeiptr buffer_size = sizeof(minimap);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_minimap);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_minimap);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory


	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(minimap), minimap);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_minimap);
	glBindVertexArray(VAO_minimap);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_minimap);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	mMainMinimapPoint = new minimapPointClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	mMainMinimapPoint->initObject();
	mMainMinimapPoint->setBlink(true);

	for (int i = 0; i < NUMBER_OF_STRUCTURES; i++) {
		mStructuresPoint[i] = new minimapPointClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
		mStructuresPoint[i]->initObject();
		mStructuresPoint[i]->setPointType(MINIMAPPOINT_STRUCTURE);
	}
}

void minimapClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	calcUniforMat4(ViewProjectionMatrix);

	

	glBindVertexArray(VAO_minimap);

	glUniform3fv(loc_primitive_color, 1, minimap_color[0]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);

	glBindVertexArray(0);

	mMainMinimapPoint->setMinimapPosition(m_position);
	mMainMinimapPoint->drawObject(ViewProjectionMatrix);
	for (int i = 0; i < NUMBER_OF_STRUCTURES; i++) {
		mStructuresPoint[i]->setMinimapPosition(m_position);
		mStructuresPoint[i]->drawObject(ViewProjectionMatrix);
	}
}

void minimapClass::updateObjcet() {

}

void minimapClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_minimap);
	glDeleteBuffers(1, &VBO_minimap);

	mMainMinimapPoint->cleanup();
	delete mMainMinimapPoint;
}

void minimapClass::setStructuresPosition(int index, glm::vec3 Position) {
	if (mStructuresPoint[index] != NULL)
		mStructuresPoint[index]->setCharacterPosition(Position);
}

void minimapClass::setHeroPosition(glm::vec3 characterPosition) {
	if (mMainMinimapPoint != NULL) {
		mMainMinimapPoint->setCharacterPosition(characterPosition);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #MARK - MinimapPoint																	/////////////////////////////////////

GLfloat minimapPoint[5][2] = { { -3.0f, -3.0f },{ -3.0f, 3.0f } ,{ 3.0f, -3.0f },{ 3.0f, 3.0f },{ 3.0f, 3.0f } };

GLfloat minimapPoint_color[2][3] = {
	{ 100.0f / 255.0f, 100.0f / 255.0f, 255.0f / 255.0f },
{ 20.0f / 255.0f, 254.0f / 255.0f, 98.0f / 255.0f },
};

void minimapPointClass::initObject() {
	GLsizeiptr buffer_size = sizeof(minimapPoint);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_minimapPoint);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_minimapPoint);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory


	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(minimapPoint), minimapPoint);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_minimapPoint);
	glBindVertexArray(VAO_minimapPoint);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_minimapPoint);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void minimapPointClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	m_position.x = minimapPosition.x + (characterPosition.x / 680.0f*70.0f);
	m_position.y = minimapPosition.y + (characterPosition.y / 500.0f*70.0f);

	if (isBlink == true) {
		delay++;
		if (delay > 20) {
			delay = 0;
			blinkFlag = !blinkFlag;
		}

		if (blinkFlag == true)
			return;
	}
	calcUniforMat4(ViewProjectionMatrix);

	/*m_position.x = minimapPosition.x + (characterPosition.x / 680.0f*70.0f);
	m_position.y = minimapPosition.y;*/
	glBindVertexArray(VAO_minimapPoint);

	glUniform3fv(loc_primitive_color, 1, minimapPoint_color[pointType]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);

	glBindVertexArray(0);
}

void minimapPointClass::updateObjcet() {

}

void minimapPointClass::cleanup() {
	glDeleteVertexArrays(1, &VAO_minimapPoint);
	glDeleteBuffers(1, &VBO_minimapPoint);
}
