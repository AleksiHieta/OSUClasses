#Makefile

hunt:
	g++ player.cpp bats.cpp driver.cpp empty.cpp gold.cpp event.cpp room.cpp pit.cpp wumpus.cpp
CC = g++
exe_file = hunt
$(exe_file): player.o bats.o driver.o empty.o gold.o event.o room.o pit.o wumpus.o
	$(CC) player.o bats.o driver.o empty.o gold.o event.o room.o pit.o wumpus.o -o $(exe_file)
player.o: player.cpp
	$(CC) -c player.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
empty.o: empty.cpp
	$(CC) -c empty.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
event.o: event.cpp
	$(CC) -c event.cpp
room.o: room.cpp
	$(CC) -c room.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp

clean:
	rm -f *.out *.o $(exe_file)
