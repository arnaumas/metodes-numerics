OPT=-g -Wall -pedantic
EXECS=prob6

all : $(EXECS)

# Executables
prob6 : prob6.o integracio.o
	gcc -o prob6 prob6.o integracio.o -lm


# Objectes
integracio.o : integracio.c
	gcc -c $(OPT) integracio.c 

prob6.o : prob6.c
	gcc -c $(OPT) prob6.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)