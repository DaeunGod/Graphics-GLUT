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

#define NUMBER_OF_HOUSES 4
#define NUMBER_OF_BLOCKTILES 88
#define NUMBER_OF_BOXES 5
// MARK: Create Object;
axesClass *g_axes;
lineClass *g_line;
airplaneClass *g_airPlane;
//shirtClass *g_shirt;
houseClass *g_house[NUMBER_OF_HOUSES];
car1Class *g_car1;
cocktailClass *g_cocktail;
car2Class *g_car2;
boxClass *g_box[NUMBER_OF_BOXES];
//swordClass *g_sword;
cloudClass *g_cloud;
blockTileClass *g_blockTile[NUMBER_OF_BLOCKTILES];
textClass *g_text;

int airplane_clock = 0;
float airplane_s_factor = 1.0f;
bool keyState[108] = { 0 };



void keySpecialOperation() {
	Object* obj = g_airPlane;
	if (obj != NULL) {
		if (keyState[GLUT_KEY_LEFT] == true) {
			obj->setPosition(obj->getPosition() - glm::vec3(3.0f, 0.0f, 0.0f));
		}
		if (keyState[GLUT_KEY_RIGHT] == true) {
			obj->setPosition(obj->getPosition() + glm::vec3(3.0f, 0.0f, 0.0f));
		}
		if (keyState[GLUT_KEY_UP] == true) {
			obj->setPosition(obj->getPosition() + glm::vec3(0.0f, 3.0f, 0.0f));
		}
		if (keyState[GLUT_KEY_DOWN] == true) {
			obj->setPosition(obj->getPosition() - glm::vec3(0.0f, 3.0f, 0.0f));
		}
	}
}

void viewUpdate(int width, int height) {
	glm::vec3 yourView = g_airPlane->getPosition();
	yourView.y += 130.0f;
	//yourView.x = -170.0f;
	if (g_airPlane->getPosition().x < -170.0f) {
		yourView.x = -170.0f;
	}
	if (g_airPlane->getPosition().x > 170.0f) {
		yourView.x = 170.0f;
	}
	ViewMatrix = glm::translate(glm::mat4(1.0f) , -yourView);
	glViewport(0, 0, win_width, win_height);
	glMatrixMode(GL_PROJECTION),
		ProjectionMatrix = glm::ortho(-win_width / 2.0, win_width / 2.0,
			-win_height / 2.0, win_height / 2.0, -1000.0, 1000.0);
	ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;
	glMatrixMode(GL_MODELVIEW);
}


void display(void) {
	//int i;
	//float x, r, s, delx, delr, dels;
	glm::mat4 ModelMatrix;
	Object* obj = g_box[2];

	keySpecialOperation();
	
	//printf("%f %f\n", obj->getPosition().x, obj->getPosition().y);



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	g_axes->drawObject(ViewProjectionMatrix);
	
	/*g_line->drawObject(ViewProjectionMatrix);
	g_airPlane->drawObject(ViewProjectionMatrix);
	g_shirt->drawObject(ViewProjectionMatrix);
	g_house->drawObject(ViewProjectionMatrix);
	g_car1->drawObject(ViewProjectionMatrix);
	
	g_cocktail->drawObject(ViewProjectionMatrix);
	g_car2->drawObject(ViewProjectionMatrix);*/
	//g_box->setPosition(glm::vec3(-500.0f, 0.0f, 0.f));

	for (int i = 0; i < NUMBER_OF_HOUSES; i++)
	{
		g_house[i]->drawObject(ViewProjectionMatrix);
	}
	for (int i = 0; i < NUMBER_OF_BLOCKTILES; i++) {
		g_blockTile[i]->drawObject(ViewProjectionMatrix);
	}
	//g_line->drawObject(ViewProjectionMatrix);
	//g_sword->drawObject(ViewProjectionMatrix);
	for (int i = 0; i < NUMBER_OF_BOXES; i++) {
		g_box[i]->drawObject(ViewProjectionMatrix);
	}
	//g_shirt->drawObject(ViewProjectionMatrix);
	//g_cloud->drawObject(ViewProjectionMatrix);
	g_text->drawObject(ViewProjectionMatrix);
	g_airPlane->drawObject(ViewProjectionMatrix);

	//glFlush();	
	glutSwapBuffers();
	//glEnd();
	viewUpdate(win_width, win_height);
	glutPostRedisplay();
}   

