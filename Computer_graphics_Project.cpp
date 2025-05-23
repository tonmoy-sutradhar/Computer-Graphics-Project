#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include<mmsystem.h>
# define PI           3.14159265358979323846
static float SunCenterY = -0.3f;
float offsetX = 0.0f;
float offsetY = 0.0f;
float movementSpeed = 0.01f;
float maxOffset = 1.9f;

//sea weave
float waveOffset = -0.1f;
float waveSpeed = 0.01f;

void drawWhiteCirlce(float centerX, float centerY, float horizontalRadius, float verticalRadius) {
    int numSegments = 100;
    float angleStep = 2.0f * M_PI / numSegments;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i <= numSegments; i++) {
        float angle = i * angleStep;
        float x = horizontalRadius * cos(angle);
        float y = verticalRadius * sin(angle);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}
void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void halfcircle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 51; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void hillTree()
{
    glPushMatrix();
    glTranslated(-15,6,0);
    glScaled(0.5,0.2,0);
    glPushMatrix();
    glTranslated(-1,-10,1);
    glColor3f(0.55,0.27,0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(1.0,10.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5,0,0);
    glScaled(0.4,1,1);
    glPushMatrix();
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(7,6);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,1.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5,-0.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0,6.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,-3.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5,-3.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}
void RIGHTcloud() {
    static float centerX = 1.1f;
    static float deltaX = -0.00014f;
    static float maxX = 1.5f;
    static float minX = -1.5f;

    // Update cloud position
    centerX += deltaX;

    // Reset position if it goes off the left edge
    if (centerX < minX) {
        centerX = maxX;
    }

    // Draw the cloud
    drawWhiteCirlce(centerX, 0.78f, 0.08f, 0.11f);
    drawWhiteCirlce(centerX - 0.06f, 0.78f, 0.06f, 0.07f);
    drawWhiteCirlce(centerX + 0.06f, 0.78f, 0.06f, 0.07f);
}

void LEFTcloud() {
    static float centerX = -1.1f;
    static float deltaX = 0.00014f;
    static float maxX = 1.5f;
    static float minX = -1.5f;

    // Update cloud position
    centerX += deltaX;

    if (centerX > maxX) {
        centerX = minX;
    }

    // Draw the cloud
    drawWhiteCirlce(centerX, 0.55f, 0.08f, 0.11f);
    drawWhiteCirlce(centerX - 0.06f, 0.55f, 0.06f, 0.07f);
    drawWhiteCirlce(centerX + 0.06f, 0.55f, 0.06f, 0.07f);
}
void SECONDLEFTcloud() {
    static float centerX = -1.5f;
    static float deltaX = 0.00014f;
    static float maxX = 1.5f;
    static float minX = -1.5f;
    centerX += deltaX;

    if (centerX > maxX) {
        centerX = minX;
    }

    // Draw the cloud
    drawWhiteCirlce(centerX, 0.65f, 0.08f, 0.11f);
    drawWhiteCirlce(centerX - 0.06f, 0.65f, 0.06f, 0.07f);
    drawWhiteCirlce(centerX + 0.06f, 0.65f, 0.06f, 0.07f);
}

void CLOUD(){
    RIGHTcloud();
    LEFTcloud();
    SECONDLEFTcloud();
}

void SUN() {

    static float minY = -0.3f;
    static float maxY = 1.2f;
    static float riseY = 0.8f;
    static float deltaY = 0.0003f;
    static bool rising = true;
    static bool setting = false;

    float centerX = 0.0f, horizontalRadius = 0.06f, verticalRadius = 0.1f;
    int numSegments = 100;
    float angleStep = 2.0f * M_PI / numSegments;

    // Keyboard handling for controlling the sun's movement
    if (GetAsyncKeyState('A')) {
        rising = true;
        setting = false;
    }
    if (GetAsyncKeyState('B')) {
        setting = true;
        rising = false;
    }

    // Update sun position based on user input
    if (rising) {
        SunCenterY += deltaY;
        if (SunCenterY >= riseY) {
            SunCenterY = riseY;
            rising = false;
        }
    }
    if (setting) {
        SunCenterY += deltaY;
        if (SunCenterY >= maxY) {
            SunCenterY = minY;
            setting = false;
        }
    }

    // Draw the sun
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.51f, 0.0f);
    for (int i = 0; i <= numSegments; i++) {
        float angle = i * angleStep;
        float x = horizontalRadius * cos(angle);
        float y = verticalRadius * sin(angle);
        glVertex2f(centerX + x, SunCenterY + y);
    }
    glEnd();

    // Swap buffers and refresh display
    glutSwapBuffers();
    glutPostRedisplay();
}

