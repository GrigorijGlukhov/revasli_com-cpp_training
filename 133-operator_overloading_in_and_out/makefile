CC=g++
CFLAGS=-c -Wall
EXECUTABLE=app_test
all: $(EXECUTABLE)
$(EXECUTABLE): main.o fraction.o point.o 
	$(CC) main.o fraction.o point.o -o $(EXECUTABLE) 
fraction.o:
	$(CC) $(CFLAGS) fraction.cpp
point.o:
	$(CC) $(CFLAGS) point.cpp
main.o:
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
