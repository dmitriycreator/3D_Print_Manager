/****************************************************************************
** Meta object code from reading C++ file 'adminform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Admin/adminform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminForm_t {
    QByteArrayData data[13];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminForm_t qt_meta_stringdata_AdminForm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AdminForm"
QT_MOC_LITERAL(1, 10, 27), // "on_pushButton_Users_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 28), // "on_pushButton_Income_clicked"
QT_MOC_LITERAL(4, 68, 28), // "on_pushButton_Params_clicked"
QT_MOC_LITERAL(5, 97, 7), // "addUser"
QT_MOC_LITERAL(6, 105, 10), // "deleteUser"
QT_MOC_LITERAL(7, 116, 13), // "findAllIncome"
QT_MOC_LITERAL(8, 130, 13), // "deletePlastic"
QT_MOC_LITERAL(9, 144, 10), // "addPlastic"
QT_MOC_LITERAL(10, 155, 15), // "closeIncomeForm"
QT_MOC_LITERAL(11, 171, 15), // "closeParamsForm"
QT_MOC_LITERAL(12, 187, 14) // "closeUsersForm"

    },
    "AdminForm\0on_pushButton_Users_clicked\0"
    "\0on_pushButton_Income_clicked\0"
    "on_pushButton_Params_clicked\0addUser\0"
    "deleteUser\0findAllIncome\0deletePlastic\0"
    "addPlastic\0closeIncomeForm\0closeParamsForm\0"
    "closeUsersForm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_Users_clicked(); break;
        case 1: _t->on_pushButton_Income_clicked(); break;
        case 2: _t->on_pushButton_Params_clicked(); break;
        case 3: _t->addUser(); break;
        case 4: _t->deleteUser(); break;
        case 5: _t->findAllIncome(); break;
        case 6: _t->deletePlastic(); break;
        case 7: _t->addPlastic(); break;
        case 8: _t->closeIncomeForm(); break;
        case 9: _t->closeParamsForm(); break;
        case 10: _t->closeUsersForm(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AdminForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AdminForm.data,
    qt_meta_data_AdminForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdminForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
