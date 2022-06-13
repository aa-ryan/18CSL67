#define GL_SILENCE_DEPRECATION
#include<GLUT/glut.h>
#include<stdio.h>

int opt=1;
void triangle()
{
	glBegin(GL_POLYGON);
	glVertex2f(5,5);
	glVertex2f(10,5);
	glVertex2f(7.5,10);  // fixed point
	glEnd();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(opt==1)
	{
		triangle();
		glRotatef(45,0,0,1);
		glColor3f(1.0,0.0,0.0);
		triangle();
	}
	else
	{
		triangle();
		glTranslated(7.5,10,0);
		glRotatef(45,0,0,1);
		glTranslated(-7.5,-10,0);
		glColor3f(0.0,1.0,0.0);
		triangle();
	}
	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20,20,-20,20,-1.0,1.0);
}
int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	printf("Enter choice for Rotation\n1) About origin\n2) About Fixed point\n");
	scanf("%d",&opt);
	init();
	glutMainLoop();
}

