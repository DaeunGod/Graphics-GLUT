#pragma once


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
//#include "texture.hpp"



class Sprite {
private:
	GLuint textureBufferID;
	glm::vec2 position;
	unsigned width;
	unsigned height;

	glm::vec2 uv2;
	glm::vec2 uv3;

	std::vector<unsigned char> image;

	GLuint vertexbuffer;
	

public:
	Sprite(const char* filename) {
		//glGenBuffers(1, &vertexbuffer);
		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		//std::vector<unsigned char> tmp;
		//

		//
		//uv2.x = 1;
		//uv2.y = 1;

		//unsigned error = lodepng::decode(tmp, width, height, filename);

		//if (error != 0)
		//{
		//	fprintf(stdout, "error %d : %s\n", error, lodepng_error_text(error));
		//	//return 1;
		//}
		//fprintf(stdout, "load success %d %d\n", width, height);
		//while (uv2.x < width)
		//	uv2.x *= 2;
		//while (uv2.y < height)
		//	uv2.y *= 2;

		//uv3.x = width / 2;
		//uv3.y = height / 2;
		//

		//std::vector<unsigned char> image2(uv2.x * uv2.y * 4);
		//
		//for(size_t y=0; y<height; y++)
		//	for (size_t x = 0; x < width; x++)
		//		for (size_t c = 0; c < 4; c++)
		//			image2[4 * uv2.x * y + 4 * x + c] = tmp[4 * width*y + 4 * x + c];
		//image = image2;
		//glEnable(GL_TEXTURE_2D);
		//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
		//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//glTexImage2D(GL_TEXTURE_2D, 0, 4, uv2.x, uv2.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image2[0]);
		//func = &render;
	}

public:
	void setPosition(glm::vec2 newPosition);
	glm::vec2 getPosition();
	void render();
	void update();


};

