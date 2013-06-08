/********************************************************************************
** Form generated from reading UI file 'Acerca_de.ui'
**
** Created: Sat Jun 8 18:28:17 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACERCA_DE_H
#define UI_ACERCA_DE_H

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
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *LB_Autores;
    QLabel *label_2;
    QLabel *LB_Mejoras;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(7, 10, 381, 281));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        LB_Autores = new QLabel(widget);
        LB_Autores->setObjectName(QString::fromUtf8("LB_Autores"));

        gridLayout->addWidget(LB_Autores, 1, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        LB_Mejoras = new QLabel(widget);
        LB_Mejoras->setObjectName(QString::fromUtf8("LB_Mejoras"));

        gridLayout->addWidget(LB_Mejoras, 3, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Autores", 0, QApplication::UnicodeUTF8));
        LB_Autores->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Mejoras", 0, QApplication::UnicodeUTF8));
        LB_Mejoras->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACERCA_DE_H