void house()
{
    glPushMatrix();
    glTranslatef(-1.1f, -1.80f, 0.0f);
    glScalef(1.0f, 2.5f, 1.0f);

    // Base part of the house
    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45);
    glVertex2f(0.2968, 0.8798);
    glVertex2f(0.1946, 0.7761);
    glVertex2f(0.2383, 0.7763);
    glVertex2f(0.328, 0.862);
    glEnd();

    // Left wall of the house
    glBegin(GL_POLYGON);
   glColor3ub(0, 0, 128);
    glVertex2f(0.252127, 0.729066);
    glVertex2f(0.251, 0.789);
    glVertex2f(0.328, 0.862);
    glVertex2f(0.407, 0.815);
    glVertex2f(0.405, 0.72);
    glEnd();

    // Right wall of the house
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 128);
    glVertex2f(0.407, 0.815);
    glVertex2f(0.405, 0.72);
    glVertex2f(0.643079, 0.728021);
    glVertex2f(0.643, 0.798);
    glEnd();

    // Roof of the house
    glBegin(GL_POLYGON);
    glColor3ub(255, 165, 0);
    glVertex2f(0.296807, 0.879882);
    glVertex2f(0.445814, 0.792193);
    glVertex2f(0.7, 0.8);
    glVertex2f(0.584871, 0.86981);
    glEnd();

    // Vertical line (edge)
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.407, 0.815);
    glVertex2f(0.405, 0.72);
    glEnd();

    // Window (small rectangle)
    glBegin(GL_POLYGON);
    glColor3ub(255, 253, 208);
    glVertex2f(0.307, 0.82);
    glVertex2f(0.36, 0.82);
    glVertex2f(0.36, 0.78);
    glVertex2f(0.307, 0.78);
    glEnd();

    // Door (correctly placed black rectangle)
    glBegin(GL_POLYGON);
    glColor3ub(255, 253, 208);
    glVertex2f(0.49f, 0.72f);
    glVertex2f(0.54f, 0.72f);
    glVertex2f(0.54f, 0.78f);
    glVertex2f(0.49f, 0.78f);
    glEnd();

    glPopMatrix();
}


void moveBoat1() {
    static float centerX = 0.5f;
    static float deltaX = 0.0001f;
    static float maxX = 1.5f;
    static float minX = -1.5f;
    centerX += deltaX;

    // Reset position if it goes off the right edge
    if (centerX > maxX) {
        centerX = minX;
    }


    // Draw Boat 1
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(centerX, -0.8f);
    glVertex2f(centerX + 0.1f, -0.9f);
    glVertex2f(centerX + 0.2f, -0.9f);
    glVertex2f(centerX + 0.3f, -0.8f);
    glEnd();

    // Boat Sail
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(centerX + 0.16f, -0.8f);
    glVertex2f(centerX + 0.16f, -0.6f);
    glVertex2f(centerX + 0.22f, -0.8f);
    glEnd();
}
void moveBoat2() {
    static float centerX = -0.1f;
    static float deltaX = 0.0001f;
    static float maxX = 1.5f;
    static float minX = -1.5f;

    // Update boat position
    centerX += deltaX;

    // Reset position if it goes off the right edge
    if (centerX > maxX) {
        centerX = minX;
    }

    // Draw Boat 2
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(centerX, -0.6f);
    glVertex2f(centerX + 0.1f, -0.7f);
    glVertex2f(centerX + 0.2f, -0.7f);
    glVertex2f(centerX + 0.3f, -0.6f);
    glEnd();

    // Boat Sail
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(centerX + 0.05f, -0.6f);
    glVertex2f(centerX + 0.05f, -0.4f);
    glVertex2f(centerX + 0.15f, -0.6f);
    glEnd();
}

