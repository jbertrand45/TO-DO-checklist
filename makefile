HW2:cdriver.o
	g++ driver.o -o HW2
driver.o: driver.cpp listimplementation.h node.
	g++ -c driver.cpp
clean:
	rm*.o HW2