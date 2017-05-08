/********************************************************************************
** Form generated from reading UI file 'rtimagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTIMAGEWINDOW_H
#define UI_RTIMAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rtImageWindow
{
public:
    QAction *actionZapisz;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *graphicsView_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QLabel *label;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *nearSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *farSpinBox;
    QLabel *label_4;
    QSlider *fovSlider;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuPlik;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *rtImageWindow)
    {
        if (rtImageWindow->objectName().isEmpty())
            rtImageWindow->setObjectName(QStringLiteral("rtImageWindow"));
        rtImageWindow->resize(1111, 600);
        actionZapisz = new QAction(rtImageWindow);
        actionZapisz->setObjectName(QStringLiteral("actionZapisz"));
        centralwidget = new QWidget(rtImageWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout_2->addWidget(graphicsView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        graphicsView_2 = new QGraphicsView(tab_2);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));

        verticalLayout_3->addWidget(graphicsView_2);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setChecked(false);

        verticalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(false);

        verticalLayout->addWidget(radioButton);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setChecked(true);

        verticalLayout->addWidget(radioButton_3);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(4);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(1);

        verticalLayout->addWidget(horizontalSlider);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        nearSpinBox = new QDoubleSpinBox(groupBox);
        nearSpinBox->setObjectName(QStringLiteral("nearSpinBox"));
        nearSpinBox->setMaximum(100000);
        nearSpinBox->setValue(1);

        horizontalLayout_2->addWidget(nearSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        farSpinBox = new QDoubleSpinBox(groupBox);
        farSpinBox->setObjectName(QStringLiteral("farSpinBox"));
        farSpinBox->setMaximum(100000);
        farSpinBox->setValue(100);

        horizontalLayout_3->addWidget(farSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        fovSlider = new QSlider(groupBox);
        fovSlider->setObjectName(QStringLiteral("fovSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fovSlider->sizePolicy().hasHeightForWidth());
        fovSlider->setSizePolicy(sizePolicy1);
        fovSlider->setMaximum(180);
        fovSlider->setValue(90);
        fovSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(fovSlider);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addWidget(groupBox);

        rtImageWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(rtImageWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1111, 25));
        menuPlik = new QMenu(menubar);
        menuPlik->setObjectName(QStringLiteral("menuPlik"));
        rtImageWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(rtImageWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        rtImageWindow->setStatusBar(statusbar);

        menubar->addAction(menuPlik->menuAction());
        menuPlik->addAction(actionZapisz);

        retranslateUi(rtImageWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(rtImageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *rtImageWindow)
    {
        rtImageWindow->setWindowTitle(QApplication::translate("rtImageWindow", "rt Renderer", Q_NULLPTR));
        actionZapisz->setText(QApplication::translate("rtImageWindow", "Zapisz", Q_NULLPTR));
        actionZapisz->setShortcut(QApplication::translate("rtImageWindow", "Ctrl+S", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("rtImageWindow", "Obraz", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("rtImageWindow", "G\305\202\304\231boko\305\233\304\207", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("rtImageWindow", "Parametry", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("rtImageWindow", "Perspektywa", Q_NULLPTR));
        radioButton->setText(QApplication::translate("rtImageWindow", "Ortograficzna", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("rtImageWindow", "Perspektywa Wielow\304\205tkowa", Q_NULLPTR));
        label->setText(QApplication::translate("rtImageWindow", "MSAA: 1x", Q_NULLPTR));
        label_2->setText(QApplication::translate("rtImageWindow", "Plan bliski", Q_NULLPTR));
        label_3->setText(QApplication::translate("rtImageWindow", "Plan daleki", Q_NULLPTR));
        label_4->setText(QApplication::translate("rtImageWindow", "FOV: 90", Q_NULLPTR));
        pushButton->setText(QApplication::translate("rtImageWindow", "Renderuj", Q_NULLPTR));
        menuPlik->setTitle(QApplication::translate("rtImageWindow", "Plik", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rtImageWindow: public Ui_rtImageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTIMAGEWINDOW_H
