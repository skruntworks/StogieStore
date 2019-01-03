OBJS	= ConsoleDriver.o StogieStore.o Cigar.o
SOURCE	= ConsoleDriver.cpp StogieStore.cpp Cigar.cpp
HEADER	= ConsoleDriver.h StogieStore.h Cigar.h
OUT	= StogieStore.exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

ConsoleDriver.o: ConsoleDriver.cpp
	$(CC) $(FLAGS) ConsoleDriver.cpp 

StogieStore.o: StogieStore.cpp
	$(CC) $(FLAGS) StogieStore.cpp 

Cigar.o: Cigar.cpp
	$(CC) $(FLAGS) Cigar.cpp 


clean:
	rm -f $(OBJS) $(OUT)
