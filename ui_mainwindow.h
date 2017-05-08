/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *r1_2;
    QLabel *sphereLabel;
    QLabel *sphereXLabel;
    QDoubleSpinBox *sphereXSpinBox;
    QLabel *sphereYLabel;
    QDoubleSpinBox *sphereYSpinBox;
    QLabel *sphereZLabel;
    QDoubleSpinBox *sphereZSpinBox;
    QLabel *sphereRadiusLabel;
    QDoubleSpinBox *sphereRadiusSpinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *r1_3;
    QLabel *sphereLabel_2;
    QLabel *sphereXLabel_2;
    QDoubleSpinBox *sphereXSpinBox_2;
    QLabel *sphereYLabel_2;
    QDoubleSpinBox *sphereYSpinBox_2;
    QLabel *sphereZLabel_2;
    QDoubleSpinBox *sphereZSpinBox_2;
    QLabel *sphereRadiusLabel_2;
    QDoubleSpinBox *sphereRadiusSpinBox_2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *r1;
    QLabel *r1Label;
    QLabel *r1XLabel;
    QDoubleSpinBox *r1XSpinBox;
    QLabel *r1YLabel;
    QDoubleSpinBox *r1YSpinBox;
    QLabel *r1ZLabel;
    QDoubleSpinBox *r1ZSpinBox;
    QLabel *r1DirXLabel;
    QDoubleSpinBox *r1DirXSpinBox;
    QLabel *r1DirYLabel;
    QDoubleSpinBox *r1DirYSpinBox;
    QLabel *r1DirZLabel;
    QDoubleSpinBox *r1DirZSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *r2;
    QLabel *r2Label;
    QLabel *r2XLabel;
    QDoubleSpinBox *r2XSpinBox;
    QLabel *r2YLabel;
    QDoubleSpinBox *r2YSpinBox;
    QLabel *r2ZLabel;
    QDoubleSpinBox *r2ZSpinBox;
    QLabel *r2DirXLabel;
    QDoubleSpinBox *r2DirXSpinBox;
    QLabel *r2DirYLabel;
    QDoubleSpinBox *r2DirYSpinBox;
    QLabel *r2DirZLabel;
    QDoubleSpinBox *r2DirZSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *r2_2;
    QLabel *r2Label_2;
    QLabel *r2XLabel_2;
    QDoubleSpinBox *r2XSpinBox_2;
    QLabel *r2YLabel_2;
    QDoubleSpinBox *r2YSpinBox_2;
    QLabel *r2ZLabel_2;
    QDoubleSpinBox *r2ZSpinBox_2;
    QLabel *r2DirXLabel_2;
    QDoubleSpinBox *r2DirXSpinBox_2;
    QLabel *r2DirYLabel_2;
    QDoubleSpinBox *r2DirYSpinBox_2;
    QLabel *r2DirZLabel_2;
    QDoubleSpinBox *r2DirZSpinBox_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *calculateButton;
    QSpacerItem *horizontalSpacer_7;
    QTextEdit *textDisplay;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(689, 502);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        r1_2 = new QHBoxLayout();
        r1_2->setSpacing(6);
        r1_2->setObjectName(QStringLiteral("r1_2"));
        sphereLabel = new QLabel(centralWidget);
        sphereLabel->setObjectName(QStringLiteral("sphereLabel"));

        r1_2->addWidget(sphereLabel);

        sphereXLabel = new QLabel(centralWidget);
        sphereXLabel->setObjectName(QStringLiteral("sphereXLabel"));
        sphereXLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1_2->addWidget(sphereXLabel);

        sphereXSpinBox = new QDoubleSpinBox(centralWidget);
        sphereXSpinBox->setObjectName(QStringLiteral("sphereXSpinBox"));
        sphereXSpinBox->setMaximum(1000);
        sphereXSpinBox->setValue(0);

        r1_2->addWidget(sphereXSpinBox);

        sphereYLabel = new QLabel(centralWidget);
        sphereYLabel->setObjectName(QStringLiteral("sphereYLabel"));
        sphereYLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1_2->addWidget(sphereYLabel);

        sphereYSpinBox = new QDoubleSpinBox(centralWidget);
        sphereYSpinBox->setObjectName(QStringLiteral("sphereYSpinBox"));
        sphereYSpinBox->setMaximum(1000);
        sphereYSpinBox->setValue(0);

        r1_2->addWidget(sphereYSpinBox);

        sphereZLabel = new QLabel(centralWidget);
        sphereZLabel->setObjectName(QStringLiteral("sphereZLabel"));
        sphereZLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1_2->addWidget(sphereZLabel);

        sphereZSpinBox = new QDoubleSpinBox(centralWidget);
        sphereZSpinBox->setObjectName(QStringLiteral("sphereZSpinBox"));
        sphereZSpinBox->setMaximum(1000);
        sphereZSpinBox->setValue(0);

        r1_2->addWidget(sphereZSpinBox);

        sphereRadiusLabel = new QLabel(centralWidget);
        sphereRadiusLabel->setObjectName(QStringLiteral("sphereRadiusLabel"));
        sphereRadiusLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1_2->addWidget(sphereRadiusLabel);

        sphereRadiusSpinBox = new QDoubleSpinBox(centralWidget);
        sphereRadiusSpinBox->setObjectName(QStringLiteral("sphereRadiusSpinBox"));
        sphereRadiusSpinBox->setMaximum(1000);
        sphereRadiusSpinBox->setValue(10);

        r1_2->addWidget(sphereRadiusSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        r1_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(r1_2);

        r1_3 = new QHBoxLayout();
        r1_3->setSpacing(6);
        r1_3->setObjectName(QStringLiteral("r1_3"));
        sphereLabel_2 = new QLabel(centralWidget);
        sphereLabel_2->setObjectName(QStringLiteral("sphereLabel_2"));

        r1_3->addWidget(sphereLabel_2);

        sphereXLabel_2 = new QLabel(centralWidget);
        sphereXLabel_2->setObjectName(QStringLiteral("sphereXLabel_2"));
        sphereXLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1_3->addWidget(sphereXLabel_2);

        sphereXSpinBox_2 = new QDoubleSpinBox(centralWidget);
        sphereXSpinBox_2->setObjectName(QStringLiteral("sphereXSpinBox_2"));
        sphereXSpinBox_2->setMaximum(1000);
        sphereXSpinBox_2->setValue(0);

        r1_3->addWidget(sphereXSpinBox_2);

        sphereYLabel_2 = new QLabel(centralWidget);
        sphereYLabel_2->setObjectName(QStringLiteral("sphereYLabel_2"));
        sphereYLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1_3->addWidget(sphereYLabel_2);

        sphereYSpinBox_2 = new QDoubleSpinBox(centralWidget);
        sphereYSpinBox_2->setObjectName(QStringLiteral("sphereYSpinBox_2"));
        sphereYSpinBox_2->setMaximum(1000);
        sphereYSpinBox_2->setValue(1);

        r1_3->addWidget(sphereYSpinBox_2);

        sphereZLabel_2 = new QLabel(centralWidget);
        sphereZLabel_2->setObjectName(QStringLiteral("sphereZLabel_2"));
        sphereZLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1_3->addWidget(sphereZLabel_2);

        sphereZSpinBox_2 = new QDoubleSpinBox(centralWidget);
        sphereZSpinBox_2->setObjectName(QStringLiteral("sphereZSpinBox_2"));
        sphereZSpinBox_2->setMaximum(1000);
        sphereZSpinBox_2->setValue(1);

        r1_3->addWidget(sphereZSpinBox_2);

        sphereRadiusLabel_2 = new QLabel(centralWidget);
        sphereRadiusLabel_2->setObjectName(QStringLiteral("sphereRadiusLabel_2"));
        sphereRadiusLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1_3->addWidget(sphereRadiusLabel_2);

        sphereRadiusSpinBox_2 = new QDoubleSpinBox(centralWidget);
        sphereRadiusSpinBox_2->setObjectName(QStringLiteral("sphereRadiusSpinBox_2"));
        sphereRadiusSpinBox_2->setMaximum(1000);
        sphereRadiusSpinBox_2->setValue(0);

        r1_3->addWidget(sphereRadiusSpinBox_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        r1_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(r1_3);

        r1 = new QHBoxLayout();
        r1->setSpacing(6);
        r1->setObjectName(QStringLiteral("r1"));
        r1Label = new QLabel(centralWidget);
        r1Label->setObjectName(QStringLiteral("r1Label"));

        r1->addWidget(r1Label);

        r1XLabel = new QLabel(centralWidget);
        r1XLabel->setObjectName(QStringLiteral("r1XLabel"));
        r1XLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1->addWidget(r1XLabel);

        r1XSpinBox = new QDoubleSpinBox(centralWidget);
        r1XSpinBox->setObjectName(QStringLiteral("r1XSpinBox"));
        r1XSpinBox->setMaximum(1000);
        r1XSpinBox->setValue(0);

        r1->addWidget(r1XSpinBox);

        r1YLabel = new QLabel(centralWidget);
        r1YLabel->setObjectName(QStringLiteral("r1YLabel"));
        r1YLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1->addWidget(r1YLabel);

        r1YSpinBox = new QDoubleSpinBox(centralWidget);
        r1YSpinBox->setObjectName(QStringLiteral("r1YSpinBox"));
        r1YSpinBox->setMaximum(1000);
        r1YSpinBox->setValue(0);

        r1->addWidget(r1YSpinBox);

        r1ZLabel = new QLabel(centralWidget);
        r1ZLabel->setObjectName(QStringLiteral("r1ZLabel"));
        r1ZLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1->addWidget(r1ZLabel);

        r1ZSpinBox = new QDoubleSpinBox(centralWidget);
        r1ZSpinBox->setObjectName(QStringLiteral("r1ZSpinBox"));
        r1ZSpinBox->setMaximum(1000);
        r1ZSpinBox->setValue(-20);

        r1->addWidget(r1ZSpinBox);

        r1DirXLabel = new QLabel(centralWidget);
        r1DirXLabel->setObjectName(QStringLiteral("r1DirXLabel"));
        r1DirXLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1->addWidget(r1DirXLabel);

        r1DirXSpinBox = new QDoubleSpinBox(centralWidget);
        r1DirXSpinBox->setObjectName(QStringLiteral("r1DirXSpinBox"));
        r1DirXSpinBox->setMaximum(1000);
        r1DirXSpinBox->setValue(0);

        r1->addWidget(r1DirXSpinBox);

        r1DirYLabel = new QLabel(centralWidget);
        r1DirYLabel->setObjectName(QStringLiteral("r1DirYLabel"));
        r1DirYLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1->addWidget(r1DirYLabel);

        r1DirYSpinBox = new QDoubleSpinBox(centralWidget);
        r1DirYSpinBox->setObjectName(QStringLiteral("r1DirYSpinBox"));
        r1DirYSpinBox->setMaximum(1000);
        r1DirYSpinBox->setValue(0);

        r1->addWidget(r1DirYSpinBox);

        r1DirZLabel = new QLabel(centralWidget);
        r1DirZLabel->setObjectName(QStringLiteral("r1DirZLabel"));
        r1DirZLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r1->addWidget(r1DirZLabel);

        r1DirZSpinBox = new QDoubleSpinBox(centralWidget);
        r1DirZSpinBox->setObjectName(QStringLiteral("r1DirZSpinBox"));
        r1DirZSpinBox->setMaximum(1000);
        r1DirZSpinBox->setValue(1);

        r1->addWidget(r1DirZSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        r1->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(r1);

        r2 = new QHBoxLayout();
        r2->setSpacing(6);
        r2->setObjectName(QStringLiteral("r2"));
        r2Label = new QLabel(centralWidget);
        r2Label->setObjectName(QStringLiteral("r2Label"));

        r2->addWidget(r2Label);

        r2XLabel = new QLabel(centralWidget);
        r2XLabel->setObjectName(QStringLiteral("r2XLabel"));
        r2XLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2->addWidget(r2XLabel);

        r2XSpinBox = new QDoubleSpinBox(centralWidget);
        r2XSpinBox->setObjectName(QStringLiteral("r2XSpinBox"));
        r2XSpinBox->setMaximum(1000);
        r2XSpinBox->setValue(0);

        r2->addWidget(r2XSpinBox);

        r2YLabel = new QLabel(centralWidget);
        r2YLabel->setObjectName(QStringLiteral("r2YLabel"));
        r2YLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2->addWidget(r2YLabel);

        r2YSpinBox = new QDoubleSpinBox(centralWidget);
        r2YSpinBox->setObjectName(QStringLiteral("r2YSpinBox"));
        r2YSpinBox->setMaximum(1000);
        r2YSpinBox->setValue(0);

        r2->addWidget(r2YSpinBox);

        r2ZLabel = new QLabel(centralWidget);
        r2ZLabel->setObjectName(QStringLiteral("r2ZLabel"));
        r2ZLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2->addWidget(r2ZLabel);

        r2ZSpinBox = new QDoubleSpinBox(centralWidget);
        r2ZSpinBox->setObjectName(QStringLiteral("r2ZSpinBox"));
        r2ZSpinBox->setMaximum(1000);
        r2ZSpinBox->setValue(0);

        r2->addWidget(r2ZSpinBox);

        r2DirXLabel = new QLabel(centralWidget);
        r2DirXLabel->setObjectName(QStringLiteral("r2DirXLabel"));
        r2DirXLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2->addWidget(r2DirXLabel);

        r2DirXSpinBox = new QDoubleSpinBox(centralWidget);
        r2DirXSpinBox->setObjectName(QStringLiteral("r2DirXSpinBox"));
        r2DirXSpinBox->setMaximum(1000);
        r2DirXSpinBox->setValue(0);

        r2->addWidget(r2DirXSpinBox);

        r2DirYLabel = new QLabel(centralWidget);
        r2DirYLabel->setObjectName(QStringLiteral("r2DirYLabel"));
        r2DirYLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2->addWidget(r2DirYLabel);

        r2DirYSpinBox = new QDoubleSpinBox(centralWidget);
        r2DirYSpinBox->setObjectName(QStringLiteral("r2DirYSpinBox"));
        r2DirYSpinBox->setMaximum(1000);
        r2DirYSpinBox->setValue(1);

        r2->addWidget(r2DirYSpinBox);

        r2DirZLabel = new QLabel(centralWidget);
        r2DirZLabel->setObjectName(QStringLiteral("r2DirZLabel"));
        r2DirZLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2->addWidget(r2DirZLabel);

        r2DirZSpinBox = new QDoubleSpinBox(centralWidget);
        r2DirZSpinBox->setObjectName(QStringLiteral("r2DirZSpinBox"));
        r2DirZSpinBox->setMaximum(1000);
        r2DirZSpinBox->setValue(0);

        r2->addWidget(r2DirZSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        r2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(r2);

        r2_2 = new QHBoxLayout();
        r2_2->setSpacing(6);
        r2_2->setObjectName(QStringLiteral("r2_2"));
        r2Label_2 = new QLabel(centralWidget);
        r2Label_2->setObjectName(QStringLiteral("r2Label_2"));

        r2_2->addWidget(r2Label_2);

        r2XLabel_2 = new QLabel(centralWidget);
        r2XLabel_2->setObjectName(QStringLiteral("r2XLabel_2"));
        r2XLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2_2->addWidget(r2XLabel_2);

        r2XSpinBox_2 = new QDoubleSpinBox(centralWidget);
        r2XSpinBox_2->setObjectName(QStringLiteral("r2XSpinBox_2"));
        r2XSpinBox_2->setMaximum(1000);
        r2XSpinBox_2->setValue(10);

        r2_2->addWidget(r2XSpinBox_2);

        r2YLabel_2 = new QLabel(centralWidget);
        r2YLabel_2->setObjectName(QStringLiteral("r2YLabel_2"));
        r2YLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2_2->addWidget(r2YLabel_2);

        r2YSpinBox_2 = new QDoubleSpinBox(centralWidget);
        r2YSpinBox_2->setObjectName(QStringLiteral("r2YSpinBox_2"));
        r2YSpinBox_2->setMaximum(1000);
        r2YSpinBox_2->setValue(0);

        r2_2->addWidget(r2YSpinBox_2);

        r2ZLabel_2 = new QLabel(centralWidget);
        r2ZLabel_2->setObjectName(QStringLiteral("r2ZLabel_2"));
        r2ZLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2_2->addWidget(r2ZLabel_2);

        r2ZSpinBox_2 = new QDoubleSpinBox(centralWidget);
        r2ZSpinBox_2->setObjectName(QStringLiteral("r2ZSpinBox_2"));
        r2ZSpinBox_2->setMaximum(1000);
        r2ZSpinBox_2->setValue(-20);

        r2_2->addWidget(r2ZSpinBox_2);

        r2DirXLabel_2 = new QLabel(centralWidget);
        r2DirXLabel_2->setObjectName(QStringLiteral("r2DirXLabel_2"));
        r2DirXLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2_2->addWidget(r2DirXLabel_2);

        r2DirXSpinBox_2 = new QDoubleSpinBox(centralWidget);
        r2DirXSpinBox_2->setObjectName(QStringLiteral("r2DirXSpinBox_2"));
        r2DirXSpinBox_2->setMaximum(1000);
        r2DirXSpinBox_2->setValue(0);

        r2_2->addWidget(r2DirXSpinBox_2);

        r2DirYLabel_2 = new QLabel(centralWidget);
        r2DirYLabel_2->setObjectName(QStringLiteral("r2DirYLabel_2"));
        r2DirYLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2_2->addWidget(r2DirYLabel_2);

        r2DirYSpinBox_2 = new QDoubleSpinBox(centralWidget);
        r2DirYSpinBox_2->setObjectName(QStringLiteral("r2DirYSpinBox_2"));
        r2DirYSpinBox_2->setMaximum(1000);
        r2DirYSpinBox_2->setValue(0);

        r2_2->addWidget(r2DirYSpinBox_2);

        r2DirZLabel_2 = new QLabel(centralWidget);
        r2DirZLabel_2->setObjectName(QStringLiteral("r2DirZLabel_2"));
        r2DirZLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        r2_2->addWidget(r2DirZLabel_2);

        r2DirZSpinBox_2 = new QDoubleSpinBox(centralWidget);
        r2DirZSpinBox_2->setObjectName(QStringLiteral("r2DirZSpinBox_2"));
        r2DirZSpinBox_2->setMaximum(1000);
        r2DirZSpinBox_2->setValue(1);

        r2_2->addWidget(r2DirZSpinBox_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        r2_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(r2_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        calculateButton = new QPushButton(centralWidget);
        calculateButton->setObjectName(QStringLiteral("calculateButton"));

        horizontalLayout->addWidget(calculateButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout);

        textDisplay = new QTextEdit(centralWidget);
        textDisplay->setObjectName(QStringLiteral("textDisplay"));
        textDisplay->setUndoRedoEnabled(false);
        textDisplay->setReadOnly(true);

        verticalLayout->addWidget(textDisplay);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 689, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        sphereLabel->setText(QApplication::translate("MainWindow", "Sfera", Q_NULLPTR));
        sphereXLabel->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        sphereYLabel->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        sphereZLabel->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        sphereRadiusLabel->setText(QApplication::translate("MainWindow", "Promie\305\204", Q_NULLPTR));
        sphereLabel_2->setText(QApplication::translate("MainWindow", "P\305\202aszczyzna", Q_NULLPTR));
        sphereXLabel_2->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        sphereYLabel_2->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        sphereZLabel_2->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        sphereRadiusLabel_2->setText(QApplication::translate("MainWindow", "D", Q_NULLPTR));
        r1Label->setText(QApplication::translate("MainWindow", "R1", Q_NULLPTR));
        r1XLabel->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        r1YLabel->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        r1ZLabel->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        r1DirXLabel->setText(QApplication::translate("MainWindow", "Kierunek X", Q_NULLPTR));
        r1DirYLabel->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        r1DirZLabel->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        r2Label->setText(QApplication::translate("MainWindow", "R2", Q_NULLPTR));
        r2XLabel->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        r2YLabel->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        r2ZLabel->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        r2DirXLabel->setText(QApplication::translate("MainWindow", "Kierunek X", Q_NULLPTR));
        r2DirYLabel->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        r2DirZLabel->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        r2Label_2->setText(QApplication::translate("MainWindow", "R3", Q_NULLPTR));
        r2XLabel_2->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        r2YLabel_2->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        r2ZLabel_2->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        r2DirXLabel_2->setText(QApplication::translate("MainWindow", "Kierunek X", Q_NULLPTR));
        r2DirYLabel_2->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        r2DirZLabel_2->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        calculateButton->setText(QApplication::translate("MainWindow", "T\304\205pnij basem synu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rtMainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
