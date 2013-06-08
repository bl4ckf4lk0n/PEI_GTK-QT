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

vistaGTK: ./Modelo/modelo.o ./Modelo/persona.o ./Modelo/gestorFicheros.o $(OBJ_GTK)
	$(COMP) $(OPC) $(GTK_OPC) $(OBJ_GTK) Modelo/modelo.o Modelo/persona.o Modelo/gestorFicheros.o Vista-gtkmm/main.cc $(LINKS) $(GTK_LINKS) -o ./Vista-gtkmm/mainGTK

vistaQT: 
	cd Vista-qt/; make

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
	cd Vista-qt/; make clean
