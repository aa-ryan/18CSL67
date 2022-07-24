#define GL_SILENCE_DEPRECATION
#include<stdio.h>
#include<GLUT/glut.h>

GLfloat px, py, R;

void Draw() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(0.1, 0.8);
		glVertex2f(0.8, 0.4);
		glVertex2f(0.1, 0.4);
	glEnd();


	glLoadIdentity();

	glTranslatef(px, py, 0.0);
	glRotatef(R, 0, 0, 1);
	glTranslatef(-px, -py, 0.0);
	
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(0.1, 0.8);
		glVertex2f(0.8, 0.4);
		glVertex2f(0.1, 0.4);
	glEnd();


	glFlush();
}
int main(int argc, char *argv[])
{
	int ch;
	printf("Enter the choice of Rotation:\n1.About Origin\t2.About Fixed Point\n");
	scanf("%d", &ch);
	if (ch == 1) 
	{
		px = 0;
		py = 0;
		printf("Enter the rotation angle: ");
		scanf("%f", &R);
	}
	else 
	{
		printf("Enter the Rotation Point: ");
		scanf("%f%f", &px, &py);
		printf("Enter the rotation angle: ");
		scanf("%f", &R);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Triangle Rotation");
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
