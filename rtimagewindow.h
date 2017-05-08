#ifndef RTIMAGEWINDOW_H
#define RTIMAGEWINDOW_H

#include "rtfilm.h"

#include <QMainWindow>

// Main window. All UI elements are covered in this file. Most of it are created by Qt Creator.

namespace Ui {
class rtImageWindow;
}

class rtImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit rtImageWindow(QWidget *parent = 0);
    ~rtImageWindow();
    void update(rtFilm &film);

private slots:
    void on_actionZapisz_triggered();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_fovSlider_sliderMoved(int position);

    void on_radioButton_toggled(bool checked);

private:
    Ui::rtImageWindow *ui;
    QImage image;
    QImage depth;
};

#endif // RTIMAGEWINDOW_H
