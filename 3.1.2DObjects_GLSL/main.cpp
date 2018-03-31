#include <windows.h>
//#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "SOIL.h"
//#include <gl\gl.h>
//#include <gl\glu.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

GLuint texture[1];


int LoadGLTextures()
{
	
	texture[0] = SOIL_load_OGL_texture
	(
		"/resource/1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	if (texture[0] == 0)
		return false;

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}


void init()
{

	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

}

void display(void)
{
	int width, height;
	glClear(GL_COLOR_BUFFER_BIT );
	texture[0] = SOIL_load_OGL_texture
	(
		"resource/Marco_Walk_0.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	if (texture[0] == 0)
		return;

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	
	glTranslatef(-0.5f, -0.5f, -3.0f);
	//glScalef(0.5f, 0.5f, 0);
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	/*glTexCoord2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);*/
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.25f, 0.25f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.75f, 0.25f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.75f, 0.75f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.25f, 0.75f, 0.0f);
	//glTranslatef(0.5f, 0.5f, -3.0f);
	/*glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);*/
	/*glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);*/

	glEnd();

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION),
		glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);*/
	gluPerspective(30.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
/* Program entry point */

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	//glutInitContextVersion(4, 0);
	//glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);
	glClearDepth(1.0f); // Depth Buffer Setup
	//glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	//glDepthFunc(GL_LEQUAL);

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}