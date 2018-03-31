#include "Sprite.h"
#include "SOIL.h"

void Sprite::setPosition(glm::vec2 newPosition) {
	position = newPosition;
}

glm::vec2 Sprite::getPosition(){
	return position;
}

void Sprite::render() {
	GLuint texture[1];
	glClear(GL_COLOR_BUFFER_BIT);
	texture[0] = SOIL_load_OGL_texture
	(
		"resource/1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	if (texture[0] == 0) {
		fprintf(stdout, "Invalid Image file\n");
		return;
	}


	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glLoadIdentity();

	glTranslatef(-0.0f, -0.0f, 0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.25f, 0.25f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.75f, 0.25f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.75f, 0.75f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.25f, 0.75f, 0.0f);

	glEnd();

}


void Sprite::update() {

}

//GLuint loadAndBufferImage(const char *filename) {
//	GLFWimage imageData;
//	glfwReadImage(filename, &imageData, NULL);
//
//	GLuint textureBufferID;
//	glGenTextures(1, &textureBufferID);
//	glBindTexture(GL_TEXTURE_2D, textureBufferID);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageData.Width, imageData.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.Data);
//
//	//glfwFreeImage(&imageData);
//
//	return textureBufferID;
//}