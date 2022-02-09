#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>



void reshape(int w,int h){
  //viewport x and y as bottom left corner
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); // reset parameters as is projection here

  // leftmost x-coordinate =-10, x_r = 10 y_bottom = -10 y_top = 10
  gluOrtho2D(-10,10,-10,10);
  glMatrixMode(GL_MODELVIEW);
}

// initial position of the block and state
float X_position = -10.0;
int state = 1;

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  //specifying the point pixel size
  glPointSize(10.0);
  //draw
  // specify vertices within glbegin and end
  // specify what to display in the parameter of begin like polygon or points
  glBegin(GL_POLYGON);
  //given co-ordinates of a square of 2 unit
  glVertex2f(X_position,1.0);
  glVertex2f(X_position,-1.0);
  glVertex2f(X_position+2.0,-1.0);
  glVertex2f(X_position+2.0,1.0);

  glEnd();
  //double buffer that we used have front and back buffer 
  //how we make this work is displaying front buffer drawing at back buffer and then swap the front and back buffer
  // resulting in smooth transitions
  glutSwapBuffers();
}


void timer(int){
  // redisplays the display function
  glutPostRedisplay();
  // parameters provided as 60 frames per 1000 milsec(1s) timer() and an int which is not used at all
  glutTimerFunc(1000/60,timer,0);
  // state 1 depicts need of moving to right side and -1 depicts need of moving to left accordingly position of x co-ordinates are changed resulting in 
  // horizontal motion of the block
  // for increasing speed we can change the const with which x_pos is increasing 0.15->0.30 doubles the speed
  switch(state)
  {
    case 1:
      if(X_position<8)
        X_position+=0.15;
      else state = -1;

      break;

    case -1:
    if(X_position >-10)
      X_position-=0.15;
    else state = 1;

  }
}








int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //double buffer display mode

  glutInitWindowPosition(200,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("A Moving Block");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(1000,timer,0);

  glutMainLoop();


  return 0;
}