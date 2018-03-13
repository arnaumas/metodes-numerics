OPT=-g -Wall -pedantic
EXECS=prob2a_fl prob2a_do prob2b_fl prob2b_do

all : $(EXECS)

# Executables
prob2a_fl : prob2a_fl.o
	gcc -o prob2a_fl prob2a_fl.o -lm

prob2a_do : prob2a_do.o
	gcc -o prob2a_do prob2a_do.o -lm

prob2b_fl : prob2b_fl.o
	gcc -o prob2b_fl prob2b_fl.o -lm

prob2b_do : prob2b_do.o
	gcc -o prob2b_do prob2b_do.o -lm
	
# Objectes
prob2a_fl.o : prob2a_fl.c
	gcc -c $(OPT) prob2a_fl.c 

prob2a_do.o : prob2a_do.c
	gcc -c $(OPT) prob2a_do.c 

prob2b_fl.o : prob2b_fl.c
	gcc -c $(OPT) prob2b_fl.c 

prob2b_do.o : prob2b_do.c
	gcc -c $(OPT) prob2b_do.c 

# Neteja
clean :
	rm -f *.o

realclean : clean
	rm -f $(EXECS)