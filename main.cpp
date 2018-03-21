//CG GRPAHICS MAJOR PROJECT DEVELOPED BY BIPIN, HARI, SHARAT

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
#include "GLUT/glut.h"
#else

#include <glut.h>

#endif

// Define the value of PI, upto 12 decimal places
#define PI 3.141592653589
int i=1,j=1, k=1, counter=1;
// ID to detect which scene the story is in.
int SCENE_ID = 0;

//function declarations
void ArmyScene();

void drawArmy(GLfloat tx, GLfloat ty, GLfloat radius, GLfloat r, GLfloat g, GLfloat b);

// Variables for Animator Faders
GLfloat title_fade,
        intro_next_text_appear;

/**/
// Function to Create Delay
void delay(float secs) {
    float end = clock() / CLOCKS_PER_SEC + secs;
    while ((clock() / CLOCKS_PER_SEC) < end);
}


// Function to Draw Circle
void drawCircle(GLfloat x, GLfloat y,
                GLfloat r, GLfloat g, GLfloat b,
                GLfloat sx, GLfloat sy,
                GLfloat radius) {
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

// Draw Dead Trees

void deadtrees(int x, int y) {
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + 30, y);
    glVertex2i(x + 28, y + 80);
    glVertex2i(x + 8, y + 80);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(x + 10, y + 80);
    glVertex2i(x + 28, y + 80);
    glVertex2i(x + 38, y + 110);
    glVertex2i(x + 28, y + 110);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(x + 28, y + 80);
    glVertex2i(x + 8, y + 80);
    glVertex2i(x - 15, y + 100);
    glVertex2i(x - 15, y + 110);
    glEnd();

}

void grass_a(int x, int y, int width, int height) {
    i = x;
    for (j = 0; j < height; j++) {
        for (k = 0; k < width; k++) {
            glBegin(GL_TRIANGLES);
            glVertex2f(x, y);
            glVertex2f(x + 10, y);
            glVertex2f(x + 5, y + 15);
            glVertex2f(x, y);
            glVertex2f(x + 12, y);
            glVertex2f(x - 5, y + 10);
            glVertex2f(x - 3, y);
            glVertex2f(x + 10, y);
            glVertex2f(x + 15, y + 10);
            glEnd();
            x += 16;
        }
        y += 8;
        x = i;
    }
}


void circle_a(GLfloat x, GLfloat y, GLdouble radius) {
    float x2, y2;
    float angle;
    glPointSize(2.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (angle = 1.0; angle < 361.0f; angle += 0.2) {
        x2 = x + sin(angle) * radius;
        y2 = y + cos(angle) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();
}

void cloud_a(int x, int y, int r, int i) {
    circle_a(x + i, y, r);
    circle_a(x + i, y, r);
    circle_a(x + 10 + i, y + 30, r - 10);
    circle_a(x + 55 + i, y + 20, r + 10);
    circle_a(x + 100 + i, y + 25, r - 5);
    circle_a(x + 90 + i, y, r + 10);
    circle_a(x + 120 + i, y + 15, r - 10);
}

void aliveTrees(int x, int y) {
    circle_a(x - 5, y + 100, 35);
    /*circle_a(x - 5, y + 100, 35);*/
    circle_a(x - 30, y + 120, 35);
    circle_a(x - 8, y + 150, 35);
    circle_a(x + 40, y + 100, 35);
    circle_a(x + 35, y + 150, 35);
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + 30, y);
    glVertex2i(x + 28, y + 80);
    glVertex2i(x + 8, y + 80);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(x + 10, y + 80);
    glVertex2i(x + 28, y + 80);
    glVertex2i(x + 38, y + 110);
    glVertex2i(x + 28, y + 110);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(x + 28, y + 80);
    glVertex2i(x + 8, y + 80);
    glVertex2i(x - 15, y + 100);
    glVertex2i(x - 15, y + 110);
    glEnd();
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

    print("Press N (next) to proceed",
          1, 1, 1, intro_next_text_appear, 560, 10, .09, .09, 1);

}

void fullArmy() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);

    //ground
    glColor3f(0.5, 1.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 300.0);
    glVertex2f(1400.0, 300.0);
    glVertex2f(1400.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glEnd();

    //sky
    glColor3ub(71, 160, 255);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 300.0);
    glVertex2f(1400.0, 300.0);
    glVertex2f(1400.0, 800.0);
    glVertex2f(0.0, 800.0);
    glEnd();

    //sun
    glColor3ub(255, 242, 0);
    circle_a(400, 600, 70.0);

    //cloud_a
    glColor3f(1.0, 1.0, 1.0);
    cloud_a(800, 600, 30, -counter);
    glColor3f(1.0, 1.0, 1.0);
    cloud_a(100, 680, 30, counter);


    std::cout<<" THIS IS COUNTER "<<counter<<"\n";

    // mountains
    glColor3ub(153, 68, 22);
    circle_a(213.33, 491.5, 29.5);
    glBegin(GL_POLYGON);
    glVertex2f(0, 300);
    glVertex2f(183.33, 500);
    glVertex2f(243.33, 500);
    glVertex2f(426.67, 300);
    glEnd();


    circle_a(640.0, 491.5, 29.5);
    glBegin(GL_POLYGON);
    glVertex2f(426.67, 300);
    glVertex2f(610, 500);
    glVertex2f(670, 500);
    glVertex2f(853.33, 300);
    glEnd();


    circle_a(1066.66, 491.5, 29.5);
    glBegin(GL_POLYGON);
    glVertex2f(853.33, 300);
    glVertex2f(1036.6, 500);
    glVertex2f(1096.6, 500);
    glVertex2f(1400, 300);
    glEnd();

    //grass_a
    glColor3f(0, 0.2, 0);
    int j;

    for(j=70;j<300;j=j+70)
    {
        for(i=80;i<1200;i=i+80)
        {
            grass_a(i,j,1,1);
        }
    }

    for (j = 0; j < 5; ++j)
        for (i = 0; i < 40; i++) {
            drawArmy(i * 30 - j * 10, j * 40 - 5 * j + 10, 10 - 0.1 * j, 232, 190, 123);
            drawArmy(i * 30 - j * 10, j * 40 - 5 * j, 20 - 0.5 * j, 182, 190, 23);
        }

    glFlush();


}