void keyboard(unsigned char key, int x, int y) {
	//printf("%d", key);
	switch (key) {
	case 27: // ESC key
		glutLeaveMainLoop(); // Incur destuction callback for cleanups.
		break;
	case 97:
		//g_sword->setScale(g_sword->getScale().x+1);
		break;
	case 98:
		//g_sword->setScale(g_sword->getScale().x - 1);
		break;
	}
}

void keySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		keyState[GLUT_KEY_LEFT] = true;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		keyState[GLUT_KEY_RIGHT] = true;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		keyState[GLUT_KEY_DOWN] = true;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		keyState[GLUT_KEY_UP] = true;
		glutPostRedisplay();
		break;
	}
}

void keySpecialUp(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		keyState[GLUT_KEY_LEFT] = false;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		keyState[GLUT_KEY_RIGHT] = false;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		keyState[GLUT_KEY_DOWN] = false;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		keyState[GLUT_KEY_UP] = false;
		glutPostRedisplay();
		break;
	}
}



void reshape(int width, int height) {
	memset(keyState, 0, sizeof(keyState));
	win_width = width, win_height = height;
	viewUpdate(win_width, win_height);
	/*win_width = width, win_height = height;
	ViewMatrix = glm::translate(ViewMatrix, g_box->getPosition());
  	glViewport(0, 0, win_width, win_height);
	glMatrixMode(GL_PROJECTION),
	ProjectionMatrix = glm::ortho(-win_width / 2.0, win_width / 2.0, 
		-win_height / 2.0, win_height / 2.0, -1000.0, 1000.0);
	ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;*/

	//glMatrixMode(GL_MODELVIEW);
	g_axes->setWinSize(glm::vec2(win_width, win_height));
	g_axes->updateObjcet();

	g_line->setWinSize(glm::vec2(win_width, win_height));
	g_line->setPosition(glm::vec2(-600.0f, 100.0f), glm::vec2(1024.0f, -100.0f));
	g_line->updateObjcet();
	
	

	glutPostRedisplay();
}

void mouseMotion(int x, int y) {
	
}

void cleanup(void) {
	g_axes->cleanup();
	delete g_axes;

	g_line->cleanup();
	delete g_line;

	g_airPlane->cleanup();
	delete g_airPlane;

	//g_shirt->cleanup();
	//delete g_shirt;

	for (int i = 0; i < NUMBER_OF_HOUSES; i++)
	{
		g_house[i]->cleanup();
		delete g_house[i];
	}

	g_car1->cleanup();
	delete g_car1;

	g_cocktail->cleanup();
	delete g_cocktail;

	g_car2->cleanup();
	delete g_car2;

	for (int i = 0; i < NUMBER_OF_BOXES; i++) {
		g_box[i]->cleanup();
		delete g_box[i];
	}

	/*g_sword->cleanup();
	delete g_sword;*/

	g_cloud->cleanup();
	delete g_cloud;
	for (int i = 0; i < NUMBER_OF_BLOCKTILES; i++) {
		g_blockTile[i]->cleanup();
		delete g_blockTile[i];
	}

	delete g_text;
}

