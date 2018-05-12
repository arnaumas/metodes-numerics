OPT=-g -Wall -pedantic
EXECS=prob7

all : $(EXECS)

# Executables
prob7 : prob7.o diferencies_dividides.o
	gcc -o prob7 prob7.o diferencies_dividides.o -lm

# Objectes
diferencies_dividides.o : diferencies_dividides.c
	gcc -c $(OPT) diferencies_dividides.c 

prob7.o : prob7.c
	gcc -c $(OPT) prob7.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)
