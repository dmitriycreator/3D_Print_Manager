/****************************************************************************
** Meta object code from reading C++ file 'paramsform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../3D_Print_Manager/Params/paramsform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paramsform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParamsForm_t {
    QByteArrayData data[12];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParamsForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParamsForm_t qt_meta_stringdata_ParamsForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ParamsForm"
QT_MOC_LITERAL(1, 11, 13), // "deletePlastic"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "addPlastic"
QT_MOC_LITERAL(4, 37, 15), // "closeParamsForm"
QT_MOC_LITERAL(5, 53, 32), // "on_pushButton_AddPlastic_clicked"
QT_MOC_LITERAL(6, 86, 32), // "on_pushButton_delPlastic_clicked"
QT_MOC_LITERAL(7, 119, 27), // "on_lineEdit_Name_textEdited"
QT_MOC_LITERAL(8, 147, 4), // "arg1"
QT_MOC_LITERAL(9, 152, 27), // "on_lineEdit_Cost_textEdited"
QT_MOC_LITERAL(10, 180, 26), // "on_lineEdit_Del_textEdited"
QT_MOC_LITERAL(11, 207, 27) // "on_toolButton_close_clicked"

    },
    "ParamsForm\0deletePlastic\0\0addPlastic\0"
    "closeParamsForm\0on_pushButton_AddPlastic_clicked\0"
    "on_pushButton_delPlastic_clicked\0"
    "on_lineEdit_Name_textEdited\0arg1\0"
    "on_lineEdit_Cost_textEdited\0"
    "on_lineEdit_Del_textEdited\0"
    "on_toolButton_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParamsForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
       9,    1,   67,    2, 0x08 /* Private */,
      10,    1,   70,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void ParamsForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ParamsForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deletePlastic(); break;
        case 1: _t->addPlastic(); break;
        case 2: _t->closeParamsForm(); break;
        case 3: _t->on_pushButton_AddPlastic_clicked(); break;
        case 4: _t->on_pushButton_delPlastic_clicked(); break;
        case 5: _t->on_lineEdit_Name_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_Cost_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_Del_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_toolButton_close_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ParamsForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParamsForm::deletePlastic)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ParamsForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParamsForm::addPlastic)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ParamsForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParamsForm::closeParamsForm)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ParamsForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ParamsForm.data,
    qt_meta_data_ParamsForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ParamsForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParamsForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParamsForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ParamsForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ParamsForm::deletePlastic()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ParamsForm::addPlastic()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ParamsForm::closeParamsForm()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
