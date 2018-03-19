//CG GRPAHICS MAJOR PROJECT DEVELOPED BY BIPIN, HARI, SHARAT

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
#include "GLUT/glut.h"
#else
#include <GL/glut.h>
#endif

// Define the value of PI, upto 12 decimal places
#define PI 3.141592653589

// ID to detect which scene the story is in.
int SCENE_ID=0;

//function declarations
void ArmyScene();

// Variables for Animator Faders
GLfloat title_fade,
        intro_next_text_appear;

/**/
// Function to Create Delay
void delay(float secs) {
    float end = clock()/CLOCKS_PER_SEC + secs;
    while((clock()/CLOCKS_PER_SEC) < end);
}



// Function to Draw Circle
void drawCircle(GLfloat x, GLfloat y,
                GLfloat r, GLfloat g, GLfloat b,
                GLfloat sx, GLfloat sy,
                GLfloat radius)
{
    glPushMatrix();

    glTranslatef(x, y, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

    glPopMatrix();
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



void introduction() {


    glClearColor(0.95, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Story Title
    print("THE EPIC BATTLE OF THERMOPHYLAE",
          0, 0, 0, title_fade, 280, 380, .3, .3, 2);

    print("by Hari, Bipin, Sharat",
          1, 1, 1, title_fade, 790, 345, .15, .15, 1);
    print("(1DS15CS029, 1DS15CS040, 1DS15CS029)",
          1, 1, 1, title_fade, 840, 320, .1, .1, 1);

    print("Press Y to proceed",
          1, 1, 1, intro_next_text_appear, 560, 10, .09, .09, 1);

}



// Function to Draw Kid's Head
void drawArmy(GLfloat tx, GLfloat ty,GLfloat radius, GLfloat r,GLfloat g,GLfloat b) {
    glPushMatrix();

    glTranslatef(tx, ty, 0);

    // army face
    drawCircle(tx,ty,
               r,g,b, // Lighter Skin
               1, 1,
               radius);

    int spear;

    //the army
    spear = tx+25;
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);

    glVertex2f(spear,ty-10);
    glVertex2f(spear,ty+40);
    glEnd();
    glLineWidth(10);

    //arrow
    glBegin(GL_LINES);
    glColor3f(1, 1, 0);

    glVertex2f(spear,ty+40);
    glVertex2f(spear,ty+50);

    glEnd();
    glLineWidth(1);

    glPopMatrix();
}

void ArmyScene()
{
    int i=0,j=1;
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

//    drawArmy(60,60,25);s
//    drawArmy(120,60,25);
//    drawArmy(180,60,25);

    for(j=1; j<10; ++j)
        for(i=1; i<30; i++)
        {
            drawArmy(i*30 - j * 10, j*40 - 5*j + 10,10 - 0.1*j ,232, 190, 123);
            drawArmy(i*30 - j * 10, j*40 - 5*j,25 - 0.5*j,182, 190, 23);
            //drawArmy(i*30,j*35,25);
        }


}

// Animator Updation Function
void update(int) {
    // Introduction
    if (SCENE_ID == 0) {
        if (title_fade < 1)
            title_fade += .003;
        else
            intro_next_text_appear = 1;
    }


    if (SCENE_ID == 1) {
       ArmyScene();
    }


    // Recalls the Display Function
    glutPostRedisplay();

    // Creates a Timer of 25ms
    glutTimerFunc(25, update, 0);
}






// Function to Render Scene
void renderScene() {
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    switch (SCENE_ID) {
	case 0:
		introduction();
		break;
	case 1:
		ArmyScene();
		break;
    default: break;

       }

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
        std::cout<<(SCENE_ID);

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
    glutKeyboardFunc(keyPress);
    glutMouseFunc(mouseClick);

    initializeScreen();
    // Timer Function
    // every 25 milliseconds, update function is called
    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return 0;
}
