#Makefile



CC = g++
exe_file = hand
$(exe_file): hand.o
	$(CC) hand.o -o $(exe_file)
hand.o: hand.cpp
	$(CC) -c hand.cpp

clean:
	rm -f *.out *.o $(exe_file)
