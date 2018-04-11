OPT=-g -Wall -pedantic
EXECS=prob4

all : $(EXECS)

# Executables
prob4 :
	gcc $(OPT) -o prob4 prob4.c 

# Neteja
clean :
	rm -f *.o

realclean : clean
	rm -f $(EXECS)
	rm -rf *.dSYM
