OPT=-g -Wall -pedantic
EXECS=prob5

all : $(EXECS)

# Executables
prob5 : prob5.o integracio.o
	gcc -o prob5 prob5.o integracio.o -lm


# Objectes
integracio.o : integracio.c
	gcc -c $(OPT) integracio.c 

prob5.o : prob5.c
	gcc -c $(OPT) prob5.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)