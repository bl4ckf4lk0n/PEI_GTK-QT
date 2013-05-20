COMP=g++
OPC=-g -Wall -std=c++0x
GTK_OPC=`pkg-config gtkmm-3.0 --cflags`
GTK_LINKS=`pkg-config gtkmm-3.0 --libs`
OBJ=Vista-gtkmm/formulario_registro.o Vista-gtkmm/formulario_busqueda.o Vista-gtkmm/plantilla.o 
LINKS=-lboost_regex
.PHONY=clean,vistaGTK,pruebaGestor,vistaTerminal
.SUFFIXES:

all: vistaGTK pruebaGestor vistaTerminal
pruebaGestor: Modelo/gestorFicheros.o Modelo/persona.o Modelo/makefile Modelo/pruebaGestor.cc
	cd Modelo/;	make
vistaTerminal: Modelo/modelo.o Modelo/persona.o Modelo/gestorFicheros.o Vista/vistaTerminal.cc
	cd Vista/;	make
vistaGTK: ./Modelo/modelo.o ./Modelo/persona.o ./Modelo/gestorFicheros.o ./Vista-gtkmm/*.o
	$(COMP) $(OPC) $(GTK_OPC) $(OBJ) Modelo/modelo.o Modelo/persona.o Modelo/gestorFicheros.o Vista-gtkmm/main.cc $(LINKS) $(GTK_LINKS) -o mainGTK

vistaQT: ./Modelo/modelo.o ./Modelo/persona.o ./Modelo/gestorFicheros.o ./Vista-qt/*.o
	$(COMP) $(OPC) $(OBJ) Modelo/modelo.o Modelo/persona.o Modelo/gestorFicheros.o Vista-qt/main.cpp $(LINKS) -o mainQT

./Modelo/modelo.o:
	cd Modelo/;	make objetos
./Modelo/persona.o:
	cd Modelo/;	make objetos
./Modelo/gestorFicheros.o:
	cd Modelo/;	make objetos

./Vista-gtkmm/*.o:
	cd Vista-gtkmm/; make objetos

clean:
	cd Modelo/; make clean
	cd Vista/; make clean
	cd Vista-gtkmm/; make clean
