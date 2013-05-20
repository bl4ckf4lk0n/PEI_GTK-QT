COMP=g++
OPC=-g -Wall -std=c++0x `pkg-config gtkmm-3.0 --cflags`
LINKS=`pkg-config gtkmm-3.0 --libs`
OBJ=formulario_registro.o formulario_busqueda.o plantilla.o 
.PHONY=clean

all: $(OBJ) main minimain
objetos: $(OBJ)
plantilla.o: plantilla.h plantilla.cc
	$(COMP) $(OPC) plantilla.cc -c
formulario_registro.o: formulario_registro.h formulario_registro.cc
	$(COMP) $(OPC) formulario_registro.cc -c
formulario_busqueda.o: formulario_busqueda.h formulario_busqueda.cc
	$(COMP) $(OPC) formulario_busqueda.cc -c
main:  $(OBJ) main.cc
	$(COMP) $(OPC) $(OBJ) main.cc $(LINKS) -o main
minimain: minimain.cc
	$(COMP) $(OPC) minimain.cc $(LINKS) -o minimain


clean:
	rm -f main
	rm -f minimain
	rm -f a.out
	rm -f *.gch
	rm -rf *.o

