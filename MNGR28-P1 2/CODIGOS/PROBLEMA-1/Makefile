OPT=-g -Wall -pedantic
EXECS=prob1b_fl prob1b_do prob1c_do prob1c_fl

all : $(EXECS)

# Executables
prob1b_fl : prob1b_fl.o
	gcc -o prob1b_fl prob1b_fl.o -lm

prob1b_do : prob1b_do.o
	gcc -o prob1b_do prob1b_do.o -lm

prob1c_do : prob1c_do.o
	gcc -o prob1c_do prob1c_do.o -lm

prob1c_fl: prob1c_fl.o
	gcc -o prob1c_fl prob1c_fl.o -lm
	
# Objectes
prob1b_fl.o : prob1b_fl.c
	gcc -c $(OPT) prob1b_fl.c 

prob1b_do.o : prob1b_do.c
	gcc -c $(OPT) prob1b_do.c 

prob1c_do.o : prob1c_do.c
	gcc -c $(OPT) prob1c_do.c 

prob1c_fl.o : prob1c_fl.c
	gcc -c $(OPT) prob1c_fl.c 

# Neteja
clean :
	rm -f *.o

realclean : clean
	rm -f $(EXECS)
