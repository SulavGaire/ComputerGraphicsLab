# ComputerGraphicsLab
Just easier to copy code for assignment.

Yes, we still use graphics.h like a total fucking retard...

# Setting up graphics.h in VS Code(C++)

1. Download graphics header file. (https://drive.google.com/file/d/16xZBvFXf7yFjxwTpuyevK1KPuLgUeZFh/view)
2. Download and install tdm-gcc 32bit compiler.
3. Copy files from include and lib folder from graphics folder file you downloaded in step 1 to include and lib folder of tdm-gcc 32bit.
4. Open VS Code and create a new project folder and open C/C++ configuration.
5. In the configuration setting set compiler path to C:/TDM-GCC-32/bin/g++.exe (this location may be different).
6. Paste following to compiler arguments -lbgi 
-lgdi32 
-lcomdlg32 
-luuid 
-loleaut32 
-lole32
7. Set C++ standard to c++11
8. Write some codes and build the code with followin cofig: 

      ![image](https://user-images.githubusercontent.com/55276059/152299456-2e5d2717-3530-4102-a84a-380ccaf49fe3.png)
      
9. Then you are good to go.

# Setting up graphics.h in Sublime Text 3(C++)

1. Download the above BGI file.
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
