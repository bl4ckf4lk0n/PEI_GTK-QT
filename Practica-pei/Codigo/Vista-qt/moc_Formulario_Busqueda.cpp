/****************************************************************************
** Meta object code from reading C++ file 'Formulario_Busqueda.h'
**
** Created: Fri May 10 11:14:43 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Formulario_Busqueda/Formulario_Busqueda.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Formulario_Busqueda.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Formulario_Busqueda[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Formulario_Busqueda[] = {
    "Formulario_Busqueda\0\0on_Btn_Buscar_clicked()\0"
};

void Formulario_Busqueda::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Formulario_Busqueda *_t = static_cast<Formulario_Busqueda *>(_o);
        switch (_id) {
        case 0: _t->on_Btn_Buscar_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Formulario_Busqueda::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Formulario_Busqueda::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Formulario_Busqueda,
      qt_meta_data_Formulario_Busqueda, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Formulario_Busqueda::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Formulario_Busqueda::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Formulario_Busqueda::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Formulario_Busqueda))
        return static_cast<void*>(const_cast< Formulario_Busqueda*>(this));
    return QDialog::qt_metacast(_clname);
}

int Formulario_Busqueda::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
