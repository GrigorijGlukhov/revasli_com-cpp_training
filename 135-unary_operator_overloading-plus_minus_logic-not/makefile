CC=g++
CFLAGS=-c -Wall
EXECUTABLE=app_dollars1
all: $(EXECUTABLE)
$(EXECUTABLE): main.o dollars.o something.o
	$(CC) main.o dollars.o something.o -o $(EXECUTABLE) 
main.o:
	$(CC) $(CFLAGS) main.cpp
dollars.o:
	$(CC) $(CFLAGS) dollars.cpp
something.o:
	$(CC) $(CFLAGS) something.cpp
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
