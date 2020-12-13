COMPILER = g++
FLAGS = #-Wall -Werror
OBJ = Aquila.o Camera.o Box.o
PROGRAMNAME = Aquila

main : $(OBJ)
	$(COMPILER) $(OBJ) -o $(PROGRAMNAME) -lsfml-graphics -lsfml-window -lsfml-system

%.o : %.cpp
	$(COMPILER) $(FLAGS) -c $<

exportDisplay:
	export DISPLAY=:0

clean:
	rm -fv *.o $(PROGRAMNAME)