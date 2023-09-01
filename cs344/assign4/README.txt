README.txt

CS 344 Assignment 4

Multi-Threaded Producer Consumer Pipeline

Instructions

	1. Compile main.c with the following command

  	   gcc -g -pthread -lm main.c -o line_processor


	2. Run the executable ./line_processor

	   ./line_processor


	Note: Without any additional files for input and output the program
	      will take an input from the command line and output the same
	      text when 80 characters are reached. to use either an input or
	      output file use the following format. 

	./line_processor < input.txt > output.txt

