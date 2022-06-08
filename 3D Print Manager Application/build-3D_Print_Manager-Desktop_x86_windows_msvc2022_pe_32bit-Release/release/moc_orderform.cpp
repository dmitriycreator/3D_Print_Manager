/****************************************************************************
** Meta object code from reading C++ file 'orderform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../3D_Print_Manager/Order/orderform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orderform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrderForm_t {
    QByteArrayData data[19];
    char stringdata0[372];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrderForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrderForm_t qt_meta_stringdata_OrderForm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "OrderForm"
QT_MOC_LITERAL(1, 10, 8), // "closeTab"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "addPrint"
QT_MOC_LITERAL(4, 29, 11), // "deletePrint"
QT_MOC_LITERAL(5, 41, 15), // "findCost_button"
QT_MOC_LITERAL(6, 57, 19), // "finishOrder_clicked"
QT_MOC_LITERAL(7, 77, 19), // "deleteOrder_clicked"
QT_MOC_LITERAL(8, 97, 27), // "on_toolButton_close_clicked"
QT_MOC_LITERAL(9, 125, 30), // "on_pushButton_addPrint_clicked"
QT_MOC_LITERAL(10, 156, 31), // "on_lineEdit_deleteID_textEdited"
QT_MOC_LITERAL(11, 188, 4), // "arg1"
QT_MOC_LITERAL(12, 193, 33), // "on_pushButton_deletePrint_cli..."
QT_MOC_LITERAL(13, 227, 22), // "chBox_defectiveChecked"
QT_MOC_LITERAL(14, 250, 9), // "isChecked"
QT_MOC_LITERAL(15, 260, 17), // "chBox_doneChecked"
QT_MOC_LITERAL(16, 278, 30), // "on_pushButton_findCost_clicked"
QT_MOC_LITERAL(17, 309, 28), // "on_pushButton_finish_clicked"
QT_MOC_LITERAL(18, 338, 33) // "on_pushButton_deleteOrder_cli..."

    },
    "OrderForm\0closeTab\0\0addPrint\0deletePrint\0"
    "findCost_button\0finishOrder_clicked\0"
    "deleteOrder_clicked\0on_toolButton_close_clicked\0"
    "on_pushButton_addPrint_clicked\0"
    "on_lineEdit_deleteID_textEdited\0arg1\0"
    "on_pushButton_deletePrint_clicked\0"
    "chBox_defectiveChecked\0isChecked\0"
    "chBox_doneChecked\0on_pushButton_findCost_clicked\0"
    "on_pushButton_finish_clicked\0"
    "on_pushButton_deleteOrder_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      15,    1,  104,    2, 0x08 /* Private */,
      16,    0,  107,    2, 0x08 /* Private */,
      17,    0,  108,    2, 0x08 /* Private */,
      18,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OrderForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OrderForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeTab(); break;
        case 1: _t->addPrint(); break;
        case 2: _t->deletePrint(); break;
        case 3: _t->findCost_button(); break;
        case 4: _t->finishOrder_clicked(); break;
        case 5: _t->deleteOrder_clicked(); break;
        case 6: _t->on_toolButton_close_clicked(); break;
        case 7: _t->on_pushButton_addPrint_clicked(); break;
        case 8: _t->on_lineEdit_deleteID_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_deletePrint_clicked(); break;
        case 10: _t->chBox_defectiveChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->chBox_doneChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_findCost_clicked(); break;
        case 13: _t->on_pushButton_finish_clicked(); break;
        case 14: _t->on_pushButton_deleteOrder_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OrderForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderForm::closeTab)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OrderForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderForm::addPrint)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OrderForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderForm::deletePrint)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (OrderForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderForm::findCost_button)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (OrderForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderForm::finishOrder_clicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (OrderForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderForm::deleteOrder_clicked)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OrderForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_OrderForm.data,
    qt_meta_data_OrderForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OrderForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OrderForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void OrderForm::closeTab()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void OrderForm::addPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void OrderForm::deletePrint()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void OrderForm::findCost_button()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void OrderForm::finishOrder_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void OrderForm::deleteOrder_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
