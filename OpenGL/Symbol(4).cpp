#include <GL/glut.h>
#include <stdlib.h>
GLfloat T = 0;
void MyInit() {
	glClearColor(0, 0, 0, 1);
	glColor3f(1, 0, 0);
	glEnable(GL_DEPTH_TEST);
}
void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
	glBegin(GL_POLYGON);
	glVertex3fv(A);
	glVertex3fv(B);
	glVertex3fv(C);
	glVertex3fv(D);
	glEnd();
}
void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
	glColor3f(0.6, 0, 0.6);
	Face(V0, V1, V2, V3);//back
	glColor3f(0.5, 0.9, 0.5);
	Face(V4, V5, V6, V7);
	glColor3f(1, 0.4, 0);
	Face(V0, V3, V7, V4);
	glColor3f(1, 0.5, 1);
	Face(V1, V2, V6, V5);
	glColor3f(0.5, 0.6, 1);
	Face(V0, V1, V5, V4);
	glColor3f(0.5, 0.4, 1);
	Face(V2, V3, V7, V6);
}
void Draw() {
	GLfloat V[8][3] = { {-0.2, 0.3, 0.3},
							 {-0.1, 0.3, 0.3},
							 {-0.1, -0.1, 0.3},
							 {-0.2, -0.1, 0.3},

							{-0.2, 0.3, -0.3},
							 {-0.1, 0.3, -0.3},
							 {-0.1, -0.1, -0.3},
							 {-0.2, -0.1, -0.3},
	};
	GLfloat V2[8][3] = { {-0.2, 0, 0.3},
						{0.2, 0, 0.3},
						{0.2, -0.1, 0.3},
						{-0.2, -0.1, 0.3},

						{-0.2, 0, -0.3},
						{0.2, 0, -0.3},
						{0.2, -0.1, -0.3},
						{-0.2, -0.1, -0.3},
	};

	GLfloat V3[8][3] = { {0.1, 0.1, 0.3},
						{0.2, 0.3, 0.3},
						{0.2, -0.3, 0.3},
						{0.1, -0.3, 0.3},

						{0.1, 0.1, -0.3},
						{0.2, 0.3, -0.3},
						{0.2, -0.3, -0.3},
						{0.1, -0.3, -0.3},
	};



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(10, 1, 1, -1);
	Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
	Cube(V2[0], V2[1], V2[2], V2[3], V2[4], V2[5], V2[6], V2[7]);
	Cube(V3[0], V3[1], V3[2], V3[3], V3[4], V3[5], V3[6], V3[7]);

	glutSwapBuffers();
}

int main(int C, char* V[])
{
	glutInit(&C, V);

	glutInitWindowPosition(250, 50);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Swastika");
	MyInit();
	glutDisplayFunc(Draw);
	glutMainLoop();

	return 0;
}
