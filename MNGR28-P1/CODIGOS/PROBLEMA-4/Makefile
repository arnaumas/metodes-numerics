OPT=-g -Wall -pedantic
EXECS=prob4a_fl prob4a_do prob4b_fl prob4b_do prob4d1_fl prob4d2_fl

all : $(EXECS)

# Executables
prob4a_fl : prob4a_fl.o
	gcc -o prob4a_fl prob4a_fl.o -lm

prob4a_do : prob4a_do.o
	gcc -o prob4a_do prob4a_do.o -lm

prob4b_fl : prob4b_fl.o
	gcc -o prob4b_fl prob4b_fl.o -lm

prob4b_do : prob4b_do.o
	gcc -o prob4b_do prob4b_do.o -lm

prob4d1_fl : prob4d1_fl.o
	gcc -o prob4d1_fl prob4d1_fl.o -lm

prob4d2_fl : prob4d2_fl.o
	gcc -o prob4d2_fl prob4d2_fl.o -lm

# Objectes
prob4a_fl.o : prob4a_fl.c
	gcc -c $(OPT) prob4a_fl.c 

prob4a_do.o : prob4a_do.c
	gcc -c $(OPT) prob4a_do.c 

prob4b_fl.o : prob4b_fl.c
	gcc -c $(OPT) prob4b_fl.c 

prob4b_do.o : prob4b_do.c
	gcc -c $(OPT) prob4b_do.c 

prob4d1_fl.o : prob4d1_fl.c
	gcc -c $(OPT) prob4d1_fl.c 

prob4d2_fl.o : prob4d2_fl.c
	gcc -c $(OPT) prob4d2_fl.c 

# Neteja
clean :
	rm -f *.o

realclean : clean
	rm -f $(EXECS)