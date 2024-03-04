main: main.o 
	g++ main.o -o main

driver.o: main.cpp linkedStack.h node.h
	g++ -c main.cpp

clean:
	rm *.o driver
