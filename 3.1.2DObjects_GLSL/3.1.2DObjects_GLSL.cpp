#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
//#include "glfw.h"

#include "Shaders/LoadShaders.h"
GLuint h_ShaderProgram; // handle to shader program
GLint loc_ModelViewProjectionMatrix, loc_primitive_color; // indices of uniform variables

// include glm/*.hpp only if necessary
//#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> //translate, rotate, scale, ortho, etc.
#include "stdafx.h"
glm::mat4 ModelViewProjectionMatrix;
glm::mat4 ViewMatrix, ProjectionMatrix, ViewProjectionMatrix;

int win_width = 0, win_height = 0; 
float centerx = 0.0f, centery = 0.0f, rotate_angle = 0.0f;

// MARK: Create Object;
axesClass *g_axes;
lineClass *g_line;
airplaneClass *g_airPlane;
shirtClass *g_shirt;
houseClass *g_house;
car1Class *g_car1;
cocktailClass *g_cocktail;
car2Class *g_car2;

int airplane_clock = 0;
float airplane_s_factor = 1.0f;

//draw cocktail


//void prepare_cocktail() {
//	GLsizeiptr buffer_size = sizeof(neck)+sizeof(liquid)+sizeof(remain)+sizeof(straw)
//		+sizeof(deco);
//
//	// Initialize vertex buffer object.
//	glGenBuffers(1, &VBO_cocktail);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO_cocktail);
//	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory
//
//	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(neck), neck);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(neck), sizeof(liquid), liquid);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(neck)+sizeof(liquid), sizeof(remain), remain);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(neck)+sizeof(liquid)+sizeof(remain), sizeof(straw), straw);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(neck)+sizeof(liquid)+sizeof(remain)+sizeof(straw),
//		sizeof(deco), deco);
//
//	// Initialize vertex array object.
//	glGenVertexArrays(1, &VAO_cocktail);
//	glBindVertexArray(VAO_cocktail);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO_cocktail);
//	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
//
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}
//
//void draw_cocktail() {
//	glBindVertexArray(VAO_cocktail);
//
//	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_NECK]);
//	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
//
//	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_LIQUID]);
//	glDrawArrays(GL_TRIANGLE_FAN, 6, 6);
//
//	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_REMAIN]);
//	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
//
//	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_STRAW]);
//	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
//
//	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_DECO]);
//	glDrawArrays(GL_TRIANGLE_FAN, 20, 8);
//
//	glBindVertexArray(0);
//}

