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
#define NUMBER_OF_AIRPLANES 2
#define NUMBER_OF_HEARTOBJ 100
// MARK: Create Object;
axesClass *g_axes;
lineClass *g_line;
airplaneClass *g_airPlane[NUMBER_OF_AIRPLANES];
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
minimapClass *g_minimap;
boxClass* g_heartObj[NUMBER_OF_HEARTOBJ];
//marcoClass *g_marco;
//minimapPointClass *g_minimapPoint;

int heartobjCreatecount = 0;
int heartobjCurrent = 0;
int airplane_clock = 0;
float airplane_s_factor = 1.0f;
bool keyState[108] = { 0 };
int shapeType = 0;

void lerptimer(int);


void keySpecialOperation() {
	Object* obj = g_airPlane[0];
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
	glm::vec3 yourView = g_airPlane[0]->getPosition();
	yourView.y += 140.0f;

	//printf("%f %f\n", yourView.x-g_minimap->getPosition().x, yourView.y - g_minimap->getPosition().y);
	//yourView.x = -170.0f;
	if (g_airPlane[0]->getPosition().x < -170.0f) {
		yourView.x = -170.0f;
	}
	if (g_airPlane[0]->getPosition().x > 170.0f) {
		yourView.x = 170.0f;
	}

	g_minimap->setPosition(glm::vec3(yourView.x + 438.0f, yourView.y - 176.0f, 0.0f));
	g_minimap->setHeroPosition(g_airPlane[0]->getPosition());
	for (int i = 0; i < NUMBER_OF_STRUCTURES; i++) {
		glm::vec3 position = g_house[i]->getPosition();
		position.y -= 60.0f;
		g_minimap->setStructuresPosition(i, position);
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
	Object* obj = g_airPlane[0];

	

	keySpecialOperation();
	//g_airPlane[1]->heartFuncMotion();
	for (int i = 0; i < heartobjCreatecount; i++) {
		int type = shapeType;//g_heartObj[i]->getMotionType();
		if (type == 0)
			g_heartObj[i]->heartFuncMotion();
		else if (type == 1)
			g_heartObj[i]->sinFuncMotion();
		else if (type == 2)
			g_heartObj[i]->cosFuncMotion();
	}
	g_minimap->setCollided(Object::AABBIntersection(
		g_airPlane[0]->getCollisionBox(),
		g_minimap->getCollisionBox()
	));
	//printf("%f %f\n", g_heartObj->getPosition().x, g_heartObj->getPosition().y);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//g_axes->drawObject(ViewProjectionMatrix);
	
	

	for (int i = 0; i < NUMBER_OF_HOUSES; i++)
	{
		g_house[i]->drawObject(ViewProjectionMatrix);
	}
	for (int i = 0; i < NUMBER_OF_BLOCKTILES; i++) {
		g_blockTile[i]->drawObject(ViewProjectionMatrix);
	}
	for (int i = 0; i < NUMBER_OF_BOXES; i++) {
		g_box[i]->drawObject(ViewProjectionMatrix);
	}
	g_text->drawObject(ViewProjectionMatrix);
	for (int i = 0; i < NUMBER_OF_AIRPLANES-1; i++) {
		g_airPlane[i]->drawObject(ViewProjectionMatrix);
	}

	g_minimap->drawObject(ViewProjectionMatrix);
	
	for (int i = 0; i < heartobjCreatecount; i++) {
		g_heartObj[i]->drawObject(ViewProjectionMatrix);
	}

	//g_marco->drawObject(ViewProjectionMatrix);
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
	case 97:/* KEY A */
		lerptimer(0);
		heartobjCurrent = 0;
		//glutTimerFunc(100, lerptimer, 0);
		shapeType++;
		shapeType = shapeType % 3;
		
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

	for (int i = 0; i < NUMBER_OF_AIRPLANES; i++) {
		g_airPlane[i]->cleanup();
		delete g_airPlane[i];
	}

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

	g_minimap->cleanup();
	delete g_minimap;

	for (int i = 0; i < heartobjCreatecount; i++) {
		g_heartObj[i]->cleanup();
		delete g_heartObj[i];
	}

	//g_marco->cleanup();
	//delete g_marco;

	/*g_minimapPoint->cleanup();
	delete g_minimapPoint;*/
}

void timer(int)
{
	//g_airPlane[1]->circularMotion();
	//printf("timer\n");
	/* update animation */
	//glutPostRedisplay();
	//glutTimerFunc(100, timer, 0);
	g_heartObj[heartobjCreatecount] = new boxClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_heartObj[heartobjCreatecount]->initObject();
	g_heartObj[heartobjCreatecount]->setScale(0.3f);
	g_heartObj[heartobjCreatecount]->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	if (heartobjCreatecount < NUMBER_OF_HEARTOBJ) {
		heartobjCreatecount++;
		glutTimerFunc(100, timer, 0);
	}
}
void lerptimer(int)
{
	for (int i = 0; i < heartobjCreatecount; i++) {
		g_heartObj[i]->setElapedTime(0.0f);
		g_heartObj[i]->setTimeStep(0.001f);
		g_heartObj[i]->setMotionType(shapeType);
	/*if (heartobjCurrent < heartobjCreatecount && heartobjCurrent < NUMBER_OF_HEARTOBJ) {
		heartobjCurrent++;
		glutTimerFunc(100, lerptimer, 0);
	}*/
	}
}


void register_callbacks(void) {
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutCloseFunc(cleanup);
	glutSpecialFunc(keySpecial);
	glutSpecialUpFunc(keySpecialUp);
	glutMotionFunc(mouseMotion);
	glutTimerFunc(100, timer, 0);
	//glutTimerFunc(500, lerptimer, 0);
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
	for (int i = 0; i < NUMBER_OF_AIRPLANES; i++) {
		g_airPlane[i] = new airplaneClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
		g_airPlane[i]->initObject();
		g_airPlane[i]->setRotate(180);
		g_airPlane[i]->setRadius(70.0f);
	}
	//g_shirt = new shirtClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	//g_shirt->initObject();
	//g_shirt->setScale(1.5f);
	for (int i = 0; i < NUMBER_OF_HOUSES; i++) {
		g_house[i] = new houseClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
		
		g_house[i]->setScale(8.0f);
	}
	g_house[0]->initObject();
	g_house[0]->setScale(9.0f);
	g_house[0]->setPosition(glm::vec3(337.0f, 128.0f, -50.0f));

	g_house[1]->initObject();
	g_house[1]->setPosition(glm::vec3(175.0f, 114.0f, -30.0f));
	g_house[1]->setColor(
		glm::vec3(185 / 255.0f, 122 / 255.0f, 86 / 255.0f), glm::vec3(171 / 255.0f, 73 / 255.0f, 93 / 255.0f),
		glm::vec3(88 / 255.0f, 88 / 255.0f, 88 / 255.0f), glm::vec3(160 / 255.0f, 122 / 255.0f, 100 / 255.0f),
		glm::vec3(0 / 255.0f, 168 / 255.0f, 243 / 255.0f)
	);

	g_house[2]->initObject(HOUSE_ARMORY);
	g_house[2]->setPosition(glm::vec3(-250.0f, 114.0f, -30.0f));

	g_house[3]->initObject(HOUSE_SHOP);
	g_house[3]->setPosition(glm::vec3(-534.0f, 114.0f, -30.0f));
	g_house[3]->setColor(
		glm::vec3(76.0f / 255.0f, 46.0f / 255.0f, 39.0f / 255.0f), glm::vec3(33.0f / 255.0f, 107.0f / 255.0f, 58.0f / 255.0f),
		glm::vec3(249.0f / 255.0f, 191.0f / 255.0f, 30.0f / 255.0f), glm::vec3(211.0f / 255.0f, 179.0f / 255.0f, 132.0f / 255.0f),
		glm::vec3(202.0f / 255.0f, 139.0f / 255.0f, 67.0f / 255.0f)
	);

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

	g_minimap = new minimapClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_minimap->initObject();
	g_minimap->setPosition(glm::vec3(438.0f, -36.0f, 0.0f));

	/*g_minimapPoint = new minimapPointClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	g_minimapPoint->initObject();*/

	//g_marco = new marcoClass(loc_ModelViewProjectionMatrix, loc_primitive_color);
	//g_marco->initObject();

	

	
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


