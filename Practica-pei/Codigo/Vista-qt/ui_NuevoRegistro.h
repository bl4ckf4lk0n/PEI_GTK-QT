/********************************************************************************
** Form generated from reading UI file 'NuevoRegistro.ui'
**
** Created: Wed May 8 15:10:58 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVOREGISTRO_H
#define UI_NUEVOREGISTRO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_NuevoRegistro
{
public:
    QGroupBox *GB_NuevoRegistro;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *LE_CodPostalNew;
    QLineEdit *LE_TelefonoNew;
    QLabel *label_6;
    QLineEdit *LE_DireccionNew;
    QLineEdit *LE_NombreNew;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *LE_EmailNew;
    QLabel *label_2;
    QLineEdit *LE_PoblacionNew;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *Btn_GuardarRegistro;

    void setupUi(QDialog *Dialog_NuevoRegistro)
    {
        if (Dialog_NuevoRegistro->objectName().isEmpty())
            Dialog_NuevoRegistro->setObjectName(QString::fromUtf8("Dialog_NuevoRegistro"));
        Dialog_NuevoRegistro->resize(667, 433);
        GB_NuevoRegistro = new QGroupBox(Dialog_NuevoRegistro);
        GB_NuevoRegistro->setObjectName(QString::fromUtf8("GB_NuevoRegistro"));
        GB_NuevoRegistro->setGeometry(QRect(70, 40, 551, 321));
        layoutWidget = new QWidget(GB_NuevoRegistro);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 50, 551, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        LE_CodPostalNew = new QLineEdit(layoutWidget);
        LE_CodPostalNew->setObjectName(QString::fromUtf8("LE_CodPostalNew"));

        gridLayout->addWidget(LE_CodPostalNew, 0, 3, 1, 1);

        LE_TelefonoNew = new QLineEdit(layoutWidget);
        LE_TelefonoNew->setObjectName(QString::fromUtf8("LE_TelefonoNew"));

        gridLayout->addWidget(LE_TelefonoNew, 1, 3, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        LE_DireccionNew = new QLineEdit(layoutWidget);
        LE_DireccionNew->setObjectName(QString::fromUtf8("LE_DireccionNew"));

        gridLayout->addWidget(LE_DireccionNew, 1, 1, 1, 1);

        LE_NombreNew = new QLineEdit(layoutWidget);
        LE_NombreNew->setObjectName(QString::fromUtf8("LE_NombreNew"));

        gridLayout->addWidget(LE_NombreNew, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        LE_EmailNew = new QLineEdit(layoutWidget);
        LE_EmailNew->setObjectName(QString::fromUtf8("LE_EmailNew"));

        gridLayout->addWidget(LE_EmailNew, 2, 3, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        LE_PoblacionNew = new QLineEdit(layoutWidget);
        LE_PoblacionNew->setObjectName(QString::fromUtf8("LE_PoblacionNew"));

        gridLayout->addWidget(LE_PoblacionNew, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        Btn_GuardarRegistro = new QPushButton(Dialog_NuevoRegistro);
        Btn_GuardarRegistro->setObjectName(QString::fromUtf8("Btn_GuardarRegistro"));
        Btn_GuardarRegistro->setGeometry(QRect(270, 370, 121, 27));

        retranslateUi(Dialog_NuevoRegistro);

        QMetaObject::connectSlotsByName(Dialog_NuevoRegistro);
    } // setupUi

    void retranslateUi(QDialog *Dialog_NuevoRegistro)
    {
        Dialog_NuevoRegistro->setWindowTitle(QApplication::translate("Dialog_NuevoRegistro", "Dialog", 0, QApplication::UnicodeUTF8));
        GB_NuevoRegistro->setTitle(QApplication::translate("Dialog_NuevoRegistro", "Nuevo registro", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog_NuevoRegistro", "Correo electr\303\263nico", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog_NuevoRegistro", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog_NuevoRegistro", "Tel\303\251fono", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog_NuevoRegistro", "C\303\263digo postal", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog_NuevoRegistro", "Direcci\303\263n", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog_NuevoRegistro", "Poblaci\303\263n", 0, QApplication::UnicodeUTF8));
        Btn_GuardarRegistro->setText(QApplication::translate("Dialog_NuevoRegistro", "Guardar registro", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_NuevoRegistro: public Ui_Dialog_NuevoRegistro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVOREGISTRO_H
