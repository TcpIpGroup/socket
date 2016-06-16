/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QTextEdit *textInput;
    QPushButton *btnExit;
    QLabel *label_2;
    QLineEdit *editUnicastIp;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *editGroupIp;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *cbxSelect;
    QPushButton *btnClear;
    QPushButton *btnSend;
    QLineEdit *editUnicastPort;
    QLineEdit *editReceivePort;
    QListWidget *listWidgetShow;
    QCheckBox *checkBoxGroup;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(428, 545);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        textInput = new QTextEdit(centralWidget);
        textInput->setObjectName(QStringLiteral("textInput"));

        gridLayout->addWidget(textInput, 5, 0, 1, 5);

        btnExit = new QPushButton(centralWidget);
        btnExit->setObjectName(QStringLiteral("btnExit"));

        gridLayout->addWidget(btnExit, 7, 4, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        editUnicastIp = new QLineEdit(centralWidget);
        editUnicastIp->setObjectName(QStringLiteral("editUnicastIp"));
        editUnicastIp->setEnabled(false);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        editUnicastIp->setPalette(palette);
        editUnicastIp->setReadOnly(true);

        gridLayout->addWidget(editUnicastIp, 0, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        editGroupIp = new QLineEdit(centralWidget);
        editGroupIp->setObjectName(QStringLiteral("editGroupIp"));
        editGroupIp->setEnabled(false);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        editGroupIp->setPalette(palette1);
        editGroupIp->setReadOnly(true);

        gridLayout->addWidget(editGroupIp, 1, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QPalette palette2;
        QBrush brush2(QColor(85, 0, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_5->setPalette(palette2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 2);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_6->setPalette(palette3);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        cbxSelect = new QComboBox(centralWidget);
        cbxSelect->setObjectName(QStringLiteral("cbxSelect"));

        gridLayout->addWidget(cbxSelect, 6, 1, 1, 1);

        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        gridLayout->addWidget(btnClear, 6, 2, 1, 2);

        btnSend = new QPushButton(centralWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        gridLayout->addWidget(btnSend, 6, 4, 1, 1);

        editUnicastPort = new QLineEdit(centralWidget);
        editUnicastPort->setObjectName(QStringLiteral("editUnicastPort"));
        editUnicastPort->setEnabled(false);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        editUnicastPort->setPalette(palette4);

        gridLayout->addWidget(editUnicastPort, 0, 3, 1, 2);

        editReceivePort = new QLineEdit(centralWidget);
        editReceivePort->setObjectName(QStringLiteral("editReceivePort"));
        editReceivePort->setEnabled(false);

        gridLayout->addWidget(editReceivePort, 1, 3, 1, 2);

        listWidgetShow = new QListWidget(centralWidget);
        listWidgetShow->setObjectName(QStringLiteral("listWidgetShow"));

        gridLayout->addWidget(listWidgetShow, 3, 0, 1, 5);

        checkBoxGroup = new QCheckBox(centralWidget);
        checkBoxGroup->setObjectName(QStringLiteral("checkBoxGroup"));
        checkBoxGroup->setChecked(true);

        gridLayout->addWidget(checkBoxGroup, 7, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(btnExit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\253\257\345\217\243\345\217\267", 0));
        btnExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\257\271\346\226\271IP", 0));
        label_4->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\347\253\257\345\217\243\345\217\267", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\273\204\346\222\255\345\234\260\345\235\200", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\345\217\221\346\266\210\346\201\257", 0));
        label_6->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\344\277\241\346\201\257", 0));
        label_7->setText(QApplication::translate("MainWindow", "\347\247\201\350\201\212\345\257\271\350\261\241", 0));
        cbxSelect->clear();
        cbxSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251", 0)
        );
        cbxSelect->setCurrentText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251", 0));
        btnClear->setText(QApplication::translate("MainWindow", "\346\270\205\345\261\217", 0));
        btnSend->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        checkBoxGroup->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\347\276\244\350\201\212", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
