/****************************************************************************
** Meta object code from reading C++ file 'basecontents.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LAB_WORK_4/basecontents.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basecontents.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseContents_t {
    QByteArrayData data[13];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseContents_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseContents_t qt_meta_stringdata_BaseContents = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BaseContents"
QT_MOC_LITERAL(1, 13, 7), // "setData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 2), // "uN"
QT_MOC_LITERAL(4, 25, 2), // "uP"
QT_MOC_LITERAL(5, 28, 9), // "establish"
QT_MOC_LITERAL(6, 38, 6), // "cypher"
QT_MOC_LITERAL(7, 45, 3), // "key"
QT_MOC_LITERAL(8, 49, 11), // "writeToFile"
QT_MOC_LITERAL(9, 61, 18), // "on_btnFind_clicked"
QT_MOC_LITERAL(10, 80, 24), // "on_btnChangePass_clicked"
QT_MOC_LITERAL(11, 105, 21), // "on_btnAddUser_clicked"
QT_MOC_LITERAL(12, 127, 24) // "on_btnChangeUser_clicked"

    },
    "BaseContents\0setData\0\0uN\0uP\0establish\0"
    "cypher\0key\0writeToFile\0on_btnFind_clicked\0"
    "on_btnChangePass_clicked\0on_btnAddUser_clicked\0"
    "on_btnChangeUser_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseContents[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x08 /* Private */,
       5,    0,   59,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,
      11,    0,   66,    2, 0x08 /* Private */,
      12,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BaseContents::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaseContents *_t = static_cast<BaseContents *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->establish(); break;
        case 2: _t->cypher((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->writeToFile(); break;
        case 4: _t->on_btnFind_clicked(); break;
        case 5: _t->on_btnChangePass_clicked(); break;
        case 6: _t->on_btnAddUser_clicked(); break;
        case 7: _t->on_btnChangeUser_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BaseContents::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BaseContents.data,
      qt_meta_data_BaseContents,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BaseContents::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseContents::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseContents.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BaseContents::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
