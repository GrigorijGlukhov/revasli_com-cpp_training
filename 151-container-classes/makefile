CC=g++
CFLAGS=-c -Wall
EXECUTABLE=app_arr
all: $(EXECUTABLE)
$(EXECUTABLE): main.o arrayint.o
	$(CC) main.o arrayint.o -o $(EXECUTABLE) 
main.o:
	$(CC) $(CFLAGS) main.cpp
arrayint.o:
	$(CC) $(CFLAGS) arrayint.cpp
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
