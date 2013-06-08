/********************************************************************************
** Form generated from reading UI file 'Formulario_Registro.ui'
**
** Created: Sat Jun 8 18:28:17 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIO_REGISTRO_H
#define UI_FORMULARIO_REGISTRO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_registro
{
public:
    QGroupBox *GB_Registro;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *LE_CodPostal;
    QLineEdit *LE_Telefono;
    QLabel *label_6;
    QLineEdit *LE_Direccion;
    QLineEdit *LE_Nombre;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *LE_Email;
    QLabel *label_2;
    QLineEdit *LE_Poblacion;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *Btn_ModRegistro;
    QPushButton *Btn_BorrarRegistro;
    QPushButton *Btn_Atras;
    QPushButton *Btn_Adelante;
    QSpinBox *SB_Atras;
    QSpinBox *SB_Adelante;

    void setupUi(QWidget *Form_registro)
    {
        if (Form_registro->objectName().isEmpty())
            Form_registro->setObjectName(QString::fromUtf8("Form_registro"));
        Form_registro->resize(757, 442);
        GB_Registro = new QGroupBox(Form_registro);
        GB_Registro->setObjectName(QString::fromUtf8("GB_Registro"));
        GB_Registro->setGeometry(QRect(100, 50, 551, 321));
        layoutWidget = new QWidget(GB_Registro);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 50, 551, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        LE_CodPostal = new QLineEdit(layoutWidget);
        LE_CodPostal->setObjectName(QString::fromUtf8("LE_CodPostal"));

        gridLayout->addWidget(LE_CodPostal, 0, 3, 1, 1);

        LE_Telefono = new QLineEdit(layoutWidget);
        LE_Telefono->setObjectName(QString::fromUtf8("LE_Telefono"));

        gridLayout->addWidget(LE_Telefono, 1, 3, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        LE_Direccion = new QLineEdit(layoutWidget);
        LE_Direccion->setObjectName(QString::fromUtf8("LE_Direccion"));

        gridLayout->addWidget(LE_Direccion, 1, 1, 1, 1);

        LE_Nombre = new QLineEdit(layoutWidget);
        LE_Nombre->setObjectName(QString::fromUtf8("LE_Nombre"));

        gridLayout->addWidget(LE_Nombre, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        LE_Email = new QLineEdit(layoutWidget);
        LE_Email->setObjectName(QString::fromUtf8("LE_Email"));

        gridLayout->addWidget(LE_Email, 2, 3, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        LE_Poblacion = new QLineEdit(layoutWidget);
        LE_Poblacion->setObjectName(QString::fromUtf8("LE_Poblacion"));

        gridLayout->addWidget(LE_Poblacion, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        Btn_ModRegistro = new QPushButton(Form_registro);
        Btn_ModRegistro->setObjectName(QString::fromUtf8("Btn_ModRegistro"));
        Btn_ModRegistro->setGeometry(QRect(100, 380, 121, 27));
        Btn_BorrarRegistro = new QPushButton(Form_registro);
        Btn_BorrarRegistro->setObjectName(QString::fromUtf8("Btn_BorrarRegistro"));
        Btn_BorrarRegistro->setGeometry(QRect(541, 380, 111, 27));
        Btn_Atras = new QPushButton(Form_registro);
        Btn_Atras->setObjectName(QString::fromUtf8("Btn_Atras"));
        Btn_Atras->setGeometry(QRect(20, 220, 61, 27));
        Btn_Adelante = new QPushButton(Form_registro);
        Btn_Adelante->setObjectName(QString::fromUtf8("Btn_Adelante"));
        Btn_Adelante->setGeometry(QRect(690, 220, 61, 27));
        SB_Atras = new QSpinBox(Form_registro);
        SB_Atras->setObjectName(QString::fromUtf8("SB_Atras"));
        SB_Atras->setGeometry(QRect(20, 180, 64, 33));
        SB_Atras->setValue(1);
        SB_Adelante = new QSpinBox(Form_registro);
        SB_Adelante->setObjectName(QString::fromUtf8("SB_Adelante"));
        SB_Adelante->setGeometry(QRect(690, 180, 64, 33));
        SB_Adelante->setMinimum(1);
        SB_Adelante->setMaximum(10);
        SB_Adelante->setValue(1);

        retranslateUi(Form_registro);

        QMetaObject::connectSlotsByName(Form_registro);
    } // setupUi

    void retranslateUi(QWidget *Form_registro)
    {
        Form_registro->setWindowTitle(QApplication::translate("Form_registro", "Registro", 0, QApplication::UnicodeUTF8));
        GB_Registro->setTitle(QApplication::translate("Form_registro", "Registro 0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form_registro", "Correo electr\303\263nico", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form_registro", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form_registro", "Tel\303\251fono", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form_registro", "C\303\263digo postal", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form_registro", "Direcci\303\263n", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form_registro", "Poblaci\303\263n", 0, QApplication::UnicodeUTF8));
        Btn_ModRegistro->setText(QApplication::translate("Form_registro", "Modificar registro", 0, QApplication::UnicodeUTF8));
        Btn_BorrarRegistro->setText(QApplication::translate("Form_registro", "Borrar registro", 0, QApplication::UnicodeUTF8));
        Btn_Atras->setText(QApplication::translate("Form_registro", "<-", 0, QApplication::UnicodeUTF8));
        Btn_Adelante->setText(QApplication::translate("Form_registro", "->", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_registro: public Ui_Form_registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIO_REGISTRO_H
