#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

static int vertical = 0, horizontal = 0;

static float light_x = 1.0f, light_y = 1.0f, light_z = 1.0f;

void init(void) 
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 90.0 };
   GLfloat light_position[] = { light_x, light_y , light_z, 0.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}



void display(void)
{
   GLfloat light_position[] = { light_x, light_y, light_z, 0.0 };
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);   
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 0.0);
   glPushMatrix();
   glRotatef ((GLfloat) vertical, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) horizontal, 0.0, 1.0, 0.0);
   glutWireSphere(1.0, 20, 16);     
   glPopMatrix();
   glutSwapBuffers();
   
}



void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}



void keyboard (unsigned char key, int x, int y)
{

   switch (key) {
      case 'w': //up
         light_y++;
         glutPostRedisplay();
         break;
      case 's': //down
         light_y--;
         glutPostRedisplay();
         break;
      case 'a': //left
         light_x--;
         glutPostRedisplay();
         break;
      case 'd': //right
         light_x++;
         glutPostRedisplay();
         break;
      case 'h': // horizontal rotation
         horizontal = (horizontal + 10) % 360;
         glutPostRedisplay();
         break;      
      case 'v': // vertical rotation
         vertical = (vertical + 5) % 360;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}


int main(int argc, char** argv)
{

   const int WINDOW_SIZE_WIDTH = 500;
   const int WINDOW_SIZE_HEIGHT = 500;
   const int WINDOW_POSITION_X = 100;
   const int WINDOW_POSITION_Y = 100;	
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT); 
   glutInitWindowPosition (WINDOW_POSITION_X, WINDOW_POSITION_Y);
   glutCreateWindow (argv[1]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

