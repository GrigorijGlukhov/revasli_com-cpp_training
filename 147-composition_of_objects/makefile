CC=g++
CFLAGS=-c -Wall
EXECUTABLE=app_creature
all: $(EXECUTABLE)
$(EXECUTABLE): main.o creature.o point2d.o
	$(CC) main.o creature.o point2d.o -o $(EXECUTABLE) 
main.o:
	$(CC) $(CFLAGS) main.cpp
creature.o:
	$(CC) $(CFLAGS) creature.cpp
point2d.o:
	$(CC) $(CFLAGS) point2d.cpp
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
