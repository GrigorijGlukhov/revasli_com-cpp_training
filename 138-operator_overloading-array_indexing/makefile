CC=g++
CFLAGS=-c -Wall
EXECUTABLE=app_intarray
all: $(EXECUTABLE)
$(EXECUTABLE): main.o intarray.o 
	$(CC) main.o intarray.o -o $(EXECUTABLE) 
main.o:
	$(CC) $(CFLAGS) main.cpp
intarray.o:
	$(CC) $(CFLAGS) intarray.cpp
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
