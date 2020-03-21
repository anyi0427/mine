#include <Windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926

float RSaoKim = 2.5;
float RTraiDat = RSaoKim * 149600 / 108200;

void drawCircle(float x0, float y0, float R, int n = 40) {
	float x, y;
	float angleinc = 2 * PI / n;
	float angle;

	glBegin(GL_LINE_LOOP);
	angle = 0;
	x = R * cos(angle);
	y = R * sin(angle);
	glVertex2f(x, y);
	for (int i = 1; i < n; i++) {
		angle += angleinc;
		x = R * cos(angle);
		y = R * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
}


void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawCircle(0, 0, RSaoKim);
	drawCircle(0, 0, RTraiDat);

	float angleTraiDatInc = 4;
	float factor = 365.25636 / 224.7008;
	float angleSaoKimInc = factor * angleTraiDatInc;
	float xTraiDat, yTraiDat;
	float xSaoKim, ySaoKim;
	float angleTraiDat = 90, angleSaoKim = 90;
	glBegin(GL_LINES);
	for (int i = 0; i <= (360.0 / angleTraiDatInc) * 8; i++) {
		angleTraiDat -= angleTraiDatInc;
		angleSaoKim -= angleSaoKimInc;
		xTraiDat = RTraiDat * cos(angleTraiDat * PI / 180);
		yTraiDat = RTraiDat * sin(angleTraiDat * PI / 180);
		xSaoKim = RSaoKim * cos(angleSaoKim * PI / 180);
		ySaoKim = RSaoKim * sin(angleSaoKim * PI / 180);
		glVertex2f(xTraiDat, yTraiDat);
		glVertex2f(xSaoKim, ySaoKim);
	}
	glEnd();

	glFlush();
}

void init() {
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.5, 4.5, -4.5, 4.5, -1.0, 1.0);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(":)");

	glutDisplayFunc(myDisplay);
	init();
	glutMainLoop();
}