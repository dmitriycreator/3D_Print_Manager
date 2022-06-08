/****************************************************************************
** Meta object code from reading C++ file 'incomeform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../3D_Print_Manager/Income/incomeform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'incomeform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IncomeForm_t {
    QByteArrayData data[7];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IncomeForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IncomeForm_t qt_meta_stringdata_IncomeForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "IncomeForm"
QT_MOC_LITERAL(1, 11, 13), // "findAllIncome"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "closeIncomeForm"
QT_MOC_LITERAL(4, 42, 29), // "on_pushButton_refresh_clicked"
QT_MOC_LITERAL(5, 72, 31), // "on_pushButton_AllIncome_clicked"
QT_MOC_LITERAL(6, 104, 27) // "on_toolButton_close_clicked"

    },
    "IncomeForm\0findAllIncome\0\0closeIncomeForm\0"
    "on_pushButton_refresh_clicked\0"
    "on_pushButton_AllIncome_clicked\0"
    "on_toolButton_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IncomeForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IncomeForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IncomeForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->findAllIncome(); break;
        case 1: _t->closeIncomeForm(); break;
        case 2: _t->on_pushButton_refresh_clicked(); break;
        case 3: _t->on_pushButton_AllIncome_clicked(); break;
        case 4: _t->on_toolButton_close_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IncomeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IncomeForm::findAllIncome)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IncomeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IncomeForm::closeIncomeForm)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject IncomeForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_IncomeForm.data,
    qt_meta_data_IncomeForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IncomeForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IncomeForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IncomeForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IncomeForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void IncomeForm::findAllIncome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void IncomeForm::closeIncomeForm()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
