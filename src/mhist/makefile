CC = gcc
EXEC = mhist
CFLAGS = -Wall -Werror -std=c18 -pedantic -D_XOPEN_SOURCE=700
BUILD_PATH=../../build/$(EXEC)

all: ../$(EXEC)

../$(EXEC): $(EXEC).o main.o
	$(CC) -o $(BUILD_PATH) $(EXEC).o main.o

$(EXEC).o: $(EXEC).c
	$(CC) -o $(EXEC).o -c $(EXEC).c  $(CFLAGS) 

main.o: main.c $(EXEC).h
	$(CC) -o main.o -c main.c  $(CFLAGS) 

clean :
	rm -fr *.o
	
run :
	$(BUILD_PATH)