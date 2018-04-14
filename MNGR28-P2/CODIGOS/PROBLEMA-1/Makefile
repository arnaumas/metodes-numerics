OPT=-g -Wall -pedantic
EXECS=prob1b_fl prob1b_do prob1c123

all : $(EXECS)

# Executables
prob1b_fl : prob1b_fl.o polinomis.o
	gcc -o prob1b_fl prob1b_fl.o polinomis.o -lm

prob1b_do : prob1b_do.o polinomis.o
	gcc -o prob1b_do prob1b_do.o polinomis.o -lm

prob1c123 : prob1c123.o polinomis.o
	gcc -o prob1c123 prob1c123.o polinomis.o -lm
	
# Objectes
polinomis.o : polinomis.c
	gcc -c $(OPT) polinomis.c 

prob1b_fl.o : prob1b_fl.c
	gcc -c $(OPT) prob1b_fl.c 

prob1b_do.o : prob1b_do.c
	gcc -c $(OPT) prob1b_do.c 

prob1c123.o : prob1c123.c
	gcc -c $(OPT) prob1c123.c 

# Neteja
clean :
	rm -f *.o

realclean : clean
	rm -f $(EXECS)