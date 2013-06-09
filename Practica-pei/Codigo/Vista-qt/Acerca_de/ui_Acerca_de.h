/********************************************************************************
** Form generated from reading UI file 'Acerca_de.ui'
**
** Created: Sun Jun 9 16:09:46 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ACERCA_DE_H
#define ACERCA_DE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *LB_Autores;
    QLabel *label_2;
    QLabel *LB_Mejoras;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(693, 463);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(7, 10, 678, 445));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        label->setFont(font);
        label->setAutoFillBackground(false);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        LB_Autores = new QLabel(layoutWidget);
        LB_Autores->setObjectName(QString::fromUtf8("LB_Autores"));

        gridLayout->addWidget(LB_Autores, 1, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        LB_Mejoras = new QLabel(layoutWidget);
        LB_Mejoras->setObjectName(QString::fromUtf8("LB_Mejoras"));

        gridLayout->addWidget(LB_Mejoras, 3, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Acerca de", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Autores\n"
"", 0, QApplication::UnicodeUTF8));
        LB_Autores->setText(QApplication::translate("Dialog", "V\303\255ctor Guzm\303\241n Pedrajas.\n"
"Adri\303\241n Escolano D\303\255az.\n"
"", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Mejoras\n"
"", 0, QApplication::UnicodeUTF8));
        LB_Mejoras->setText(QApplication::translate("Dialog", "Las mejoras incluidas son:\n"
"	-	Guardar como...\n"
"	-	B\303\272squeda exacta y por subcadenas\n"
"	-	B\303\272squeda con operador \"Y\" y con operador \"O\"\n"
"	-	Gesti\303\263n de m\303\272ltiples ficheros independientes\n"
"	-	Exportar a CSV\n"
"	-	Nuevo fichero...\n"
"	-	Comprobaci\303\263n de fichero mal formado\n"
"	-	Nuevo fichero...\n"
"	-	Navegaci\303\263n de N en N\n"
"	-	Di\303\241logos de confirmaci\303\263n\n"
"	-	L\303\255mites din\303\241micos en el movimiento entre registros\n"
"	-	Pesta\303\261as con bot\303\263n de cierre en Gtk", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ACERCA_DE_H
