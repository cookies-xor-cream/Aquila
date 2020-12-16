COMPILER = g++
FLAGS = #-Wall -Werror
OBJ = Aquila.o Vector2.o Vector3.o Vector4.o Matrix3.o Matrix4.o Triangle.o Mesh.o Camera.o
PROGRAMNAME = Aquila

main : $(OBJ)
	$(COMPILER) $(OBJ) -o $(PROGRAMNAME) -lsfml-graphics -lsfml-window -lsfml-system

%.o : %.cpp
	$(COMPILER) $(FLAGS) -c $<

exportDisplay:
	export DISPLAY=:0

clean:
	rm -fv *.o $(PROGRAMNAME)