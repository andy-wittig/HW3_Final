CC = g++
CFLAGS = -g -Wall

hw_3: main.o
	$(CC) main.o -o hw_3

driver.o: main.cpp arrayStack.h linkedStack.h node.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o driver