void moveBoat3() {
    static float centerX = -1.0f;
    static float deltaX = 0.0001f;
    static float maxX = 1.5f;
    static float minX = -1.5f;

    // Update boat position
    centerX += deltaX;

    // Reset position if it goes off the right edge
    if (centerX > maxX) {
        centerX = minX;
    }

    // Draw Boat 3
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(centerX, -0.7f);
    glVertex2f(centerX + 0.1f, -0.8f);
    glVertex2f(centerX + 0.2f, -0.8f);
    glVertex2f(centerX + 0.3f, -0.7f);
    glEnd();

    // Boat Sail
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(centerX + 0.05f, -0.7f);
    glVertex2f(centerX + 0.05f, -0.5f);
    glVertex2f(centerX + 0.15f, -0.7f);
    glEnd();
}

void renderScene() {
    moveBoat1();
    moveBoat2();
    moveBoat3();
    glutSwapBuffers();
}

void sound()
{
    PlaySound("bird.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void bird(float offsetX, float offsetY) {
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.78f + offsetX, 0.0f + offsetY);
    glVertex2f(-0.76f + offsetX, -0.04f + offsetY);
    glVertex2f(-0.73f + offsetX, 0.0f + offsetY);
    glVertex2f(-0.76f + offsetX, -0.04f + offsetY);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.77f + offsetX, 0.05f + offsetY);
    glVertex2f(-0.75f + offsetX, 0.01f + offsetY);
    glVertex2f(-0.72f + offsetX, 0.05f + offsetY);
    glVertex2f(-0.75f + offsetX, 0.01f + offsetY);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.66f + offsetX, 0.0f + offsetY);
    glVertex2f(-0.64f + offsetX, -0.04f + offsetY);
    glVertex2f(-0.61f + offsetX, 0.0f + offsetY);
    glVertex2f(-0.64f + offsetX, -0.04f + offsetY);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.7f + offsetX, 0.05f + offsetY);
    glVertex2f(-0.68f + offsetX, 0.01f + offsetY);
    glVertex2f(-0.65f + offsetX, 0.05f + offsetY);
    glVertex2f(-0.68f + offsetX, 0.01f + offsetY);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.62f + offsetX, 0.09f + offsetY);
    glVertex2f(-0.6f + offsetX, 0.06f + offsetY);
    glVertex2f(-0.57f + offsetX, 0.09f + offsetY);
    glVertex2f(-0.6f + offsetX, 0.06f + offsetY);
    glEnd();
}

void updateBird(int value) {
    float angleRadians = 30.0f * M_PI / 180.0f;
    offsetX += movementSpeed * cos(angleRadians);
    offsetY += movementSpeed * sin(angleRadians);

    if (abs(offsetX) > maxOffset || abs(offsetY) > maxOffset) {
        offsetX = -0.4f;
        offsetY = -0.4f;
    }

    glutPostRedisplay();

    glutTimerFunc(16, updateBird, 0);
}

//sea wave function
void updateWave(int value) {
    // Update wave offset to move along the x-axis
    waveOffset += waveSpeed;

    // Reset the waveOffset to create continuous flow (loop)
    if (waveOffset > 1.0f) {
        waveOffset = -1.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateWave, 0);
}


//Sound
bool soundOn = true;

// control sound
void keyboard(unsigned char key, int x, int y) {
    switch (key) {

        case 'c':
            if (soundOn) {
                sndPlaySound(NULL, SND_ASYNC);
                soundOn = false;
            } else {
                sndPlaySound("bird.wav", SND_ASYNC);
                soundOn = true;
            }
            break;
        default:
            break;
    }
}



