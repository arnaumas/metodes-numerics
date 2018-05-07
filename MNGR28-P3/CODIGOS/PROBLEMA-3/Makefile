OPT=-g -Wall -pedantic
EXECS=prob3

all : $(EXECS)

# Executables
prob3 : prob3.o integracio.o
	gcc -o prob3 prob3.o integracio.o -lm


# Objectes
integracio.o : integracio.c
	gcc -c $(OPT) integracio.c 

prob3.o : prob3.c
	gcc -c $(OPT) prob3.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)