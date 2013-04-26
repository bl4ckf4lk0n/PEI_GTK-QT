/********************************************************************************
** Form generated from reading UI file 'Plantilla.ui'
**
** Created: Fri Apr 26 11:09:59 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANTILLA_H
#define UI_PLANTILLA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_App_Main
{
public:
    QAction *actionNuevo_archivo;
    QAction *actionAbrir;
    QAction *actionGuardar;
    QAction *actionGuardar_como;
    QAction *actionBuscar;
    QAction *actionExportar;
    QAction *actionSalir;
    QAction *actionNuevo_registro;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuRegistrp;
    QMenu *menuAcerca_de;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *App_Main)
    {
        if (App_Main->objectName().isEmpty())
            App_Main->setObjectName(QString::fromUtf8("App_Main"));
        App_Main->resize(800, 600);
        actionNuevo_archivo = new QAction(App_Main);
        actionNuevo_archivo->setObjectName(QString::fromUtf8("actionNuevo_archivo"));
        actionAbrir = new QAction(App_Main);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        actionGuardar = new QAction(App_Main);
        actionGuardar->setObjectName(QString::fromUtf8("actionGuardar"));
        actionGuardar_como = new QAction(App_Main);
        actionGuardar_como->setObjectName(QString::fromUtf8("actionGuardar_como"));
        actionBuscar = new QAction(App_Main);
        actionBuscar->setObjectName(QString::fromUtf8("actionBuscar"));
        actionExportar = new QAction(App_Main);
        actionExportar->setObjectName(QString::fromUtf8("actionExportar"));
        actionSalir = new QAction(App_Main);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionNuevo_registro = new QAction(App_Main);
        actionNuevo_registro->setObjectName(QString::fromUtf8("actionNuevo_registro"));
        centralwidget = new QWidget(App_Main);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(8, 20, 781, 521));
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        App_Main->setCentralWidget(centralwidget);
        menubar = new QMenuBar(App_Main);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuRegistrp = new QMenu(menubar);
        menuRegistrp->setObjectName(QString::fromUtf8("menuRegistrp"));
        menuAcerca_de = new QMenu(menubar);
        menuAcerca_de->setObjectName(QString::fromUtf8("menuAcerca_de"));
        App_Main->setMenuBar(menubar);
        statusbar = new QStatusBar(App_Main);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        App_Main->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuRegistrp->menuAction());
        menubar->addAction(menuAcerca_de->menuAction());
        menuArchivo->addAction(actionNuevo_archivo);
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionGuardar_como);
        menuArchivo->addAction(actionBuscar);
        menuArchivo->addAction(actionExportar);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuRegistrp->addAction(actionNuevo_registro);

        retranslateUi(App_Main);
        QObject::connect(actionSalir, SIGNAL(triggered()), App_Main, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(App_Main);
    } // setupUi

    void retranslateUi(QMainWindow *App_Main)
    {
        App_Main->setWindowTitle(QApplication::translate("App_Main", "Registros", 0, QApplication::UnicodeUTF8));
        actionNuevo_archivo->setText(QApplication::translate("App_Main", "Nuevo archivo", 0, QApplication::UnicodeUTF8));
        actionAbrir->setText(QApplication::translate("App_Main", "Abrir", 0, QApplication::UnicodeUTF8));
        actionGuardar->setText(QApplication::translate("App_Main", "Guardar", 0, QApplication::UnicodeUTF8));
        actionGuardar_como->setText(QApplication::translate("App_Main", "Guardar como...", 0, QApplication::UnicodeUTF8));
        actionBuscar->setText(QApplication::translate("App_Main", "Buscar", 0, QApplication::UnicodeUTF8));
        actionExportar->setText(QApplication::translate("App_Main", "Exportar", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("App_Main", "Salir", 0, QApplication::UnicodeUTF8));
        actionNuevo_registro->setText(QApplication::translate("App_Main", "Nuevo registro", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("App_Main", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("App_Main", "Tab 2", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("App_Main", "Archivo", 0, QApplication::UnicodeUTF8));
        menuRegistrp->setTitle(QApplication::translate("App_Main", "Registro", 0, QApplication::UnicodeUTF8));
        menuAcerca_de->setTitle(QApplication::translate("App_Main", "Acerca de...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class App_Main: public Ui_App_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANTILLA_H