void register_callbacks(void) {
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutCloseFunc(cleanup);
	glutSpecialFunc(keySpecial);
	glutSpecialUpFunc(keySpecialUp);
	glutMotionFunc(mouseMotion);
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
	g_airPlane->setRotate(180);
	//g_shirt = new shirtClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	//g_shirt->initObject();
	//g_shirt->setScale(1.5f);
	for (int i = 0; i < NUMBER_OF_HOUSES; i++) {
		g_house[i] = new houseClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
		
		g_house[i]->setScale(8.0f);
	}
	g_house[0]->initObject();
	g_house[0]->setScale(9.0f);
	g_house[0]->setPosition(glm::vec3(267.0f, 128.0f, -50.0f));

	g_house[1]->initObject();
	g_house[1]->setPosition(glm::vec3(105.0f, 114.0f, -30.0f));
	g_house[1]->setColor(
		glm::vec3(185 / 255.0f, 122 / 255.0f, 86 / 255.0f), glm::vec3(171 / 255.0f, 73 / 255.0f, 93 / 255.0f),
		glm::vec3(88 / 255.0f, 88 / 255.0f, 88 / 255.0f), glm::vec3(160 / 255.0f, 122 / 255.0f, 100 / 255.0f),
		glm::vec3(0 / 255.0f, 168 / 255.0f, 243 / 255.0f)
	);

	g_house[2]->initObject(HOUSE_ARMORY);
	g_house[2]->setPosition(glm::vec3(-250.0f, 114.0f, -30.0f));

	g_house[3]->initObject(HOUSE_SHOP);
	g_house[3]->setPosition(glm::vec3(-534.0f, 114.0f, -30.0f));

	g_car1 = new car1Class(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_car1->initObject();
	g_cocktail = new cocktailClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_cocktail->initObject();
	g_car2 = new car2Class(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_car2->initObject();

	for (int i = 0; i < NUMBER_OF_BOXES; i++) {
		g_box[i] = new boxClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
		g_box[i]->initObject();
		g_box[i]->setScale(0.7f);
	}
	g_box[0]->setPosition(glm::vec3(-207.0f, 14.0f, 0.0f)); 
	g_box[1]->setPosition(glm::vec3(-186.0f, 13.5f, 0.0f));
	g_box[2]->setPosition(glm::vec3(-195.0f, 42.0f, 0.0f));
	g_box[3]->setPosition(glm::vec3(-426, 14.0f, 0.0f));
	g_box[4]->setPosition(glm::vec3(-450.0f, 14.0f, 0.0f));
	g_box[1]->setRotate(90.0f);
	g_box[2]->setRotate(-90.0f);
	g_box[4]->setRotate(-97.0f);

	/*g_sword = new swordClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_sword->initObject();
	g_sword->setScale(2.0f);
	g_sword->setPosition(g_house[2]->getPosition() + glm::vec3(114.0f, -39.0f, 0.0f));
	g_sword->setRotateType(1);
	g_sword->setRotate(0, glm::vec3(0.0f, 1.0f, 0.0));*/
	//g_sword->setRotate(60.0f);

	g_cloud = new cloudClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_cloud->initObject();

	for (int i = 0; i < NUMBER_OF_BLOCKTILES; i++) {
		g_blockTile[i] = new blockTileClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
		g_blockTile[i]->initObject();
		g_blockTile[i]->setPosition(glm::vec3(-700.0f+i*80.0f, -18.0f, 0.0f));
	}

	g_text = new textClass(loc_ModelViewProjectionMatrix, loc_primitive_color, "abadfasdfasdfasdfasdf");
	//g_box->setScale(5.0f);
	//prepare_car2();
	
}

void initialize_renderer(void) {
	register_callbacks();
	prepare_shader_program(); 
	initialize_OpenGL();
	prepare_scene();
	//glPolygonMode(GL_FRONT, GL_FILL);
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
	glutInitWindowSize (1024, 500);
	glutInitContextVersion(4, 0);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(program_name);

	greetings(program_name, messages, N_MESSAGE_LINES);
	initialize_renderer();

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutMainLoop ();

	return 0;
}


