#include "Acerca_de.h"

Acerca_de::Acerca_de(QMainWindow* parent)
{
	this->parent = parent;
	ui.setupUi(this);

	ui.LB_Autores->setText("Victor Guzman Pedrajas.\nAdrian Escolano Diaz.");
	ui.LB_Mejoras->setText(" ");
}