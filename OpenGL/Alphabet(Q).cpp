#include <GL/glut.h>
#include <stdlib.h>
GLfloat T = 0;
// void Spin()
// {
// 	T = T + 0.03;
// 	if(T>360)
// 	T = 0;
// 	glutPostRedisplay();
// }
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
	Face(V4, V5, V6, V7);//front
	glColor3f(1, 0.4, 0);
	Face(V0, V3, V7, V4);//left
	glColor3f(1, 0.5, 1);
	Face(V1, V2, V6, V5);//right
	glColor3f(0.5, 0.6, 1);
	Face(V0, V1, V5, V4);//top
	glColor3f(0.5, 0.4, 1);
	Face(V2, V3, V7, V6);//bottom
}
void Draw() {
	GLfloat V[8][3] = { {-0.2, 0.2, 0.3},
							 {-0.1, 0.2, 0.3},
							 {-0.1, -0.2, 0.3},
							 {-0.2, -0.2, 0.3},

							 {-0.2, 0.2, -0.3},
							 {-0.1, 0.2, -0.3},
							 {-0.1, -0.2, -0.3},
							 {-0.2, -0.2, -0.3},
	};
	GLfloat V1[8][3] = { {0.1, 0.2, 0.3},
							 {0.2, 0.2, 0.3},
							 {0.2, -0.2, 0.3},
							 {0.1, -0.2, 0.3},


							 {0.1, 0.2, -0.3},
							 {0.2, 0.2, -0.3},
							 {0.2, -0.2, -0.3},
							 {0.1, -0.2, -0.3},
	};
	GLfloat V2[8][3] = { {-0.2, 0.2, 0.3},
						{0.2, 0.2, 0.3},
						{0.2, 0.1, 0.3},
						{-0.2, 0.1, 0.3},

						{-0.2, 0.2, -0.3},
						{0.2, 0.2, -0.3},
						{0.2, 0.1, -0.3},
						{-0.2, 0.1, -0.3},
	};

	GLfloat V3[8][3] = { {-0.2, -0.2, 0.3},
						{0.2, -0.2, 0.3},
						{0.2, -0.3, 0.3},
						{-0.2, -0.3, 0.3},

						{-0.2, -0.2, -0.3},
						{0.2, -0.2, -0.3},
						{0.2, -0.3, -0.3},
						{-0.2, -0.3, -0.3},
	};

	GLfloat V4[8][3] = { {0, -0.1, 0.3},
						{0.05, -0.05, 0.3},
						{0.3, -0.35, 0.3},
						{0.2, -0.45, 0.3},

						{0, -0.1, -0.3},
						{0.05, -0.05, -0.3},
						{0.3, -0.35, -0.3},
						{0.2, -0.45, -0.3},
	};
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	//glRotatef(T,1,1,1);//for spinning
	glRotatef(3, 1, 1, -1);//for stationary
	Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
	Cube(V1[0], V1[1], V1[2], V1[3], V1[4], V1[5], V1[6], V1[7]);
	Cube(V2[0], V2[1], V2[2], V2[3], V2[4], V2[5], V2[6], V2[7]);
	Cube(V3[0], V3[1], V3[2], V3[3], V3[4], V3[5], V3[6], V3[7]);
	Cube(V4[0], V4[1], V4[2], V4[3], V4[4], V4[5], V4[6], V4[7]);

	glutSwapBuffers();
}

int main(int C, char* V[])
{
	glutInit(&C, V);

	glutInitWindowPosition(250, 50);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("SAMMAN");
	MyInit();
	glutDisplayFunc(Draw);
	//glutIdleFunc(Spin); //spinning
	glutMainLoop();

	return 0;
}
