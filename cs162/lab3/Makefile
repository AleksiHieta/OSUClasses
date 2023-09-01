#Makefile

deck:
	g++ card.cpp deck.cpp driver.cpp -o deck
CC = g++
exe_file = deck
$(exe_file): card.o deck.o driver.o
	$(CC) card.o deck.o driver.o -o $(exe_file)
card.o: card.cpp
	$(CC) -c card.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)