//draw car2
//#define CAR2_BODY 0
//#define CAR2_FRONT_WINDOW 1
//#define CAR2_BACK_WINDOW 2
//#define CAR2_FRONT_WHEEL 3
//#define CAR2_BACK_WHEEL 4
//#define CAR2_LIGHT1 5
//#define CAR2_LIGHT2 6
//
//GLfloat car2_body[8][2] = { { -18.0, -7.0 }, { -18.0, 0.0 }, { -13.0, 0.0 }, { -10.0, 8.0 }, { 10.0, 8.0 }, { 13.0, 0.0 }, { 18.0, 0.0 }, { 18.0, -7.0 } };
//GLfloat car2_front_window[4][2] = { { -10.0, 0.0 }, { -8.0, 6.0 }, { -2.0, 6.0 }, { -2.0, 0.0 } };
//GLfloat car2_back_window[4][2] = { { 0.0, 0.0 }, { 0.0, 6.0 }, { 8.0, 6.0 }, { 10.0, 0.0 } };
//GLfloat car2_front_wheel[8][2] = { { -11.0, -11.0 }, { -13.0, -8.0 }, { -13.0, -7.0 }, { -11.0, -4.0 }, { -7.0, -4.0 }, { -5.0, -7.0 }, { -5.0, -8.0 }, { -7.0, -11.0 } };
//GLfloat car2_back_wheel[8][2] = { { 7.0, -11.0 }, { 5.0, -8.0 }, { 5.0, -7.0 }, { 7.0, -4.0 }, { 11.0, -4.0 }, { 13.0, -7.0 }, { 13.0, -8.0 }, { 11.0, -11.0 } };
//GLfloat car2_light1[3][2] = { { -18.0, -1.0 }, { -17.0, -2.0 }, { -18.0, -3.0 } };
//GLfloat car2_light2[3][2] = { { -18.0, -4.0 }, { -17.0, -5.0 }, { -18.0, -6.0 } };
//
//GLfloat car2_color[7][3] = {
//	{ 100 / 255.0f, 141 / 255.0f, 159 / 255.0f },
//	{ 235 / 255.0f, 219 / 255.0f, 208 / 255.0f },
//	{ 235 / 255.0f, 219 / 255.0f, 208 / 255.0f },
//	{ 0 / 255.0f, 0 / 255.0f, 0 / 255.0f },
//	{ 0 / 255.0f, 0 / 255.0f, 0 / 255.0f },
//	{ 249 / 255.0f, 244 / 255.0f, 0 / 255.0f },
//	{ 249 / 255.0f, 244 / 255.0f, 0 / 255.0f }
//};
//
//GLuint VBO_car2, VAO_car2;
//void prepare_car2() {
//	GLsizeiptr buffer_size = sizeof(car2_body)+sizeof(car2_front_window)+sizeof(car2_back_window)+sizeof(car2_front_wheel)
//		+sizeof(car2_back_wheel)+sizeof(car2_light1)+sizeof(car2_light2);
//
//	// Initialize vertex buffer object.
//	glGenBuffers(1, &VBO_car2);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO_car2);
//	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory
//
//	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(car2_body), car2_body);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body), sizeof(car2_front_window), car2_front_window);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body)+sizeof(car2_front_window), sizeof(car2_back_window), car2_back_window);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body)+sizeof(car2_front_window)+sizeof(car2_back_window), sizeof(car2_front_wheel), car2_front_wheel);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body)+sizeof(car2_front_window)+sizeof(car2_back_window)+sizeof(car2_front_wheel),
//		sizeof(car2_back_wheel), car2_back_wheel);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body)+sizeof(car2_front_window)+sizeof(car2_back_window)+sizeof(car2_front_wheel)
//		+sizeof(car2_back_wheel), sizeof(car2_light1), car2_light1);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body)+sizeof(car2_front_window)+sizeof(car2_back_window)+sizeof(car2_front_wheel)
//		+sizeof(car2_back_wheel)+sizeof(car2_light1), sizeof(car2_light2), car2_light2);
//
//	// Initialize vertex array object.
//	glGenVertexArrays(1, &VAO_car2);
//	glBindVertexArray(VAO_car2);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO_car2);
//	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
//
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}
//
//void draw_car2() {
//	glBindVertexArray(VAO_car2);
//
//	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_BODY]);
//	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);
//
//	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_FRONT_WINDOW]);
//	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
//
//	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_BACK_WINDOW]);
//	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
//
//	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_FRONT_WHEEL]);
//	glDrawArrays(GL_TRIANGLE_FAN, 16, 8);
//
//	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_BACK_WHEEL]);
//	glDrawArrays(GL_TRIANGLE_FAN, 24, 8);
//
//	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_LIGHT1]);
//	glDrawArrays(GL_TRIANGLE_FAN, 32, 3);
//
//	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_LIGHT2]);
//	glDrawArrays(GL_TRIANGLE_FAN, 35, 3);
//
//	glBindVertexArray(0);
//}


void display(void) {
	int i;
	float x, r, s, delx, delr, dels;
	glm::mat4 ModelMatrix;

	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	
	ModelMatrix = glm::mat4(1.0f);
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	//draw_axes();
	g_axes->drawObject();

	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 300.0f, 0.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	g_line->drawObject();

	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-500.0f, 0.0f, 0.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	g_airPlane->drawObject();
	//draw_airplane();
 
	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-300.0f, 0.0f, 0.0f));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(2.0f, 2.0f, 1.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	g_shirt->drawObject();

	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-100.0f, 0.0f, 0.0f));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(2.0f, 2.0f, 1.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	g_house->drawObject();
	
	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(100.0f, 0.0f, 0.0f));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(2.0f, 2.0f, 1.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]); 
	g_car1->drawObject();
	
	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(300.0f, 0.0f, 0.0f));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(2.0f, 2.0f, 1.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]); 
	g_cocktail->drawObject();
	
	//glLoadIdentity();
	ModelMatrix = glm::mat4(1.0f);
	ModelMatrix = glm::translate(ModelMatrix, glm::vec3(500.0f, 0.0f, 0.0f));
	//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-200.0f, 0.0f, 0.0f));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(2.0f, 2.0f, 1.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]); 
	g_car2->drawObject();
	

	//glFlush();	
	glutSwapBuffers();
	glDisable(GL_TEXTURE_2D);
	//glEnd();
}   

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: // ESC key
		glutLeaveMainLoop(); // Incur destuction callback for cleanups.
		break;
	}
}

