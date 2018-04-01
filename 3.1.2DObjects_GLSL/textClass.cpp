#include "textClass.h"
#include <string>


void textClass::initObject() {

}
void textClass::drawObject(glm::mat4 ViewProjectionMatrix) {
	calcUniforMat4(ViewProjectionMatrix);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, m_winSize.x, 0, m_winSize.y, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glPushAttrib(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	glRasterPos2i(m_position.x, m_position.y);
	for (int i = 0; i<String.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
	}
	glPopAttrib();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
void textClass::updateObjcet() {

}
void textClass::cleanup() {

}
//void printtext(int x, int y, string String)
//{
//	//(x,y) is from the bottom left of the window
//	
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glEnable(GL_DEPTH_TEST);
//
//	char string[64];
//	sprintf(string, "something");
//	printtext(10, 10, string);
//
//	glutSwapBuffers();
//}