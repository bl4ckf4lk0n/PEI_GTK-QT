COMP=g++
OPC=-g -Wall -std=c++0x
LINKS=-lboost_regex
.PHONY=clean

all: objetos pruebaGestor
objetos: gestorFicheros.o persona.o modelo.o
pruebaGestor: gestorFicheros.o persona.o makefile pruebaGestor.cc
	$(COMP) $(OPC) gestorFicheros.o persona.o pruebaGestor.cc $(LINKS)
modelo.o: modelo.h modelo.cc gestorFicheros.o
	$(COMP) $(OPC) -c  ./modelo.cc;
gestorFicheros.o: ./gestorFicheros.cc ./gestorFicheros.h ./persona.o ./fileException.h
	$(COMP) $(OPC) -c ./gestorFicheros.cc;
persona.o: ./persona.h ./persona.cc
	$(COMP) $(OPC) -c ./persona.cc;

clean:
	rm -f main
	rm -f a.out
	rm -f *.gch
	rm -rf *.o