void reshape(int width, int height) {
	win_width = width, win_height = height;
	
  	glViewport(0, 0, win_width, win_height);
	glMatrixMode(GL_PROJECTION),
	ProjectionMatrix = glm::ortho(-win_width / 2.0, win_width / 2.0, 
		-win_height / 2.0, win_height / 2.0, -1000.0, 1000.0);
	ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;

	glMatrixMode(GL_MODELVIEW);
	g_axes->setWinSize(glm::vec2(win_width, win_height));
	g_axes->updateObjcet();

	g_line->setWinSize(glm::vec2(win_width, win_height));
	g_line->updateObjcet();

	glutPostRedisplay();
}

void cleanup(void) {
	g_axes->cleanup();
	delete g_axes;

	g_line->cleanup();
	delete g_line;

	g_airPlane->cleanup();
	delete g_airPlane;

	g_shirt->cleanup();
	delete g_shirt;

	g_house->cleanup();
	delete g_house;

	g_car1->cleanup();
	delete g_car1;

	g_cocktail->cleanup();
	delete g_cocktail;

	g_car2->cleanup();
	delete g_car2;
}

void register_callbacks(void) {
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutCloseFunc(cleanup);
}

void prepare_shader_program(void) {
	ShaderInfo shader_info[3] = {
		{ GL_VERTEX_SHADER, "Shaders/simple.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/simple.frag" },
		{ GL_NONE, NULL }
	};

	h_ShaderProgram = LoadShaders(shader_info);
	glUseProgram(h_ShaderProgram);

	loc_ModelViewProjectionMatrix = glGetUniformLocation(h_ShaderProgram, "u_ModelViewProjectionMatrix");
	loc_primitive_color = glGetUniformLocation(h_ShaderProgram, "u_primitive_color");
}

void initialize_OpenGL(void) {
	glEnable(GL_MULTISAMPLE); 
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	glClearColor(250 / 255.0f, 128 / 255.0f, 114 / 255.0f, 1.0f);
	ViewMatrix = glm::mat4(1.0f);
}

void prepare_scene(void) {
	g_axes = new axesClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_axes->initObject(win_width, win_height);
	g_line = new lineClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_line->initObject(win_width, win_height);
	g_airPlane = new airplaneClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_airPlane->initObject();
	g_shirt = new shirtClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_shirt->initObject();
	g_house = new houseClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_house->initObject();
	g_car1 = new car1Class(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_car1->initObject();
	g_cocktail = new cocktailClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_cocktail->initObject();
	//prepare_shirt();
	//prepare_house();
	//prepare_car();
	//prepare_cocktail();
	g_car2 = new car2Class(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_car2->initObject();
	//prepare_car2();
	
}

void initialize_renderer(void) {
	register_callbacks();
	prepare_shader_program(); 
	initialize_OpenGL();
	prepare_scene();
}

void initialize_glew(void) {
	GLenum error;

	glewExperimental = GL_TRUE;

    error = glewInit();
	if (error != GLEW_OK) { 
		fprintf(stderr, "Error: %s\n", glewGetErrorString(error));
		exit(-1);
	}
	fprintf(stdout, "*********************************************************\n");
	fprintf(stdout, " - GLEW version supported: %s\n", glewGetString(GLEW_VERSION));
	fprintf(stdout, " - OpenGL renderer: %s\n", glGetString(GL_RENDERER));
	fprintf(stdout, " - OpenGL version supported: %s\n", glGetString(GL_VERSION));
	fprintf(stdout, "*********************************************************\n\n");
}

void greetings(char *program_name, char messages[][256], int n_message_lines) {
	fprintf(stdout, "**************************************************************\n\n");
	fprintf(stdout, "  PROGRAM NAME: %s\n\n", program_name);
	fprintf(stdout, "    This program was coded for CSE4170 students\n");
	fprintf(stdout, "      of Dept. of Comp. Sci. & Eng., Sogang University.\n\n");

	for (int i = 0; i < n_message_lines; i++)
		fprintf(stdout, "%s\n", messages[i]);
	fprintf(stdout, "\n**************************************************************\n\n");

	initialize_glew();
}

#define N_MESSAGE_LINES 1
int main(int argc, char *argv[]) {
	char program_name[64] = "20131612 Choe Daeun";
	char messages[N_MESSAGE_LINES][256] = {
		"    - Keys used: 'ESC' "
	};

	glutInit (&argc, argv);
 	glutInitDisplayMode(GLUT_RGBA | GLUT_MULTISAMPLE | GLUT_DOUBLE);
	glutInitWindowSize (1280, 1024);
	glutInitContextVersion(4, 0);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(program_name);

	greetings(program_name, messages, N_MESSAGE_LINES);
	initialize_renderer();

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutMainLoop ();

	return 0;
}


