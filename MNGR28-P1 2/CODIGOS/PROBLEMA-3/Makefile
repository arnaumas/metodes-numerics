OPT=-g -Wall -pedantic
EXECS=prob3a1_fl prob3a1_do prob3a2_fl prob3a2_do prob3c

all : $(EXECS)

# Executables
prob3a1_fl : prob3a1_fl.o prob3.o
	gcc -o prob3a1_fl prob3a1_fl.o prob3.o -lm

prob3a2_fl : prob3a2_fl.o prob3.o
	gcc -o prob3a2_fl prob3a2_fl.o prob3.o -lm

prob3a1_do : prob3a1_do.o prob3.o
	gcc -o prob3a1_do prob3a1_do.o prob3.o -lm

prob3a2_do : prob3a2_do.o prob3.o
	gcc -o prob3a2_do prob3a2_do.o prob3.o -lm

prob3c :
	gcc $(OPT) -o prob3c prob3c.c
	
# Objectes
prob3.o : prob3.c
	gcc -c $(OPT) prob3.c 

prob3a1_fl.o : prob3a1_fl.c
	gcc -c $(OPT) prob3a1_fl.c 

prob3a2_fl.o : prob3a2_fl.c
	gcc -c $(OPT) prob3a2_fl.c 

prob3a1_do.o : prob3a1_do.c
	gcc -c $(OPT) prob3a1_do.c 

prob3a2_do.o : prob3a2_do.c
	gcc -c $(OPT) prob3a2_do.c 

# Neteja
clean :
	rm -f *.o
	rm -r -f *.dSYM

realclean : clean
	rm -f $(EXECS)
