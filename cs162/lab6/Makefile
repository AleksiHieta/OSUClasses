#Makefile

shape:
	g++ shape.h shape.cpp circle.h circle.cpp rectangle.h rectangle.cpp square.h square.cpp application.cpp
CC = g++
exe_file = shape
$(exe_file): shape.o circle.o rectangle.o square.o application.o
	$(CC) shape.o circle.o rectangle.o square.o application.o -o $(exe_file)
shape.o: shape.cpp
	$(CC) -c shape.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp
rectangle.o: rectangle.cpp
	$(CC) -c rectangle.cpp
square.o: square.cpp
	$(CC) -c square.cpp
application.o: application.cpp
	$(CC) -c application.cpp

clean:
	rm -f *.out *.o $(exe_file)
