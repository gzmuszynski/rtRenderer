#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class rtRayWindow;
}

class rtRayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit rtRayWindow(QWidget *parent = 0);
    ~rtRayWindow();

private slots:
    void on_calculateButton_clicked();

private:
    Ui::rtRayWindow *ui;
};

#endif // MAINWINDOW_H
