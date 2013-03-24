COMP=g++
OPC=-g -Wall
LINKS=-lboost_regex
.PHONY=clean

all: objetos main
objetos: vistaTerminal.o
main: ../Modelo/modelo.o ../Modelo/persona.o ../Modelo/gestorFicheros.o vistaTerminal.o
	$(COMP)  $(OPC) vistaTerminal.cc ../Modelo/modelo.o ../Modelo/persona.o ../Modelo/gestorFicheros.o -o main $(LINKS)
vistaTerminal.o: vistaTerminal.cc
	$(COMP) $(OPC) -c ./vistaTerminal.cc;

clean:
	rm -f main
	rm -f a.out
	rm -f *.gch
	rm -rf *.o

