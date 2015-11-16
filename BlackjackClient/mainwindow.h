#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void displayMsg(QString msg);
    void changePlaying(bool value);


private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonStand_clicked();

    void on_pushButtonHit_clicked();

private:
    Game game;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
