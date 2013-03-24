COMP=g++
OPC=-g -Wall
LINKS=-lboost_regex
.PHONY=clean

all: pruebaGestor vistaTerminal
pruebaGestor: Modelo/gestorFicheros.o Modelo/persona.o Modelo/makefile Modelo/pruebaGestor.cc
	cd Modelo/;	make
vistaTerminal: Modelo/modelo.o Modelo/persona.o Modelo/gestorFicheros.o Vista/vistaTerminal.cc
	cd Vista/;	make

clean:
	cd Modelo/; make clean
	cd Vista/; make clean
