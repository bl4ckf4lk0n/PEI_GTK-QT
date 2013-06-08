/****************************************************************************
** Meta object code from reading C++ file 'Plantilla.h'
**
** Created: Sat Jun 8 20:01:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Plantilla/Plantilla.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Plantilla.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Plantilla[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      38,   10,   10,   10, 0x08,
      74,   10,   10,   10, 0x08,
     103,   10,   10,   10, 0x08,
     143,  137,   10,   10, 0x08,
     179,   10,   10,   10, 0x08,
     214,   10,   10,   10, 0x08,
     242,   10,   10,   10, 0x08,
     270,   10,   10,   10, 0x08,
     306,  300,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Plantilla[] = {
    "Plantilla\0\0on_actionAbrir_triggered()\0"
    "on_actionNuevo_registro_triggered()\0"
    "on_actionGuardar_triggered()\0"
    "on_actionGuardar_como_triggered()\0"
    "index\0on_tabWidget_tabCloseRequested(int)\0"
    "on_actionNuevo_archivo_triggered()\0"
    "on_actionBuscar_triggered()\0"
    "on_actionAcerca_triggered()\0"
    "on_actionExportar_triggered()\0event\0"
    "closeEvent(QCloseEvent*)\0"
};

void Plantilla::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Plantilla *_t = static_cast<Plantilla *>(_o);
        switch (_id) {
        case 0: _t->on_actionAbrir_triggered(); break;
        case 1: _t->on_actionNuevo_registro_triggered(); break;
        case 2: _t->on_actionGuardar_triggered(); break;
        case 3: _t->on_actionGuardar_como_triggered(); break;
        case 4: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_actionNuevo_archivo_triggered(); break;
        case 6: _t->on_actionBuscar_triggered(); break;
        case 7: _t->on_actionAcerca_triggered(); break;
        case 8: _t->on_actionExportar_triggered(); break;
        case 9: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Plantilla::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Plantilla::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Plantilla,
      qt_meta_data_Plantilla, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Plantilla::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Plantilla::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Plantilla::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Plantilla))
        return static_cast<void*>(const_cast< Plantilla*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Plantilla::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
