/****************************************************************************
** Meta object code from reading C++ file 'Formulario_Registro.h'
**
** Created: Fri Apr 26 12:24:28 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Formulario_Registro/Formulario_Registro.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Formulario_Registro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Formulario_Registro[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      47,   20,   20,   20, 0x08,
      70,   20,   20,   20, 0x08,
      99,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Formulario_Registro[] = {
    "Formulario_Registro\0\0on_Btn_Adelante_clicked()\0"
    "on_Btn_Atras_clicked()\0"
    "on_Btn_ModRegistro_clicked()\0"
    "on_Btn_BorrarRegistro_clicked()\0"
};

void Formulario_Registro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Formulario_Registro *_t = static_cast<Formulario_Registro *>(_o);
        switch (_id) {
        case 0: _t->on_Btn_Adelante_clicked(); break;
        case 1: _t->on_Btn_Atras_clicked(); break;
        case 2: _t->on_Btn_ModRegistro_clicked(); break;
        case 3: _t->on_Btn_BorrarRegistro_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Formulario_Registro::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Formulario_Registro::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Formulario_Registro,
      qt_meta_data_Formulario_Registro, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Formulario_Registro::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Formulario_Registro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Formulario_Registro::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Formulario_Registro))
        return static_cast<void*>(const_cast< Formulario_Registro*>(this));
    return QWidget::qt_metacast(_clname);
}

int Formulario_Registro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
