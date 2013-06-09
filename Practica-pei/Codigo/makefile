COMP=g++
OPC=-g -Wall -std=c++0x
GTK_OPC=`pkg-config gtkmm-3.0 --cflags`
GTK_LINKS=`pkg-config gtkmm-3.0 --libs`
OBJ_GTK=Vista-gtkmm/*.o 
OBJ_QT=Vista-qt/*.o
LINKS=-lboost_regex
.PHONY=clean,vistaGTK,pruebaGestor,vistaTerminal
.SUFFIXES:

all: vistaGTK vistaQT

vistaGTK: 
	cd Vista-gtkmm/; make
vistaQT: 
	cd Vista-qt/; make

./Modelo/modelo.o:
	cd Modelo/;	make objetos
./Modelo/persona.o:
	cd Modelo/;	make objetos
./Modelo/gestorFicheros.o:
	cd Modelo/;	make objetos



clean:
	cd Modelo/; make clean
	cd Vista/; make clean
	cd Vista-gtkmm/; make clean
	cd Vista-qt/; make clean
