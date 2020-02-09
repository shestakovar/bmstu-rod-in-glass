/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralwidget;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lightZ;
    QLabel *label;
    QLineEdit *lightY;
    QLineEdit *lightX;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *camZ;
    QLabel *label_7;
    QLineEdit *camY;
    QLineEdit *camX;
    QLabel *label_8;
    QGroupBox *groupBox_3;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *turnZ;
    QLabel *label_11;
    QLineEdit *turnY;
    QLineEdit *turnX;
    QLabel *label_12;
    QPushButton *pushButton;
    QGroupBox *groupBox_4;
    QLabel *label_13;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 10, 640, 640));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 651, 681));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(700, 20, 251, 111));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 50, 16, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 50, 16, 16));
        lightZ = new QLineEdit(groupBox);
        lightZ->setObjectName(QString::fromUtf8("lightZ"));
        lightZ->setGeometry(QRect(170, 70, 71, 24));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 181, 16));
        lightY = new QLineEdit(groupBox);
        lightY->setObjectName(QString::fromUtf8("lightY"));
        lightY->setGeometry(QRect(90, 70, 61, 24));
        lightX = new QLineEdit(groupBox);
        lightX->setObjectName(QString::fromUtf8("lightX"));
        lightX->setGeometry(QRect(10, 70, 61, 24));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 50, 16, 16));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(700, 150, 251, 111));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 50, 16, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 50, 16, 16));
        camZ = new QLineEdit(groupBox_2);
        camZ->setObjectName(QString::fromUtf8("camZ"));
        camZ->setGeometry(QRect(170, 70, 71, 24));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 30, 181, 16));
        camY = new QLineEdit(groupBox_2);
        camY->setObjectName(QString::fromUtf8("camY"));
        camY->setGeometry(QRect(90, 70, 61, 24));
        camX = new QLineEdit(groupBox_2);
        camX->setObjectName(QString::fromUtf8("camX"));
        camX->setGeometry(QRect(10, 70, 61, 24));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 50, 16, 16));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(700, 280, 251, 111));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 50, 16, 16));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 50, 16, 16));
        turnZ = new QLineEdit(groupBox_3);
        turnZ->setObjectName(QString::fromUtf8("turnZ"));
        turnZ->setGeometry(QRect(170, 70, 71, 24));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(100, 30, 61, 16));
        turnY = new QLineEdit(groupBox_3);
        turnY->setObjectName(QString::fromUtf8("turnY"));
        turnY->setGeometry(QRect(90, 70, 61, 24));
        turnX = new QLineEdit(groupBox_3);
        turnX->setObjectName(QString::fromUtf8("turnX"));
        turnX->setGeometry(QRect(10, 70, 61, 24));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 50, 16, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(740, 520, 141, 32));
        pushButton->setAutoDefault(false);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(700, 400, 251, 111));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 30, 241, 16));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 50, 113, 21));
        checkBox = new QCheckBox(groupBox_4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 80, 201, 20));
        checkBox->setChecked(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201\320\276\320\262\320\276\320\271 \320\277\321\200\320\276\320\265\320\272\321\202", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        lightZ->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260 \321\201\320\262\320\265\321\202\320\260", nullptr));
        lightY->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        lightX->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        camZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
        camY->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        camX->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        turnZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        turnY->setText(QCoreApplication::translate("MainWindow", "-30", nullptr));
        turnX->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 \320\277\321\200\320\265\320\273\320\276\320\274\320\273\320\265\320\275\320\270\321\217 \320\266\320\270\320\264\320\272\320\276\321\201\321\202\320\270", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "1.33", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\260\320\272\320\276\320\275\320\265\321\207\320\275\320\270\320\272-\321\210\320\260\321\200", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
