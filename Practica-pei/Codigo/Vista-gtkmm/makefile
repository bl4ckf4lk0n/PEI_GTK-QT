COMP=g++
OPC=-g -Wall -std=c++0x `pkg-config gtkmm-3.0 --cflags` -lboost_regex
OPC_MODELO=-g -Wall -std=c++0x
LINKS=`pkg-config gtkmm-3.0 --libs`
OBJ=formulario_registro.o formulario_busqueda.o plantilla.o nuevo.o
OBJ_MODELO=modelo.o persona.o gestorFicheros.o

.PHONY=clean

all:  main minimain
objetos: $(OBJ)
plantilla.o: plantilla.h plantilla.cc
	$(COMP) $(OPC) plantilla.cc -c
formulario_registro.o: $(OBJ_MODELO) formulario_registro.h formulario_registro.cc
	$(COMP) $(OPC) formulario_registro.cc -c
formulario_busqueda.o: $(OBJ_MODELO) formulario_busqueda.h formulario_busqueda.cc
	$(COMP) $(OPC) formulario_busqueda.cc -c
nuevo.o: nuevo.h nuevo.cc
	$(COMP) $(OPC) nuevo.cc -c
main: $(OBJ_MODELO) $(OBJ) main.cc
	$(COMP) $(OPC) $(OBJ_MODELO) $(OBJ) main.cc $(LINKS) -o mainGTK
minimain: minimain.cc
	$(COMP) $(OPC) minimain.cc $(LINKS) -o minimain

modelo.o: ../Modelo/modelo.h ../Modelo/modelo.cc ../Modelo/gestorFicheros.o
	$(COMP) $(OPC_MODELO) -c  ../Modelo/modelo.cc;
persona.o: ../Modelo/persona.h ../Modelo/persona.cc
	$(COMP) $(OPC) -c ../Modelo/persona.cc;
gestorFicheros.o: ../Modelo/gestorFicheros.cc ../Modelo/gestorFicheros.h ../Modelo/persona.o ../Modelo/fileException.h
	$(COMP) $(OPC) -c ../Modelo/gestorFicheros.cc;

clean:
	rm -f mainGTK
	rm -f minimain
	rm -f a.out
	rm -f *.gch
	rm -rf *.o
	rm -rf ../Modelo/*.o

