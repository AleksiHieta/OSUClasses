#Makefile

playgame:
	g++ card.cpp deck.cpp game.cpp hand.cpp player.cpp driver.cpp -o playgame
CC = g++
exe_file = playgame
$(exe_file): card.o deck.o game.o hand.o player.o driver.o
	$(CC) card.o deck.o game.o hand.o player.o driver.o -o $(exe_file)
card.o: card.cpp
	$(CC) -c card.cpp 
deck.o: deck.cpp
	$(CC) -c deck.cpp
game.o: game.cpp
	$(CC) -c game.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
player.o: player.cpp
	$(CC) -c player.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)
