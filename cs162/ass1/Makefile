#Makefile

budget:
	g++ budget.cpp prog.cpp -o budget
CC = g++
exe_file = budget
$(exe_file): budget.o prog.o
	$(CC) budget.o prog.o -o $(exe_file)
budget.o: budget.cpp
	$(CC) -c budget.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)
