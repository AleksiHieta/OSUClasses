#Makefile

zoogame:
	g++ animal.cpp zoo.cpp tiger.cpp bear.cpp sealion.cpp driver.cpp
CC = g++
exe_file = zoogame
$(exe_file): animal.o zoo.o tiger.o bear.o sealion.o driver.o
	$(CC) animal.o zoo.o tiger.o bear.o sealion.o driver.o -o $(exe_file)
animal.o: animal.cpp
	$(CC) -c animal.cpp
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
bear.o: bear.cpp
	$(CC) -c bear.cpp
sealion.o: sealion.cpp
	$(CC) -c sealion.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)
