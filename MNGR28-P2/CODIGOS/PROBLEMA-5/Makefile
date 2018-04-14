OPT=-g -Wall -pedantic
EXECS=probextrah probextrag

all : $(EXECS)

# Executables
probextrah : probextrah.o
	gcc -o probextrah probextrah.o -lm

probextrag : probextrag.o
	gcc -o probextrag probextrag.o -lm
	
# Objectes
probextrah.o : probextrah.c
	gcc -c $(OPT) probextrah.c 

probextrag.o : probextrag.c
	gcc -c $(OPT) probextrag.c 

# Neteja
clean :
	rm -f *.o

realclean : clean
	rm -f $(EXECS)