OPT=-g -Wall -pedantic
EXECS=prob1 nodes

all : $(EXECS)

# Executables
prob1 : prob1.o diferencies_dividides.o
	gcc -o prob1 prob1.o diferencies_dividides.o -lm

nodes : nodes.o diferencies_dividides.o
	gcc -o nodes nodes.o diferencies_dividides.o -lm

# Objectes
diferencies_dividides.o : diferencies_dividides.c
	gcc -c $(OPT) diferencies_dividides.c 

nodes.o : nodes.c
	gcc -c $(OPT) nodes.c 

prob1.o : prob1.c
	gcc -c $(OPT) prob1.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)
