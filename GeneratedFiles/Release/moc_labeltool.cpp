/****************************************************************************
** Meta object code from reading C++ file 'labeltool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../labeltool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labeltool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LabelTool_t {
    QByteArrayData data[15];
    char stringdata[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LabelTool_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LabelTool_t qt_meta_stringdata_LabelTool = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 11),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 11),
QT_MOC_LITERAL(4, 35, 13),
QT_MOC_LITERAL(5, 49, 9),
QT_MOC_LITERAL(6, 59, 14),
QT_MOC_LITERAL(7, 74, 13),
QT_MOC_LITERAL(8, 88, 16),
QT_MOC_LITERAL(9, 105, 15),
QT_MOC_LITERAL(10, 121, 15),
QT_MOC_LITERAL(11, 137, 16),
QT_MOC_LITERAL(12, 154, 15),
QT_MOC_LITERAL(13, 170, 16),
QT_MOC_LITERAL(14, 187, 23)
    },
    "LabelTool\0openImgSlot\0\0openDirSlot\0"
    "openLabelSlot\0labelSlot\0clearLabelSlot\0"
    "saveLabelSlot\0getNextImageSlot\0"
    "rotateImageSlot\0imageZoomInSlot\0"
    "imageZoomOutSlot\0deleteImageSlot\0"
    "openLabelDirSlot\0getNextLabeledImageSlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabelTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a,
       3,    0,   80,    2, 0x0a,
       4,    0,   81,    2, 0x0a,
       5,    0,   82,    2, 0x0a,
       6,    0,   83,    2, 0x0a,
       7,    0,   84,    2, 0x0a,
       8,    0,   85,    2, 0x0a,
       9,    0,   86,    2, 0x0a,
      10,    0,   87,    2, 0x0a,
      11,    0,   88,    2, 0x0a,
      12,    0,   89,    2, 0x0a,
      13,    0,   90,    2, 0x0a,
      14,    0,   91,    2, 0x0a,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void LabelTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LabelTool *_t = static_cast<LabelTool *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->openImgSlot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->openDirSlot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->openLabelSlot(); break;
        case 3: _t->labelSlot(); break;
        case 4: _t->clearLabelSlot(); break;
        case 5: _t->saveLabelSlot(); break;
        case 6: { bool _r = _t->getNextImageSlot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->rotateImageSlot(); break;
        case 8: _t->imageZoomInSlot(); break;
        case 9: _t->imageZoomOutSlot(); break;
        case 10: _t->deleteImageSlot(); break;
        case 11: { bool _r = _t->openLabelDirSlot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->getNextLabeledImageSlot(); break;
        default: ;
        }
    }
}

const QMetaObject LabelTool::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LabelTool.data,
      qt_meta_data_LabelTool,  qt_static_metacall, 0, 0}
};


const QMetaObject *LabelTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabelTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LabelTool.stringdata))
        return static_cast<void*>(const_cast< LabelTool*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LabelTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
