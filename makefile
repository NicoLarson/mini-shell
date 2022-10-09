EXEC = mini_shell
CFLAGS = -Wall -Werror -std=c18 -pedantic -D_XOPEN_SOURCE=700

all: $(EXEC)
	@$(MAKE) -C src/mcat
	@$(MAKE) -C src/mcd
	@$(MAKE) -C src/mfind
	@$(MAKE) -C src/mgrep
	@$(MAKE) -C src/mhist
	@$(MAKE) -C src/mls
	@$(MAKE) -C src/mpwd

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
