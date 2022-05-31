/****************************************************************************
** Meta object code from reading C++ file 'logform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Sport - V2/Ui/logform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogForm_t {
    const uint offsetsAndSize[24];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_LogForm_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_LogForm_t qt_meta_stringdata_LogForm = {
    {
QT_MOC_LITERAL(0, 7), // "LogForm"
QT_MOC_LITERAL(8, 17), // "on_CloseB_clicked"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 15), // "on_MinB_clicked"
QT_MOC_LITERAL(43, 16), // "on_MbrRb_clicked"
QT_MOC_LITERAL(60, 16), // "on_MgrRb_clicked"
QT_MOC_LITERAL(77, 16), // "on_SysRb_clicked"
QT_MOC_LITERAL(94, 18), // "on_MbrLogB_clicked"
QT_MOC_LITERAL(113, 21), // "on_SysMgrLogB_clicked"
QT_MOC_LITERAL(135, 18), // "on_MbrRegB_clicked"
QT_MOC_LITERAL(154, 20), // "on_IdT_returnPressed"
QT_MOC_LITERAL(175, 22) // "on_PswdT_returnPressed"

    },
    "LogForm\0on_CloseB_clicked\0\0on_MinB_clicked\0"
    "on_MbrRb_clicked\0on_MgrRb_clicked\0"
    "on_SysRb_clicked\0on_MbrLogB_clicked\0"
    "on_SysMgrLogB_clicked\0on_MbrRegB_clicked\0"
    "on_IdT_returnPressed\0on_PswdT_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

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

       0        // eod
};

void LogForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_CloseB_clicked(); break;
        case 1: _t->on_MinB_clicked(); break;
        case 2: _t->on_MbrRb_clicked(); break;
        case 3: _t->on_MgrRb_clicked(); break;
        case 4: _t->on_SysRb_clicked(); break;
        case 5: _t->on_MbrLogB_clicked(); break;
        case 6: _t->on_SysMgrLogB_clicked(); break;
        case 7: _t->on_MbrRegB_clicked(); break;
        case 8: _t->on_IdT_returnPressed(); break;
        case 9: _t->on_PswdT_returnPressed(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject LogForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LogForm.offsetsAndSize,
    qt_meta_data_LogForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_LogForm_t
, QtPrivate::TypeAndForceComplete<LogForm, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *LogForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LogForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
