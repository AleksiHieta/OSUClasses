#Makefile

sort:
	g++ linked_list.cpp node.cpp driver.cpp
CC = g++
exe_file = sort
$(exe_file): linked_list.o node.o driver.o
	$(CC) linked_list.o node.o driver.o -o $(exe_file)
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp
node.o: node.cpp
	$(CC) -c node.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)
