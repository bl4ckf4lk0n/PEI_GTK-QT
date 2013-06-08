/****************************************************************************
** Meta object code from reading C++ file 'NuevoRegistro.h'
**
** Created: Fri Jun 7 21:31:55 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "NuevoRegistro/NuevoRegistro.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NuevoRegistro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NuevoRegistro[] = {

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
      15,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NuevoRegistro[] = {
    "NuevoRegistro\0\0on_Btn_GuardarRegistro_clicked()\0"
};

void NuevoRegistro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NuevoRegistro *_t = static_cast<NuevoRegistro *>(_o);
        switch (_id) {
        case 0: _t->on_Btn_GuardarRegistro_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NuevoRegistro::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NuevoRegistro::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NuevoRegistro,
      qt_meta_data_NuevoRegistro, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NuevoRegistro::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NuevoRegistro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NuevoRegistro::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NuevoRegistro))
        return static_cast<void*>(const_cast< NuevoRegistro*>(this));
    return QDialog::qt_metacast(_clname);
}

int NuevoRegistro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
