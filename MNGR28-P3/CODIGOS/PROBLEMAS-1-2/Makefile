OPT=-g -Wall -pedantic
EXECS=nodes_eq nodes_cheb 

all : $(EXECS)

# Executables
nodes_eq : nodes_eq.o diferencies_dividides.o
	gcc -o nodes_eq nodes_eq.o diferencies_dividides.o -lm

nodes_cheb : nodes_cheb.o diferencies_dividides.o
	gcc -o nodes_cheb nodes_cheb.o diferencies_dividides.o -lm

# Objectes
diferencies_dividides.o : diferencies_dividides.c
	gcc -c $(OPT) diferencies_dividides.c 

nodes_eq.o : nodes_eq.c
	gcc -c $(OPT) nodes_eq.c 

nodes_cheb.o : nodes_cheb.c
	gcc -c $(OPT) nodes_cheb.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)
