/********************************************************************************
** Form generated from reading UI file 'Formulario_Busqueda.ui'
**
** Created: Sat Jun 8 18:28:17 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIO_BUSQUEDA_H
#define UI_FORMULARIO_BUSQUEDA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Busqueda
{
public:
    QComboBox *CB_TipoBusqueda;
    QLabel *label;
    QComboBox *CB_TipoBusqueda_2;
    QLabel *label_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *LE_CodPostal;
    QLineEdit *LE_Telefono;
    QLabel *label_6;
    QLineEdit *LE_Direccion;
    QLineEdit *LE_Nombre;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *LE_Email;
    QLabel *label_5;
    QLineEdit *LE_Poblacion;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *Btn_Buscar;

    void setupUi(QDialog *Dialog_Busqueda)
    {
        if (Dialog_Busqueda->objectName().isEmpty())
            Dialog_Busqueda->setObjectName(QString::fromUtf8("Dialog_Busqueda"));
        Dialog_Busqueda->resize(588, 516);
        CB_TipoBusqueda = new QComboBox(Dialog_Busqueda);
        CB_TipoBusqueda->setObjectName(QString::fromUtf8("CB_TipoBusqueda"));
        CB_TipoBusqueda->setGeometry(QRect(160, 50, 271, 29));
        CB_TipoBusqueda->setEditable(false);
        label = new QLabel(Dialog_Busqueda);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 20, 121, 21));
        CB_TipoBusqueda_2 = new QComboBox(Dialog_Busqueda);
        CB_TipoBusqueda_2->setObjectName(QString::fromUtf8("CB_TipoBusqueda_2"));
        CB_TipoBusqueda_2->setGeometry(QRect(160, 120, 271, 29));
        CB_TipoBusqueda_2->setEditable(false);
        label_2 = new QLabel(Dialog_Busqueda);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 90, 71, 21));
        layoutWidget = new QWidget(Dialog_Busqueda);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 170, 551, 261));
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

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        LE_Email = new QLineEdit(layoutWidget);
        LE_Email->setObjectName(QString::fromUtf8("LE_Email"));

        gridLayout->addWidget(LE_Email, 2, 3, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        LE_Poblacion = new QLineEdit(layoutWidget);
        LE_Poblacion->setObjectName(QString::fromUtf8("LE_Poblacion"));

        gridLayout->addWidget(LE_Poblacion, 2, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        Btn_Buscar = new QPushButton(Dialog_Busqueda);
        Btn_Buscar->setObjectName(QString::fromUtf8("Btn_Buscar"));
        Btn_Buscar->setGeometry(QRect(240, 460, 98, 31));

        retranslateUi(Dialog_Busqueda);

        QMetaObject::connectSlotsByName(Dialog_Busqueda);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Busqueda)
    {
        Dialog_Busqueda->setWindowTitle(QApplication::translate("Dialog_Busqueda", "B\303\272squeda", 0, QApplication::UnicodeUTF8));
        CB_TipoBusqueda->clear();
        CB_TipoBusqueda->insertItems(0, QStringList()
         << QApplication::translate("Dialog_Busqueda", "Coincidencia exacta", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_Busqueda", "Subcadena", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("Dialog_Busqueda", "Tipo de b\303\272squeda", 0, QApplication::UnicodeUTF8));
        CB_TipoBusqueda_2->clear();
        CB_TipoBusqueda_2->insertItems(0, QStringList()
         << QApplication::translate("Dialog_Busqueda", "Y", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_Busqueda", "O", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Dialog_Busqueda", "Conector", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog_Busqueda", "Correo electr\303\263nico", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog_Busqueda", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog_Busqueda", "Tel\303\251fono", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog_Busqueda", "C\303\263digo postal", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Dialog_Busqueda", "Direcci\303\263n", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Dialog_Busqueda", "Poblaci\303\263n", 0, QApplication::UnicodeUTF8));
        Btn_Buscar->setText(QApplication::translate("Dialog_Busqueda", "Buscar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Busqueda: public Ui_Dialog_Busqueda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIO_BUSQUEDA_H
