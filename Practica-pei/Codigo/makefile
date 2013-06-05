COMP=g++
OPC=-g -Wall -std=c++0x
GTK_OPC=`pkg-config gtkmm-3.0 --cflags`
GTK_LINKS=`pkg-config gtkmm-3.0 --libs`
OBJ_GTK=Vista-gtkmm/*.o 
OBJ_QT=Vista-qt/*.o
LINKS=-lboost_regex
.PHONY=clean,vistaGTK,pruebaGestor,vistaTerminal
.SUFFIXES:

all: vistaGTK pruebaGestor vistaTerminal
pruebaGestor: Modelo/gestorFicheros.o Modelo/persona.o Modelo/makefile Modelo/pruebaGestor.cc
	cd Modelo/;	make
vistaTerminal: Modelo/modelo.o Modelo/persona.o Modelo/gestorFicheros.o Vista/vistaTerminal.cc
	cd Vista/;	make
vistaGTK: ./Modelo/modelo.o ./Modelo/persona.o ./Modelo/gestorFicheros.o $(OBJ_GTK)
	$(COMP) $(OPC) $(GTK_OPC) $(OBJ_GTK) Modelo/modelo.o Modelo/persona.o Modelo/gestorFicheros.o Vista-gtkmm/main.cc $(LINKS) $(GTK_LINKS) -o ./Vista-gtkmm/mainGTK

vistaQT: ./Modelo/modelo.o ./Modelo/persona.o ./Modelo/gestorFicheros.o ./Vista-qt/*.o
	$(COMP) $(OPC) $(OBJ_QT) Modelo/modelo.o Modelo/persona.o Modelo/gestorFicheros.o Vista-qt/main.cpp $(LINKS) -o mainQT

./Modelo/modelo.o:
	cd Modelo/;	make objetos
./Modelo/persona.o:
	cd Modelo/;	make objetos
./Modelo/gestorFicheros.o:
	cd Modelo/;	make objetos

./Vista-gtkmm/*.o: ./Vista-gtkmm/*.cc ./Vista-gtkmm/*.h
	cd Vista-gtkmm/; make objetos

clean:
	cd Modelo/; make clean
	cd Vista/; make clean
	cd Vista-gtkmm/; make clean