//Deser Army

void desertArmy() {


    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);



    //ground
    glColor3f(1.0, 0.9, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 300.0);
    glVertex2f(1400.0, 300.0);
    glVertex2f(1400.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glEnd();

    //sky

    glColor3f(0.8, 0.8, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 300.0);
    glVertex2f(1400.0, 300.0);
    glVertex2f(1400.0, 800.0);
    glVertex2f(0.0, 800.0);
    glEnd();

    //sun

    glColor3f(1.0, 0.3, 0.0);
    circle_a(426.67, 370.0, 70.0);

    //clouds

    glColor3f(1.0, 1.0, 1.0);
    cloud_a(800, 600, 30, -counter);
    glColor3f(1.0, 1.0, 1.0);
    cloud_a(100, 680, 30, counter);

    // mountains
    glColor3f(0.7, 0.3, 0.0);
    circle_a(213.33, 491.5, 29.5);
    glColor3f(0.7, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 300);
    glVertex2f(183.33, 500);
    glVertex2f(243.33, 500);
    glVertex2f(426.67, 300);
    glEnd();

    glColor3f(0.7, 0.3, 0.0);
    circle_a(640.0, 491.5, 29.5);
    glBegin(GL_POLYGON);
    glVertex2f(426.67, 300);
    glVertex2f(610, 500);
    glVertex2f(670, 500);
    glVertex2f(853.33, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(853.33, 300);
    glVertex2f(1036.6, 500);
    glVertex2f(1096.6, 500);
    glVertex2f(1400, 300);
    glEnd();

    glColor3f(0.8, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(700, 300);
    glVertex2f(853.33, 450);
    glVertex2f(1006.66, 300);
    glEnd();

    glColor3f(0.7, 0.3, 0.0);
    circle_a(1066.66, 491.5, 29.5);
    glBegin(GL_POLYGON);
    glVertex2f(853.33, 300);
    glVertex2f(1036.6, 500);
    glVertex2f(1096.6, 500);
    glVertex2f(1400, 300);
    glEnd();





    //trees
    glColor3f(0, 0.5, 0);
    deadtrees(50, 270);
    deadtrees(650, 230);
    deadtrees(850, 270);
    deadtrees(1050, 230);
    deadtrees(1250, 200);



    for (j = 1; j < 4; ++j)
        for (i = 5; i < 10; i++) {
            drawArmy(i * 30 - j * 10 + counter, j * 40 - 5 * j + 10, 10 - 0.1 * j, 232, 190, 123);
            drawArmy(i * 30 - j * 10 + counter, j * 40 - 5 * j, 25 - 0.5 * j, 182, 190, 23);
            //drawArmy(i*30,j*35,25);
        }


    glFlush();


}

// Function to Draw Kid's Head
void drawArmy(GLfloat tx, GLfloat ty, GLfloat radius, GLfloat r, GLfloat g, GLfloat b) {
    glPushMatrix();

    glTranslatef(tx, ty, 0);

    // army face
    drawCircle(tx, ty,
               r, g, b, // Lighter Skin
               1, 1,
               radius);

    int spear;

    //the army
    spear = tx + 25;
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);

    glVertex2f(spear, ty - 10);
    glVertex2f(spear, ty + 40);
    glEnd();
    glLineWidth(10);

    //arrow
    glBegin(GL_LINES);
    glColor3f(1, 1, 0);

    glVertex2f(spear, ty + 40);
    glVertex2f(spear, ty + 50);

    glEnd();
    glLineWidth(1);

    glPopMatrix();
}

void ArmyScene() {
    int i = 0, j = 1;
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

//    drawArmy(60,60,25);s
//    drawArmy(120,60,25);
//    drawArmy(180,60,25);

    for (j = 1; j < 10; ++j)
        for (i = 1; i < 30; i++) {
            drawArmy(i * 30 - j * 10, j * 40 - 5 * j + 10, 10 - 0.1 * j, 232, 190, 123);
            drawArmy(i * 30 - j * 10, j * 40 - 5 * j, 25 - 0.5 * j, 182, 190, 23);
            //drawArmy(i*30,j*35,25);
        }


}

// Animator Updation Function
void update(int) {
    // Introduction
    if (SCENE_ID == 0) {
        if (title_fade < 1)
            title_fade += .010;
        else
            intro_next_text_appear = 1;
    }


    if (SCENE_ID == 1) {
       counter++;
    }


    if (SCENE_ID == 2) {
       counter++;
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
            desertArmy();
            break;
        case 2:
            fullArmy();
            break;
        default:
            break;

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
            std::cout << (SCENE_ID);

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
