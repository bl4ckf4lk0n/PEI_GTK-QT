#ifndef ACERCA_H
#define ACERCA_H

#include <QMainWindow>
#include "ui_Acerca_de.h"

using namespace std;

class Acerca_de : public QDialog
{
 Q_OBJECT

public:
 Acerca_de(QMainWindow* parent);

private slots:

private:
 Ui::Dialog ui;
 QMainWindow* parent;
};


#endif