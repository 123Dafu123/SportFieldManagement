/****************************************************************************
** Meta object code from reading C++ file 'regform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Sport/regform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RegForm_t {
    const uint offsetsAndSize[20];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RegForm_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RegForm_t qt_meta_stringdata_RegForm = {
    {
QT_MOC_LITERAL(0, 7), // "RegForm"
QT_MOC_LITERAL(8, 17), // "on_CloseB_clicked"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 15), // "on_MinB_clicked"
QT_MOC_LITERAL(43, 14), // "on_Reg_clicked"
QT_MOC_LITERAL(58, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(76, 20), // "on_IdT_returnPressed"
QT_MOC_LITERAL(97, 22), // "on_PswdT_returnPressed"
QT_MOC_LITERAL(120, 22), // "on_NameT_returnPressed"
QT_MOC_LITERAL(143, 22) // "on_TeleT_returnPressed"

    },
    "RegForm\0on_CloseB_clicked\0\0on_MinB_clicked\0"
    "on_Reg_clicked\0on_Cancel_clicked\0"
    "on_IdT_returnPressed\0on_PswdT_returnPressed\0"
    "on_NameT_returnPressed\0on_TeleT_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
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

void RegForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RegForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_CloseB_clicked(); break;
        case 1: _t->on_MinB_clicked(); break;
        case 2: _t->on_Reg_clicked(); break;
        case 3: _t->on_Cancel_clicked(); break;
        case 4: _t->on_IdT_returnPressed(); break;
        case 5: _t->on_PswdT_returnPressed(); break;
        case 6: _t->on_NameT_returnPressed(); break;
        case 7: _t->on_TeleT_returnPressed(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject RegForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RegForm.offsetsAndSize,
    qt_meta_data_RegForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RegForm_t
, QtPrivate::TypeAndForceComplete<RegForm, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RegForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RegForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RegForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
