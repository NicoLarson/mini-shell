CC = gcc
EXEC = mcat
CFLAGS = -Wall -Werror -std=c18 -pedantic -D_XOPEN_SOURCE=700
BUILD_PATH=../../build/$(EXEC)
all: ../$(EXEC)

../$(EXEC) : main.o
	$(CC) -o $(BUILD_PATH) main.o 

main.o : main.c
	$(CC) -o main.o -c main.c $(CFLAGS) 

clean :
	rm -fr *.o
	
run :
	$(BUILD_PATH)