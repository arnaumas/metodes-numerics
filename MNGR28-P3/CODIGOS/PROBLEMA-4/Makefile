OPT=-g -Wall -pedantic
EXECS=prob4

all : $(EXECS)

# Executables
prob4 : prob4.o integracio.o
	gcc -o prob4 prob4.o integracio.o -lm


# Objectes
integracio.o : integracio.c
	gcc -c $(OPT) integracio.c 

prob4.o : prob4.c
	gcc -c $(OPT) prob4.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)