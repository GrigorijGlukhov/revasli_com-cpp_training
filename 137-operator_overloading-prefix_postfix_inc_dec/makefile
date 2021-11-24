CC=g++
CFLAGS=-c -Wall
EXECUTABLE=app_numbers
all: $(EXECUTABLE)
$(EXECUTABLE): main.o numbers.o 
	$(CC) main.o numbers.o -o $(EXECUTABLE) 
main.o:
	$(CC) $(CFLAGS) main.cpp
numbers.o:
	$(CC) $(CFLAGS) numbers.cpp
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
