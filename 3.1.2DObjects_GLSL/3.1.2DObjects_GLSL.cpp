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
boxClass *g_box;

int airplane_clock = 0;
float airplane_s_factor = 1.0f;

void display(void) {
	int i;
	float x, r, s, delx, delr, dels;
	glm::mat4 ModelMatrix;

	glClear(GL_COLOR_BUFFER_BIT);
	
	g_axes->drawObject(ViewProjectionMatrix);
	/*g_line->drawObject(ViewProjectionMatrix);
	g_airPlane->drawObject(ViewProjectionMatrix);
	g_shirt->drawObject(ViewProjectionMatrix);
	g_house->drawObject(ViewProjectionMatrix);
	g_car1->drawObject(ViewProjectionMatrix);
	
	g_cocktail->drawObject(ViewProjectionMatrix);
	g_car2->drawObject(ViewProjectionMatrix);*/

	g_box->drawObject(ViewProjectionMatrix);
	

	//glFlush();	
	glutSwapBuffers();
	//glEnd();
}   

void keyboard(unsigned char key, int x, int y) {
	printf("%d\n", key);
	switch (key) {
	case 27: // ESC key
		glutLeaveMainLoop(); // Incur destuction callback for cleanups.
		break;
	}
}

void special(int key, int x, int y) {
//#define SENSITIVITY 2.0
	switch (key) {
	case GLUT_KEY_LEFT:
		g_airPlane->setPosition(g_airPlane->getPosition() - glm::vec3(1.0f, 0.0f, 0.0f));
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		glutPostRedisplay();
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

	g_box->cleanup();
	delete g_box;
}

void register_callbacks(void) {
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutCloseFunc(cleanup);
	glutSpecialFunc(special);
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
	g_shirt->setScale(2.0f);
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

	g_box = new boxClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_box->initObject();
	//g_box->setScale(5.0f);
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