//DIsplay function---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->>
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    /**........................................ Sky ...........................................**/
    glColor3f(0.4f, 0.69f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    SUN();
    CLOUD();


     bird(offsetX,offsetY);


    /**........................................ Sea ...........................................**/
    glColor3f(0.0f, 0.29f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    //sea waves
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    // Apply waveOffset to all lines
    glVertex2f(-0.48f + waveOffset, -0.2f);
    glVertex2f(-0.9f + waveOffset, -0.2f);

    glVertex2f(-0.4f + waveOffset, 0.0f);
    glVertex2f(-0.9f + waveOffset, 0.0f);

    glVertex2f(-1.9f + waveOffset, -0.4f);
    glVertex2f(-0.2f + waveOffset, -0.4f);

    glVertex2f(-1.8f + waveOffset, -0.1f);
    glVertex2f(-0.6f + waveOffset, -0.1f);

    glVertex2f(-1.7f + waveOffset, -0.6f);
    glVertex2f(0.2f + waveOffset, -0.6f);

    glVertex2f(-1.8f + waveOffset, -0.8f);
    glVertex2f(-0.4f + waveOffset, -0.8f);

    glVertex2f(-0.1f + waveOffset, -0.9f);
    glVertex2f(1.0f + waveOffset, -0.9f);

    glVertex2f(-0.5f + waveOffset, 0.1f);
    glVertex2f(0.4f + waveOffset, 0.1f);

    glVertex2f(0.0f + waveOffset, 0.0f);
    glVertex2f(0.5f + waveOffset, 0.0f);

    glVertex2f(0.8f + waveOffset, 0.0f);
    glVertex2f(1.8f + waveOffset, 0.0f);

    glVertex2f(0.5f + waveOffset, -0.6f);
    glVertex2f(1.7f + waveOffset, -0.6f);

    glVertex2f(0.3f + waveOffset, -0.4f);
    glVertex2f(1.93f + waveOffset, -0.4f);

    glVertex2f(0.8f + waveOffset, -0.3f);
    glVertex2f(1.9f + waveOffset, -0.3f);

    glVertex2f(0.89f + waveOffset, -0.2f);
    glVertex2f(2.0f + waveOffset, -0.2f);

    glVertex2f(-0.4f + waveOffset, -0.1f);
    glVertex2f(-0.08f + waveOffset, -0.1f);

    glEnd();


    /**........................................ Soil ...........................................**/
     glColor3ub(210, 180, 140);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(-1.0f, 0.1f);
    glEnd();

     /**........................................ Hill ..........................................**/
    glColor3f(0.13f, 0.54f, 0.13f);
    glBegin(GL_TRIANGLES);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(0.6f, 0.1f);
    glColor3f(0.56f, 0.93f, 0.56f);
    glVertex2f(0.8f, 0.5f);
    glEnd();

    glColor3f(0.13f, 0.54f, 0.13f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.7f, 0.1f);
    glVertex2f(0.3f, 0.1f);
     glColor3f(0.56f, 0.93f, 0.56f);
    glVertex2f(0.5f, 0.5f);
    glEnd();

    glColor3f(0.13f, 0.54f, 0.13f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.5f, 0.1f);
     glColor3f(0.56f, 0.93f, 0.56f);
    glVertex2f(0.3f, 0.4f);
    glEnd();

     hillTree();


    /**........................................Tree-1.......................................**/
   glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(0.7f, 0.1f);
    glVertex2f(0.8f, 0.1f);
    glVertex2f(0.8f, 0.4f);
    glVertex2f(0.7f, 0.4f);
    glEnd();

    // Draw Tree Leaves (green color)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(0.65f, 0.4f);
    glVertex2f(0.85f, 0.4f);
    glVertex2f(0.75f, 0.6f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.8f, 0.0f);
    glVertex2f(0.6f, 0.5f);
    glVertex2f(0.9f, 0.5f);
    glVertex2f(0.75f, 0.7f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.55f, 0.6f);
    glVertex2f(0.95f, 0.6f);
    glVertex2f(0.75f, 0.8f);
    glEnd();



     /**........................................Tree-2.......................................**/
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.3f, 0.1f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();

    // Draw Tree Leaves (green color)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.45f, 0.4f);
    glVertex2f(-0.25f, 0.4f);
    glVertex2f(-0.35f, 0.6f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.8f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.2f, 0.5f);
    glVertex2f(-0.35f, 0.7f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.55f, 0.6f);
    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.35f, 0.8f);
    glEnd();

    renderScene();
    house();
    //drawSea() ;
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(80, 50);
    glutCreateWindow("Vertex, Primitive & Color");
    glutDisplayFunc(display);
    sound();
    glutKeyboardFunc(keyboard);
     glutTimerFunc(16, updateBird, 0);
     glutTimerFunc(16, updateWave, 0);
    glutMainLoop();

    return 0;
}
