/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 21 17:06:16 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <MapWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    MapWidget *mapArea;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *seedPoints_txt;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *maxIterations_txt;
    QLabel *label_3;
    QLineEdit *seed_txt;
    QPushButton *generate_btn;
    QCheckBox *showPoints_chk;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(425, 415);
        mapArea = new MapWidget(Form);
        mapArea->setObjectName(QString::fromUtf8("mapArea"));
        mapArea->setGeometry(QRect(9, 9, 407, 231));
        mapArea->setMinimumSize(QSize(0, 138));
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 250, 401, 123));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        seedPoints_txt = new QLineEdit(layoutWidget);
        seedPoints_txt->setObjectName(QString::fromUtf8("seedPoints_txt"));

        gridLayout->addWidget(seedPoints_txt, 2, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        maxIterations_txt = new QLineEdit(layoutWidget);
        maxIterations_txt->setObjectName(QString::fromUtf8("maxIterations_txt"));

        gridLayout->addWidget(maxIterations_txt, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        seed_txt = new QLineEdit(layoutWidget);
        seed_txt->setObjectName(QString::fromUtf8("seed_txt"));
        seed_txt->setReadOnly(false);

        gridLayout->addWidget(seed_txt, 0, 1, 1, 1);

        generate_btn = new QPushButton(layoutWidget);
        generate_btn->setObjectName(QString::fromUtf8("generate_btn"));

        gridLayout->addWidget(generate_btn, 0, 3, 1, 1);

        showPoints_chk = new QCheckBox(layoutWidget);
        showPoints_chk->setObjectName(QString::fromUtf8("showPoints_chk"));

        gridLayout->addWidget(showPoints_chk, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        QWidget::setTabOrder(seed_txt, generate_btn);
        QWidget::setTabOrder(generate_btn, maxIterations_txt);
        QWidget::setTabOrder(maxIterations_txt, seedPoints_txt);

        retranslateUi(Form);
        QObject::connect(generate_btn, SIGNAL(clicked()), Form, SLOT(generate()));
        QObject::connect(showPoints_chk, SIGNAL(stateChanged(int)), Form, SLOT(generate()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        seedPoints_txt->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Seed", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "Number of iterations", 0, QApplication::UnicodeUTF8));
        maxIterations_txt->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "Number of iterations", 0, QApplication::UnicodeUTF8));
        seed_txt->setText(QApplication::translate("Form", "2", 0, QApplication::UnicodeUTF8));
        generate_btn->setText(QApplication::translate("Form", "Generate", 0, QApplication::UnicodeUTF8));
        showPoints_chk->setText(QApplication::translate("Form", "Show points", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
