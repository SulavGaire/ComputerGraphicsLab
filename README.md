
# Setting up graphics.h in VS Code(C++)

1. Download graphics header file from [here](https://drive.google.com/file/d/16xZBvFXf7yFjxwTpuyevK1KPuLgUeZFh/view)
2. Download and install tdm-gcc 32bit compiler.
3. Copy files from include and lib folder from graphics folder file you downloaded in step 1 to include and lib folder of tdm-gcc 32bit.
4. Open VS Code and create a new project folder and open C/C++ configuration.
5. In the configuration setting set compiler path to C:/TDM-GCC-32/bin/g++.exe (this location may be different).
6. Paste following to compiler arguments. 
-lbgi 
-lgdi32 
-lcomdlg32 
-luuid 
-loleaut32 
-lole32
7. Set C++ standard to c++11
8. Write some codes and build the code with followin config: 

      ![image](https://user-images.githubusercontent.com/55276059/152299456-2e5d2717-3530-4102-a84a-380ccaf49fe3.png)
      
9. Then you are good to go.

# Setting up graphics.h in Sublime Text 3(C++)

1. Download the above BGI file from thefunkydude/ComputerGraphicsLab.
2. Copy the file to path c:/dev.
3. Make sure that mingw is added to the environment variables.
4. Open your sublime text and follow the setps: tools->Build system->New build system.
5. Copy the following code and paste it to the new build system:
      ```
      {
        "shell_cmd": "g++ -std=c++17 \"${file}\" -IC:\\dev\\BGI -LC:\\dev\\BGI -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -o \"${file_path}/${file_base_name}\" &&                start cmd /c \"title ${file_base_name}.exe && \"${file_path}/${file_base_name}\" && echo. && echo. && pause\"",
        "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
        "working_dir": "${file_path}",
        "selector": "source.c++",
      }
      ```
      
6. Save the build system with extension .sublime-build.
7. Select the build system you just saved from the tools menu and you are good to go.
8. Check with a testfile.cpp as:
      ```
      #include<graphics.h>
      int main()
      {
        initwindow(400,400,"TEST FILE");
        rectangle(50,100,200,250);
        //your code
        getch();
        closegraph();
        }
      ```
      

# Setting up Opengl (freeglut) in sublime text3 (c++)
- Build code for now:
```
      {
        "shell_cmd": "g++ -std=c++17 \"${file}\" ‐IC:\\freeglut\\include ‐LC:\\freeglut\\lib ‐w ‐Wl,‐subsystem,windows ‐lOpenGL32 ‐lglu32 ‐lfreeGLUT -o \"${file_base_name}\"             && start cmd /c \"title ${file_base_name}.exe && \"${file_path}/${file_base_name}\" && echo. && echo. && pause\"",
        "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
        "working_dir": "${file_path}",
        "selector": "source.c++",
      }
```
      
      
- A test code drawing a triangle taken from [This site](https://cs.lmu.edu/~ray/notes/openglexamples/).
```
      #include<Gl/glut.h>

      void display() {

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POLYGON);
          glVertex3f(-0.6, -0.75, 0.5);
          glVertex3f(0.6, -0.75, 0);
          glVertex3f(0, 0.75, 0);

        glEnd();

        glFlush();
      }

      int main(int argc, char** argv) {

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);


        glutInitWindowPosition(80, 80);
        glutInitWindowSize(400, 300);
        glutCreateWindow("A Simple Triangle");

        glutDisplayFunc(display);
        glutMainLoop();
      }
```


#Setting up OpenGL(freeglut) in Visual Studio

1. Download free glew and glut from [here](http://www.mediafire.com/file/cmlnr0pj0pyha5d/Glew_and_Glut.zip/file)
2. Extract the files in a folder you desire.(you need the folder so never delete it unless you donot want to do opengl anymore)
3. Open Visual Studio and create a C++ solution/project.
4. Go to the properties of your project.
 ![image](https://user-images.githubusercontent.com/55276059/156544423-93256c2f-c779-41cb-a2e7-0793a4879032.png)
5. Inside properties go to C/C++ and in additional include directories include the include folders from the files you dowloaded before.
![image](https://user-images.githubusercontent.com/55276059/156544972-aa1594c0-e7db-455a-a654-04335f869573.png)
6. Go to general of linker section and in additional library directories include the lib folders from the files you downloaded before.
![image](https://user-images.githubusercontent.com/55276059/156545285-c22c1b0b-a163-4b36-857e-bafcabc938ff.png)
7. In the input of linker section add following in additional dependencies. 
   -freeglut.lib
   -glew32.lib
   ![image](https://user-images.githubusercontent.com/55276059/156545541-ef37ab0a-5807-47d0-ba1b-a9041cf4d20e.png)
8. Copy and paste following files you downloaded before in System32 folder.
![image](https://user-images.githubusercontent.com/55276059/156545796-6eed6463-563d-486c-9da9-97553c3a387c.png)
9. Now copy the code and build your project and run it, then you are good to go.
```
      #include<Gl/glut.h>

      void display() {

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POLYGON);
          glVertex3f(-0.6, -0.75, 0.5);
          glVertex3f(0.6, -0.75, 0);
          glVertex3f(0, 0.75, 0);

        glEnd();

        glFlush();
      }

      int main(int argc, char** argv) {

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);


        glutInitWindowPosition(80, 80);
        glutInitWindowSize(400, 300);
        glutCreateWindow("A Simple Triangle");

        glutDisplayFunc(display);
        glutMainLoop();
      }
```




















