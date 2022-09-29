EXEC = mini_shell
CFLAGS = -Wall -Werror -std=c18 -pedantic -D_XOPEN_SOURCE=700

all: $(EXEC)

$(EXEC): $(EXEC).o main.o
	gcc -o $(EXEC) $(EXEC).o main.o

$(EXEC).o: $(EXEC).c
	gcc -o $(EXEC).o -c $(EXEC).c  $(CFLAGS) 

main.o: main.c $(EXEC).h
	gcc -o main.o -c main.c  $(CFLAGS) 

clean :
	rm -fr *.o
	
run :
	./$(EXEC)
