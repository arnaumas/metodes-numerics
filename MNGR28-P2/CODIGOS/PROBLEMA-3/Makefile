OPT=-g -Wall -pedantic
EXECS=prob3
all : $(EXECS)

# Executables
prob3 : prob3.o halley.o
	gcc -o prob3 prob3.o halley.o -lm
# Objectes
halley.o : halley.c
	gcc -c $(OPT) halley.c 

prob3.o : prob3.c
	gcc -c $(OPT) prob3.c 

# Neteja
clean :
	rm -f *.o

realclean : clean
	rm -f $(EXECS)