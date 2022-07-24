#include<GLUT/glut.h>
#include<math.h>

void Draw() 
{
	GLfloat x1 = 120, y1 = 50, x2 = 300, y2 = 350;
	GLfloat x, y, dx, dy, p, M, t;
	glClear(GL_COLOR_BUFFER_BIT);

		if ((x2-x1) == 0)
			M = (y2-y1);
		else
			M = (y2-y1)/(x2-x1);

		if (fabs(M) < 1)
		{
			if (x1 > x2)
			{
				t = x1;
				x1 = x2;
				x2 = t;

				t = y1;
				y1 = y2;
				y2 = t;
			}

			dx = fabs(x2-x1);
			dy = fabs(y2-y1);
			p  = 2*dy-dx;

			x = x1;
			y = y1;

			glBegin(GL_POINTS);
			while (x <= x2)
			{
				glVertex2f(x,y);
				x = x + 1;

				if (p > 0)
				{
					if (M < 1)
						y += 1;
					else
						y -= 1;
					p += 2*dy - 2*dx;
				}
				else
				{
					y = y;
					p += 2*dy;
				}
			}
			glEnd();
		}

		if (fabs(M) >= 1)
		{
			if (y1 > y2)
			{
				t = x1;
				x1 = x2;
				x2 = t;

				t = y1;
				y1 = y2;
				y2 = t;
			}

			dx = fabs(x2-x1);
			dy = fabs(y2-y1);
			p  = 2*dx-dy;

			x = x1;
			y = y1;

			glBegin(GL_POINTS);
			while (y <= y2)
			{
				glVertex2f(x,y);
				y = y + 1;

				if (p > 0)
				{
					if (M < 1)
						x += 1;
					else
						x -= 1;
					p += 2*dx - 2*dy;
				}
				else
				{
					x = x;
					p += 2*dx;
				}
			}
			glEnd();
		}
	glFlush();

}

void MyInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	MyInit();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
