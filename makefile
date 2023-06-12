CC = g++
CFLAGS = -Wall -g

fracDim: fracDim.o Matrix.o
	$(CC) $(CFLAGS) -o fracDim fracDim.o Matrix.o

fracDim.o: fracDim.cpp Matrix.h
	$(CC) $(CFLAGS) -c fracDim.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CC) $(CFLAGS) -c Matrix.cpp

clean:
	rm *.o fracDim
