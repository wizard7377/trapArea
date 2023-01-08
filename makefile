main: main.o
	g++ main.o -o main -lmpfr -lgmp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o