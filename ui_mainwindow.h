/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *wasd;
    QPushButton *arrows;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(187, 43);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 168, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wasd = new QPushButton(widget);
        wasd->setObjectName(QStringLiteral("wasd"));

        horizontalLayout->addWidget(wasd);

        arrows = new QPushButton(widget);
        arrows->setObjectName(QStringLiteral("arrows"));

        horizontalLayout->addWidget(arrows);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TTR Controls", 0));
#ifndef QT_NO_TOOLTIP
        wasd->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Click button, click on toon screen quickly, and wait for toon to jump.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        wasd->setText(QApplication::translate("MainWindow", "WASD", 0));
#ifndef QT_NO_TOOLTIP
        arrows->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Click button, click on toon screen quickly, and wait for toon to jump.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        arrows->setText(QApplication::translate("MainWindow", "Arrows", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
