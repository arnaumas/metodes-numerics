OPT=-g -Wall -pedantic
EXECS=prob2

all : $(EXECS)

# Executables
prob2 : prob2.o diferencies_dividides.o
	gcc -o prob2 prob2.o diferencies_dividides.o -lm

# Objectes
diferencies_dividides.o : diferencies_dividides.c
	gcc -c $(OPT) diferencies_dividides.c 

prob2.o : prob2.c
	gcc -c $(OPT) prob2.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)