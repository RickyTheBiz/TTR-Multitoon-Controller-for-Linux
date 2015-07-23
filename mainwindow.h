#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_wasd_clicked();

    void on_arrows_clicked();

    void keyPressEvent(QKeyEvent * e);

    void keyReleaseEvent(QKeyEvent* r);

private:
    Ui::MainWindow *ui;

    QString win1;
    QString win2;
};

#endif // MAINWINDOW_H
