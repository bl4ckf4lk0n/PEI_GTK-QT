COMP=g++
OPC=-g -Wall `pkg-config gtkmm-3.0 --cflags`
LINKS=`pkg-config gtkmm-3.0 --libs`
.PHONY=clean

all: objetos minimain
objetos: 
#main: ../Modelo/modelo.o ../Modelo/persona.o ../Modelo/gestorFicheros.o vistaTerminal.o
#	$(COMP)  $(OPC) vistaTerminal.cc ../Modelo/modelo.o ../Modelo/persona.o ../Modelo/gestorFicheros.o -o main $(LINKS)
minimain: minimain.cc
	$(COMP) $(OPC) minimain.cc $(LINKS) -o main


clean:
	rm -f main
	rm -f a.out
	rm -f *.gch
	rm -rf *.o

