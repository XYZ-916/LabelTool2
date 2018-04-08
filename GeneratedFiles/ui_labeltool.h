/********************************************************************************
** Form generated from reading UI file 'labeltool.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELTOOL_H
#define UI_LABELTOOL_H

#include <MyLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabelToolClass
{
public:
    QAction *actionOpen;
    QAction *actionLabel;
    QAction *actionOpen_Dir;
    QAction *actionOpen_label;
    QAction *action_label_dir;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    MyLabel *label;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *lineEdit_x3;
    QLineEdit *lineEdit_x2;
    QLineEdit *lineEdit_x1;
    QLineEdit *lineEdit_x4;
    QLineEdit *lineEdit_y1;
    QLineEdit *lineEdit_y2;
    QLineEdit *lineEdit_y3;
    QLineEdit *lineEdit_y4;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_clear;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *lineEdit_numbers;
    QPushButton *pushButton_save;
    QPushButton *pushButton_rotate;
    QPushButton *pushButton_delete;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_larger;
    QPushButton *pushButton_smaller;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QLabel *label_dirPath;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLabel *label_imgNum;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QLabel *label_labelNum;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_14;
    QLabel *label_leftImgNum;
    QPushButton *pushButton_next;
    QPushButton *pushButton_next_labeled_image;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LabelToolClass)
    {
        if (LabelToolClass->objectName().isEmpty())
            LabelToolClass->setObjectName(QStringLiteral("LabelToolClass"));
        LabelToolClass->resize(1102, 731);
        actionOpen = new QAction(LabelToolClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionLabel = new QAction(LabelToolClass);
        actionLabel->setObjectName(QStringLiteral("actionLabel"));
        actionOpen_Dir = new QAction(LabelToolClass);
        actionOpen_Dir->setObjectName(QStringLiteral("actionOpen_Dir"));
        actionOpen_label = new QAction(LabelToolClass);
        actionOpen_label->setObjectName(QStringLiteral("actionOpen_label"));
        action_label_dir = new QAction(LabelToolClass);
        action_label_dir->setObjectName(QStringLiteral("action_label_dir"));
        centralWidget = new QWidget(LabelToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setStyleSheet(QStringLiteral("background-color:white;"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new MyLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(800, 0));
        label->setMaximumSize(QSize(800, 16777215));
        label->setFocusPolicy(Qt::StrongFocus);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);


        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 10, 10, 10);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        lineEdit_x3 = new QLineEdit(centralWidget);
        lineEdit_x3->setObjectName(QStringLiteral("lineEdit_x3"));

        gridLayout->addWidget(lineEdit_x3, 3, 1, 1, 1);

        lineEdit_x2 = new QLineEdit(centralWidget);
        lineEdit_x2->setObjectName(QStringLiteral("lineEdit_x2"));

        gridLayout->addWidget(lineEdit_x2, 2, 1, 1, 1);

        lineEdit_x1 = new QLineEdit(centralWidget);
        lineEdit_x1->setObjectName(QStringLiteral("lineEdit_x1"));

        gridLayout->addWidget(lineEdit_x1, 1, 1, 1, 1);

        lineEdit_x4 = new QLineEdit(centralWidget);
        lineEdit_x4->setObjectName(QStringLiteral("lineEdit_x4"));

        gridLayout->addWidget(lineEdit_x4, 4, 1, 1, 1);

        lineEdit_y1 = new QLineEdit(centralWidget);
        lineEdit_y1->setObjectName(QStringLiteral("lineEdit_y1"));

        gridLayout->addWidget(lineEdit_y1, 1, 2, 1, 1);

        lineEdit_y2 = new QLineEdit(centralWidget);
        lineEdit_y2->setObjectName(QStringLiteral("lineEdit_y2"));

        gridLayout->addWidget(lineEdit_y2, 2, 2, 1, 1);

        lineEdit_y3 = new QLineEdit(centralWidget);
        lineEdit_y3->setObjectName(QStringLiteral("lineEdit_y3"));

        gridLayout->addWidget(lineEdit_y3, 3, 2, 1, 1);

        lineEdit_y4 = new QLineEdit(centralWidget);
        lineEdit_y4->setObjectName(QStringLiteral("lineEdit_y4"));

        gridLayout->addWidget(lineEdit_y4, 4, 2, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        verticalLayout->addWidget(pushButton_clear);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        lineEdit_numbers = new QLineEdit(centralWidget);
        lineEdit_numbers->setObjectName(QStringLiteral("lineEdit_numbers"));

        horizontalLayout_4->addWidget(lineEdit_numbers);


        verticalLayout->addLayout(horizontalLayout_4);

        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        verticalLayout->addWidget(pushButton_save);

        pushButton_rotate = new QPushButton(centralWidget);
        pushButton_rotate->setObjectName(QStringLiteral("pushButton_rotate"));

        verticalLayout->addWidget(pushButton_rotate);

        pushButton_delete = new QPushButton(centralWidget);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        verticalLayout->addWidget(pushButton_delete);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton_larger = new QPushButton(centralWidget);
        pushButton_larger->setObjectName(QStringLiteral("pushButton_larger"));

        horizontalLayout_9->addWidget(pushButton_larger);

        pushButton_smaller = new QPushButton(centralWidget);
        pushButton_smaller->setObjectName(QStringLiteral("pushButton_smaller"));

        horizontalLayout_9->addWidget(pushButton_smaller);


        verticalLayout->addLayout(horizontalLayout_9);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        label_dirPath = new QLabel(centralWidget);
        label_dirPath->setObjectName(QStringLiteral("label_dirPath"));
        label_dirPath->setMaximumSize(QSize(300, 16777215));
        label_dirPath->setWordWrap(true);

        horizontalLayout_6->addWidget(label_dirPath);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        label_imgNum = new QLabel(centralWidget);
        label_imgNum->setObjectName(QStringLiteral("label_imgNum"));

        horizontalLayout_5->addWidget(label_imgNum);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_7->addWidget(label_12);

        label_labelNum = new QLabel(centralWidget);
        label_labelNum->setObjectName(QStringLiteral("label_labelNum"));

        horizontalLayout_7->addWidget(label_labelNum);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_8->addWidget(label_14);

        label_leftImgNum = new QLabel(centralWidget);
        label_leftImgNum->setObjectName(QStringLiteral("label_leftImgNum"));

        horizontalLayout_8->addWidget(label_leftImgNum);


        verticalLayout->addLayout(horizontalLayout_8);

        pushButton_next = new QPushButton(centralWidget);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));

        verticalLayout->addWidget(pushButton_next);

        pushButton_next_labeled_image = new QPushButton(centralWidget);
        pushButton_next_labeled_image->setObjectName(QStringLiteral("pushButton_next_labeled_image"));

        verticalLayout->addWidget(pushButton_next_labeled_image);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        LabelToolClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LabelToolClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1102, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        LabelToolClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LabelToolClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LabelToolClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LabelToolClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LabelToolClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionOpen_Dir);
        menu->addAction(actionOpen_label);
        menu_2->addAction(action_label_dir);

        retranslateUi(LabelToolClass);

        QMetaObject::connectSlotsByName(LabelToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *LabelToolClass)
    {
        LabelToolClass->setWindowTitle(QApplication::translate("LabelToolClass", "LabelTool", 0));
        actionOpen->setText(QApplication::translate("LabelToolClass", "open", 0));
        actionLabel->setText(QApplication::translate("LabelToolClass", "label", 0));
        actionOpen_Dir->setText(QApplication::translate("LabelToolClass", "open Dir", 0));
        actionOpen_label->setText(QApplication::translate("LabelToolClass", "open label", 0));
        action_label_dir->setText(QApplication::translate("LabelToolClass", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", 0));
        label->setText(QString());
        label_4->setText(QApplication::translate("LabelToolClass", "\347\202\2712", 0));
        label_5->setText(QApplication::translate("LabelToolClass", "\347\202\2713", 0));
        label_2->setText(QApplication::translate("LabelToolClass", "\346\240\207\346\263\250\357\274\232", 0));
        label_3->setText(QApplication::translate("LabelToolClass", "\347\202\2711\357\274\232", 0));
        label_6->setText(QApplication::translate("LabelToolClass", "\347\202\2714", 0));
        label_7->setText(QApplication::translate("LabelToolClass", "\346\250\252\345\235\220\346\240\207", 0));
        label_8->setText(QApplication::translate("LabelToolClass", "\347\272\265\345\235\220\346\240\207", 0));
        pushButton_clear->setText(QApplication::translate("LabelToolClass", "\351\207\215\347\275\256\346\240\207\350\256\260", 0));
        label_9->setText(QApplication::translate("LabelToolClass", "\350\257\273\346\225\260\357\274\232", 0));
        pushButton_save->setText(QApplication::translate("LabelToolClass", "\344\277\235\345\255\230(Enter)", 0));
        pushButton_save->setShortcut(QApplication::translate("LabelToolClass", "Return", 0));
        pushButton_rotate->setText(QApplication::translate("LabelToolClass", "\346\227\213\350\275\25490\345\272\246(Ctrl+C)", 0));
        pushButton_delete->setText(QApplication::translate("LabelToolClass", "\345\210\240\351\231\244", 0));
        pushButton_larger->setText(QApplication::translate("LabelToolClass", "\346\224\276\345\244\247", 0));
        pushButton_smaller->setText(QApplication::translate("LabelToolClass", "\347\274\251\345\260\217", 0));
        label_13->setText(QApplication::translate("LabelToolClass", "\345\275\223\345\211\215\346\226\207\344\273\266\345\244\271\344\270\272\357\274\232", 0));
        label_dirPath->setText(QString());
        label_11->setText(QApplication::translate("LabelToolClass", "\346\226\207\344\273\266\345\244\271\344\270\255\345\233\276\347\211\207\346\200\273\346\225\260\357\274\232", 0));
        label_imgNum->setText(QString());
        label_12->setText(QApplication::translate("LabelToolClass", "\345\267\262\346\240\207\350\256\260\346\225\260\347\233\256\357\274\232", 0));
        label_labelNum->setText(QString());
        label_14->setText(QApplication::translate("LabelToolClass", "\345\211\251\344\275\231\345\233\276\345\203\217\346\225\260\347\233\256\357\274\232", 0));
        label_leftImgNum->setText(QString());
        pushButton_next->setText(QApplication::translate("LabelToolClass", "\344\270\213\344\270\200\345\274\240(Ctrl+X)", 0));
        pushButton_next->setShortcut(QApplication::translate("LabelToolClass", "Ctrl+X", 0));
        pushButton_next_labeled_image->setText(QApplication::translate("LabelToolClass", "\346\237\245\347\234\213\344\270\213\344\270\200\345\274\240\345\267\262\346\240\207\346\263\250\345\233\276\347\211\207\357\274\210Ctrl+Z\357\274\211", 0));
        pushButton_next_labeled_image->setShortcut(QApplication::translate("LabelToolClass", "Ctrl+Z", 0));
        menu->setTitle(QApplication::translate("LabelToolClass", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("LabelToolClass", "\345\267\262\346\240\207\346\263\250\346\225\260\346\215\256\346\237\245\347\234\213", 0));
    } // retranslateUi

};

namespace Ui {
    class LabelToolClass: public Ui_LabelToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELTOOL_H
