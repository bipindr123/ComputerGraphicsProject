#include <iostream>
#include <unistd.h>
#include <time.h>
#include <math.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
	#include "GLUT/glut.h"
#else
	#include "GL\glut.h"
#endif

// Define the value of PI, upto 12 decimal places
#define PI 3.141592653589

// ID to detect which scene the story is in.
int SCENE_ID;

// Variables for Animator Faders
GLfloat title_fade,
	intro_next_text_appear, summary_next_text_appear,
	summary_para1_fade, summary_para2_fade, summary_para3_fade, summary_para4_fade,
	kg_chap_fade, kg_title_fade,
	kg_a_fade, kg_apple_fade, kg_b_fade, kg_ball_fade, kg_soon_fade, kg_subtitle_1_appear,
	ps_chap_fade, ps_title_fade,
	ps_subtitle_1_appear, ps_subtitle_2_appear,
	hs_chap_fade, hs_title_fade,
	hs_subtitle_1_appear,
	puc_chap_fade, puc_title_fade,
	puc_subtitle_1_fade,
	eng_chap_fade, eng_title_fade,
	ec_subtitle_1_fade,
	wp_chap_fade, wp_title_fade,
	wp_subtitle_1_fade,
	epilogue_para1_fade, epilogue_para2_fade, epilogue_para3_fade, epilogue_para4_fade, epilogue_para5_fade, epilogue_para6_fade,
	moral_para1_fade, moral_para2_fade, moral_para3_fade, moral_para4_fade;

// Variables for Translation Animators
GLfloat trans_x_chap1, trans_x_title1,
	trans_x_chap2, trans_y_title2,
	trans_x_kid1, trans_x_kid2, trans_x_kid3, trans_x_ball,
	trans_subtitle_1_done, trans_subtitle_2_done,
	trans_x_chap3, trans_x_title3,
	trans_x_chap4, trans_x_title4,
	sun_move_left,
	schoolboy_x = 1150, schoolboy_y = 5220,
	trans_x_sb1 = -630, trans_y_sb1 = -50, trans_x_sb2 = -1630, trans_y_sb2 = -50,
	trans_x_chap5, trans_x_title5,
	trans_x_ec_sb1 = 850, trans_x_ec_sb2 = -1000, trans_y_ec_sb = 40, trans_x_ec_gb = -180, trans_y_ec_gb = 1040,
	trans_x_chap6, trans_x_title6;

// Variables for Color Morphers
GLfloat window_top_r = 59, window_top_g = 91, window_top_b = 132,
	window_bottom_r = 97, window_bottom_g = 131, window_bottom_b = 159,
	sky_r = 12, sky_g = 172, sky_b = 232,
	grass_r = 82, grass_g =  163, grass_b = 42,
	sun_r = 251, sun_g = 255, sun_b = 163;

// Variables for Turn-based Switching
bool sun_moved_half, sun_has_set, stars_are_made,
	chapter_1_done, chapter_2_done, chapter_3_done, chapter_4_done, chapter_5_done, tuition_done,
	puc_begin_anim, puc_end_anim,
	ec_graduation_done;

// Variables for Random Star Generation
int star_alpha, no_of_stars, stars_array[40][2];

// Function to Create Delay
void delay(float secs) {
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}




// Function to Print Text
void print(char *string,
	GLfloat r, GLfloat g, GLfloat b, GLfloat a,
	GLint x, GLint y,
	GLfloat w, GLfloat h,
	GLfloat strokeSize) {
	glPushMatrix();

	glColor4f(r, g, b, a);
	glTranslatef(x, y, 0);
	glScalef(w, h, 0);

	glPointSize(strokeSize);
	glLineWidth(strokeSize);

	while (*string)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *string++);

	glPopMatrix();

	glLineWidth(1);
	glPointSize(1);
}

//
// Animator Updation Function
void update(int) {
	// Introduction
	if (SCENE_ID == 0) {
		if (title_fade < 1)
			title_fade += .003;
		else
			intro_next_text_appear = 1;
	}

	// Summary
	if (SCENE_ID == 1) {
		if (summary_para1_fade < 1)
			summary_para1_fade += .02;
		else
			if (summary_para2_fade < 1)
				summary_para2_fade += .02;
			else
				if (summary_para3_fade < 1)
					summary_para3_fade += .02;
				else
					if (summary_para4_fade < 1)
						summary_para4_fade += .02;
					else
						summary_next_text_appear = 1;
	}


	// Recalls the Display Function
	glutPostRedisplay();

	// Creates a Timer of 25ms
	glutTimerFunc(25, update, 0);
}



void introduction() {
	// Background
	//hello

	glClearColor(0.05, 0.05, 0.05, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Story Title
	print("THE EPIC BATTLE OF THERMOPHYLAE",
		1, 1, 1, title_fade, 280, 380, .3, .3, 2);

	print("by Hari, Bipin, Sharat",
		1, 1, 1, title_fade, 790, 345, .15, .15, 1);
	print("(1DS15CS029, 1DS15CS040, 1DS15CS029)",
		1, 1, 1, title_fade, 840, 320, .1, .1, 1);

	print("Press Y to proceed",
		1, 1, 1, intro_next_text_appear, 560, 10, .09, .09, 1);
}


// Function to Render Scene
void renderScene() {
	introduction();


	// glFush sends it to the Display Buffer
	glFlush();
}


// Keyboard Action
void keyPress(unsigned char key, int x, int y) {
	switch (key) {
	// Go to Previous Scene
	case 'b':
	case 'B':
		if (SCENE_ID == 0)
			break;
		SCENE_ID--;
		break;
	// Go to Next Scene
	case 'n':
	case 'N':
		if (SCENE_ID == 15)
			break;
		SCENE_ID++;
		break;
	// Quit Story
	case 'q':
	case 'Q':
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

// Function to Handle Mouse Clicks
void mouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		std::cout << x << "\t" << 800 - y << "\n";
}

// Function to Initialize Screen
void initializeScreen() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1400, 0, 800);
}

// Main Function
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1400, 800);
	glutCreateWindow("SPARTAA!!");

	// Enables Transparency
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	// Enable Smoothening
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	// Display Function
	glutDisplayFunc(renderScene);

	// Input Functions
	glutMouseFunc(mouseClick);

	initializeScreen();

	// Timer Function
	// every 25 milliseconds, update function is called
	glutTimerFunc(25, update, 0);

	glutMainLoop();

	return 0;
}
