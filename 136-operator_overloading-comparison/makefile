CC=g++
CFLAGS=-c -Wall
EXECUTABLE=app_car1
all: $(EXECUTABLE)
$(EXECUTABLE): main.o car.o 
	$(CC) main.o car.o -o $(EXECUTABLE) 
main.o:
	$(CC) $(CFLAGS) main.cpp
car.o:
	$(CC) $(CFLAGS) car.cpp
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
